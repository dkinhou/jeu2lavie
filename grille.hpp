 #pragma once

#include "cellules.hpp"
#include <vector>//Pour utiliser des vecteurs
#include <memory>//Pour utiliser des pointeurs intelligents

using namespace std;

// Définition de la classe grille
class grille {
    private:
        int largeur;//Nombre de colonnes
        int hauteur;//Nombre de lignes
        vector<vector<unique_ptr<cellules>>> cellulesGrille;//Matrice de pointeurs intelligents vers des cellules
    
    public:

        grille(){}//Constructeur par défaut
        grille(int h, int l);//Constructeur avec paramètres
        void setcellule(int x, int y, std::unique_ptr<cellules> c);//Méthode pour définir une cellule à une position donnée
        cellules* getCellule(int x, int y) const;//Méthode pour obtenir une cellule à une position donnée
        int getLargeur() const;//Méthode pour obtenir la largeur de la grille
        int getHauteur() const;//Méthode pour obtenir la hauteur de la grille

};