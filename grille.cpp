#include "grille.hpp"

// Implémentation du constructeur personnalisé
grille::grille(int h, int l) : largeur(l), hauteur(h) {
    cellulesGrille.resize(h);
    for (auto &row : cellulesGrille) {
        row.resize(l);
    }
}

// Implémentation de la méthode setcellule pour définir une cellule à une position donnée
void grille::setcellule(int x, int y, std::unique_ptr<cellules> c) {
    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        cellulesGrille[y][x] = std::move(c);
    }
}

// Implémentation de la méthode getCellule pour obtenir une cellule à une position donnée
cellules* grille::getCellule(int x, int y) const {
    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
        return cellulesGrille[y][x].get();
    }
    return nullptr;
}

// Implémentation de la méthode getLargeur pour obtenir la largeur de la grille
int grille::getLargeur() const { return largeur; }

// Implémentation de la méthode getHauteur pour obtenir la hauteur de la grille
int grille::getHauteur() const { return hauteur; }

