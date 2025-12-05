# jeu2lavie
Notre jeu de la  vie présente un ensemble de fonctionnalités qui se base sur le fonctionnement initial.

## Règle basique
Dans notre jeu de le vie les règles appliquées sont simple pour qu'une cellule vivante soit vivante il fait qu'est possède seulement 2 ou 3 voisin vivant. Tandis qu'une cellule morte à besoin d'être entourer d'exactement 3 cellules vivantes pour devenir vivante.  

## Mode de fonctionnement
Nous disposons de 3 mode de fonctionnement: Le mode console, le mode graphique, le mode test unitaire.

### Mode console 
Dans ce mode on va demander à l'utilisateur de renseingner le non de son fichier d'entrer et lui demander le nombre d'itération qu'il souhaite éffectuer. Le programme va ensuite s'occuper de creer le dossier de sortie en fonction du fichier d'entré ou il enregistre toutes les générations.

### Mode graphique
Dans ce mode on receuille juste le nom du fichier d'entré au début et on ouvre une fenêtre qui s'occupe d'afficher les différentes générations de la grille.

#### Intératcion avec l'affichage graphique

| Touche du clavier (à maintenir appuyée) | Objectif                     |
|-----------------------------------------|------------------------------|
| B                                       | Ajouter un blinker           |
| G                                       | Ajouter un glider            |
| S                                       | Ajouter un vaisseau spacial  |
| V                                       | Ajouter un obstacle vivant   |
| M                                       | Ajouter un obstacle mort     |
| A                                       | Ajouter une cellule vivante  |
| D                                       | Ajouter une cellule morte    |
| Espace                                  | Pause                        |

### Mode test unitaire 

Pour ce mode on prend en entré un fichier d'entré et le fichier attendu. Ensuite on demande le nombre de génarations correpondant au fichier attendu. On retourne donc si le résultat obtenu à la suite des générations sur le fichier d'entré sont en accord avec le fichier attendu.  







