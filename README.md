*This project has been created as part of the 42 curriculum by sohollar and rhorace.*

# English
 --*French below*-- \
## Project description:

This project consists of creating a mini-game that gives the illusion of 3D using the raycasting method. It relies on the provided MinilibX graphics library.

The bonuses implemented are:
- Camera rotation using the mouse
- Minimap system
- Collision detection with walls
- Doors that can be opened and closed.

## Instructions:
To run the programme in its mandatory version:
- type "make"
- launch the programme with ": ./cub3D maps/mandatory.cub"

To run the programme in its bonus version:
- type "make bonus"
- launch the programme with ": ./cub3D maps/bonus.cub"

The maps can be modified but must meet the following validity criteria:
- enclosed
- containing at least one player represented by a cardinal direction (N, S, E, W)
- .cub extension
- lines describing the textures and floor and ceiling colours at the beginning
- no spaces within the map itself

### Arguments:
The programme takes a map as an argument, i.e. the path to a "*.cub" file.

### Outputs:
The programme opens a new window and only outputs potential error messages to the terminal.

## Resources:

### Peer-to-peer:
- for debugging
- to come up with ways of implementing the bonuses

### Websites:
Understanding raycasting:
- [https://lodev.org/cgtutor/raycasting.html](https://lodev.org/cgtutor/raycasting.html)
- [https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a](https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a)

Using MLX to fill an image with pixels rather than displaying textures directly: [https://harm-smits.github.io/42docs/libs/minilibx/getting\_started.html](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

Understanding the reading of an XPM image: [https://fr.wikipedia.org/wiki/X\_PixMap](https://fr.wikipedia.org/wiki/X_PixMap)

Drawing straight lines and moving along them: [https://www.desmos.com/calculator/o2b8mnfigk?lang=fr](https://www.desmos.com/calculator/o2b8mnfigk?lang=fr)

### AI:
- To gain a deeper understanding of certain elements that the other web sources alone did not make sufficiently clear
- For persistent bugs

## Programme description:

### Initialisation:
The programme is divided into three main parts:
- parsing: this part
    - checks that the map provided as an argument is valid
    - loads the textures and colours
    - stores the map as an array
    - initialises structures, the main ones being:
        - a game structure, which itself contains
        - a player structure storing their position and direction
        - a structure containing the components required for the graphics library and the final image
        - the textures
        - the map
    - other small utility structures (coordinates, wall hit by a ray, door, ...)

- displaying an image
    - Filling the background with the colours provided in the map
    - raycasting:
    - casting one ray for each pixel across the width of the final image
    - finding the first wall hit by each ray
    - determining the distance between the wall and the player
    - projecting this distance onto the player's viewing plane to correct the "fish-eye" effect; otherwise, the edges of a straight wall would appear smaller than its centre.
    - determining which column of pixels to sample from the texture, as well as each relevant pixel in that column, according to the calculated wall height
    - placing the identified pixels at the corresponding address in the final image, at the x-coordinate corresponding to the ray and centred vertically
    - displaying the final image

- event handling, with one hook for each:
    - WASD for movement
    - the arrow keys to rotate the camera
    - the mouse to rotate the camera
    - ESC to close the window properly
    - clicking the close button to close the window properly

# Français

## Description du projet :
Ce projet consiste à créer un minijeu donnant l'illusion de la 3D grâce à la méthode du raycasting. Il s'appuie sur la librairie graphique MinilibX fournie.
Les bonus traités sont :
- Rotation de la caméra avec la souris
- Système de minimap
- Gestion des collisions avec les murs
- Portes pouvant ouvrir et fermer.

## Instructions :
Pour exécuter le programme dans sa version obligatoire :
- taper "make"
- lancer le programme avec ": ./cub3D maps/mandatory.cub

Pour exécuter le programme dans sa version avec bonus :
- taper "make bonus"
- lancer le programme avec ": ./cub3D maps/bonus.cub

Les cartes sont modifiables mais doivent respecter les critères de validité :
- fermées
- avec au minimum un joueur représenté par un point cardinal (N, S, E, O)
- extension .cub
- lignes décrivant les textures et couleurs du sol et du plafond au début
- pas d'espaces dans la carte en elle-même

### Arguments :
Le programme prend en argument une carte, soit le chemin vers un fichier "*.cub"

### Outputs :
Le programme ouvre une nouvelle fenêtre, et n'écrit dans le terminal que des messages d'erreur éventuels.

## Ressources :

### Peer to peer :
- pour débugguer
- pour imaginer des façons de réaliser les bonus

### Sites web :
Comprendre le raycasting :
- [https://lodev.org/cgtutor/raycasting.html](https://lodev.org/cgtutor/raycasting.html)
- [https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a](https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a)

Utiliser la MLX pour remplir une image de pixels et ne pas afficher directement les textures : [https://harm-smits.github.io/42docs/libs/minilibx/getting\_started.html](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

Comprendre la lecture d’une image XPM : [https://fr.wikipedia.org/wiki/X\_PixMap](https://fr.wikipedia.org/wiki/X_PixMap)

tracer des droites et se deplacer dessus : [https://www.desmos.com/calculator/o2b8mnfigk?lang=fr](https://www.desmos.com/calculator/o2b8mnfigk?lang=fr)

### IA :
- Pour approfondir certains éléments que les autres sources web n'ont pas permis de comprendre à elles-seules
- Pour les bugs récalcitrants

## Description du programme :

### Initialisation :
Le programme s'articule en trois grandes parties :
- le parsing : cette partie
    - vérifie que la carte prise en argument est valide
    - charge les textures et les couleurs
    - stocke la carte sous forme de tableau
    - initialise des structures, dont les principales :
        - une structure pour le jeu, contenant elle-même
            - une structure joueur stockant sa position et direction
            - une structure contenant les éléments de fonctionnement de la librairie graphique et l'image finale
            - les textures
            - la carte
        - d'autres petites structures utilitaires (coordonnées, mur tapé par un rayon, porte, ...)
- l'affichage d'une image
    - Remplissage du fond par les couleurs fournies dans la carte
    - raycasting :
        - émission d'un rayon par pixel de largeur de l'image finale
        - repérage du premier mur tapé par chaque rayon
        - détermination de la distance mur-joueur
        - projection de cette distance sur le plan du regard du joueur pour corriger le "fish-eye", sinon les bors d'un mur droit apparaîtraient plus petits que son centre.
        - détermination de la colonne de pixel de la texture à prélever, et de chaque pixel pertinent dans cette colonne, selon la taille du mur calculée
        - placement des pixels identifiées dans l'adresse de l'image finale, à l'abcisse correspondant au rayon et centrés verticalement
        - affichage de l'image finale
- la gestion des événements, un hook our chacun :
        - WASD pour les déplacements
        - les flèches pour tourner la caméra
        - la souris pour tourner la caméra
        - ESC pour fermer la fenêtre proprement
        - cliquer sur la croix pour fermer la fenêtre proprement
