*This project has been created as part of the 42 curriculum by sohollar.*

## Description :
Ce projet consiste a créer un jeu vidéo en 2D, dans lequel un personnage doit ramasser des collectibles et se rendre à la sortie en le moins de coups possible.

## Instructions :
executer le programme ainsi :
- ./so_long Maps/[choisir une map]
- utiliser les flèches directionnelles pour déplacer le personnage
- Utiliser la touche ECHAP ou cliquer sur la croix pour quitter le jeu.

## Ressources :

### Beaucoup de peer to peer :
- pour le Makefile, pour comprendre comment utiliser la minilib (les fonctions utiles, leurs arguments précis, comment bien free, ...)
- GIMP pour créer mes textures

### Sites web :
Quelques ressources en ligne pour dégrossir :
https://harm-smits.github.io/42docs/libs/minilibx
https://harm-smits.github.io/42docs/libs/minilibx/events.html

### IA :
Pas eu besoin sur ce projet

## Description du programme :
Le programme commence par vérifier que la map entrée en argument est bien conforme aux exigences du projet, finissable, et de taille raisonnable.
Puis le programme démarre la minilibX et alloue l'espace nécessaire aux textures, les affiche, et définit les règles du jeu grâce aux fonctions gérant les "hooks".
