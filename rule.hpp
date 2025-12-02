#pragma once

#include <string>
#include <vector>
#include <memory>
#include "grille.hpp"

using namespace std;

class rule {
    public:
        virtual grille appliquerRegle(grille& g) = 0;// Méthode virtuelle pour appliquer la règle à la grille g et retourner la nouvelle grille 
        virtual int compterVoisinsVivants(const grille& g, int x, int y) = 0;// Méthode virtuelle pour compter les voisins vivants d'une cellule à la position (x, y) dans la grille g
        virtual ~rule() {}// Destructeur virtuel
};

class baserule : public rule {
    public:

        grille appliquerRegle(grille& g) override;// Méthode reféfinie pour appliquer la règle de base du Jeu de la Vie à la grille g
        int compterVoisinsVivants(const grille& g, int x, int y) override;// Méthode reféfinie pour le comptage des voisins vivants avec conditions de bordure toroïdales
};