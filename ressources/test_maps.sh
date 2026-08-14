#!/usr/bin/env bash

set -u

BINARY="${1:-./cub3D}"
MAPS_DIR="${2:-maps/generated}"
TIMEOUT_SECONDS="${TIMEOUT_SECONDS:-2}"
DATE="$(date +%Y%m%d_%H%M%S)"
RESULTS_DIR="test_results/maps_$DATE"
SUMMARY="$RESULTS_DIR/summary.txt"

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
RESET='\033[0m'

TOTAL=0
PASSED=0
FAILED=0

mkdir -p "$RESULTS_DIR/valid" "$RESULTS_DIR/invalid"

print_pass()
{
	printf "${GREEN}[OK]${RESET}   %s\n" "$1"
	PASSED=$((PASSED + 1))
}

print_fail()
{
	printf "${RED}[FAIL]${RESET} %s\n" "$1"
	FAILED=$((FAILED + 1))
}

check_requirements()
{
	if ! command -v timeout >/dev/null 2>&1; then
		echo "Erreur : la commande 'timeout' est introuvable."
		exit 1
	fi

	if [ ! -d "$MAPS_DIR/valid" ] || [ ! -d "$MAPS_DIR/invalid" ]; then
		echo "Erreur : dossiers introuvables :"
		echo "  $MAPS_DIR/valid"
		echo "  $MAPS_DIR/invalid"
		exit 1
	fi

	if [ ! -x "$BINARY" ]; then
		echo "Compilation de cub3D..."
		make || exit 1
	fi

	if [ ! -x "$BINARY" ]; then
		echo "Erreur : exécutable introuvable : $BINARY"
		exit 1
	fi
}

first_non_empty_line()
{
	sed -n '/[^[:space:]]/{s/\r$//;p;q;}' "$1"
}

contains_error_header()
{
	grep -Fxq "Error" "$1"
}

run_program()
{
	local map="$1"
	local log="$2"

	if [ -n "${DISPLAY:-}" ]; then
		timeout --signal=TERM --kill-after=1 \
			"${TIMEOUT_SECONDS}s" "$BINARY" "$map" >"$log" 2>&1
		return $?
	fi

	if command -v xvfb-run >/dev/null 2>&1; then
		timeout --signal=TERM --kill-after=1 \
			"${TIMEOUT_SECONDS}s" xvfb-run -a \
			"$BINARY" "$map" >"$log" 2>&1
		return $?
	fi

	timeout --signal=TERM --kill-after=1 \
		"${TIMEOUT_SECONDS}s" "$BINARY" "$map" >"$log" 2>&1
	return $?
}

test_valid_map()
{
	local map="$1"
	local name
	local log
	local status

	name="$(basename "$map")"
	log="$RESULTS_DIR/valid/$name.log"
	TOTAL=$((TOTAL + 1))

	run_program "$map" "$log"
	status=$?

	# 124 signifie que cub3D est resté ouvert jusqu'au timeout.
	if { [ "$status" -eq 0 ] || [ "$status" -eq 124 ]; } \
		&& ! contains_error_header "$log"; then
		print_pass "VALIDE   $name"
		printf "PASS | VALID   | %s | exit=%d\n" \
			"$name" "$status" >>"$SUMMARY"
	else
		print_fail "VALIDE   $name (exit=$status)"
		printf "FAIL | VALID   | %s | exit=%d | output=%s\n" \
			"$name" "$status" "$(tr '\n' ' ' <"$log")" >>"$SUMMARY"
	fi
}

test_invalid_map()
{
	local map="$1"
	local name
	local log
	local status
	local first_line
	local non_empty_lines

	name="$(basename "$map")"
	log="$RESULTS_DIR/invalid/$name.log"
	TOTAL=$((TOTAL + 1))

	run_program "$map" "$log"
	status=$?

	first_line="$(first_non_empty_line "$log")"
	non_empty_lines="$(grep -c '[^[:space:]]' "$log" || true)"

	# Une map invalide doit :
	# - quitter avec un code différent de 0 ;
	# - ne pas rester ouverte jusqu'au timeout ;
	# - afficher "Error" sur la première ligne ;
	# - afficher ensuite un message explicite.
	if [ "$status" -ne 0 ] \
		&& [ "$status" -ne 124 ] \
		&& [ "$first_line" = "Error" ] \
		&& [ "$non_empty_lines" -ge 2 ]; then
		print_pass "INVALIDE $name"
		printf "PASS | INVALID | %s | exit=%d\n" \
			"$name" "$status" >>"$SUMMARY"
	else
		print_fail "INVALIDE $name (exit=$status)"
		printf "FAIL | INVALID | %s | exit=%d | output=%s\n" \
			"$name" "$status" "$(tr '\n' ' ' <"$log")" >>"$SUMMARY"
	fi
}

check_requirements

{
	echo "Tests cub3D"
	echo "Date : $(date)"
	echo "Binaire : $BINARY"
	echo "Maps : $MAPS_DIR"
	echo "Timeout : ${TIMEOUT_SECONDS}s"
	echo
} >"$SUMMARY"

echo
echo "=== MAPS VALIDES ==="

while IFS= read -r map
do
	test_valid_map "$map"
done < <(find "$MAPS_DIR/valid" -maxdepth 1 -type f | sort)

echo
echo "=== MAPS INVALIDES ==="

while IFS= read -r map
do
	test_invalid_map "$map"
done < <(find "$MAPS_DIR/invalid" -maxdepth 1 -type f | sort)

{
	echo
	echo "Total   : $TOTAL"
	echo "Réussis : $PASSED"
	echo "Échoués : $FAILED"
} >>"$SUMMARY"

echo
echo "=============================="
echo "Total   : $TOTAL"
printf "${GREEN}Réussis : %d${RESET}\n" "$PASSED"

if [ "$FAILED" -eq 0 ]; then
	printf "${GREEN}Échoués : 0${RESET}\n"
	echo "Tous les tests sont réussis."
else
	printf "${RED}Échoués : %d${RESET}\n" "$FAILED"
	echo
	echo "Consulte les logs dans : $RESULTS_DIR"
fi

echo "Résumé : $SUMMARY"

if [ "$FAILED" -ne 0 ]; then
	exit 1
fi

exit 0
