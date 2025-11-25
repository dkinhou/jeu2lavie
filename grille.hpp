#pragma once 

#include "cellules.hpp"
#include <vector>
#include <memory> 

class grille {
    private:
        int largeur;
        int hauteur;
        std::vector<std::vector<std::unique_ptr<cellules>>> cellulesGrille;
    
    public:
        grille(int l, int h) : largeur(l), hauteur(h), cellulesGrille(h, std::vector<std::unique_ptr<cellules>>(l, nullptr)) {}
    
        void setCellule(int x, int y, std::unique_ptr<cellules> cellule) {
            if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
                cellulesGrille[y][x] = std::move(cellule);
            }
        }
    
        cellules* getCellule(int x, int y) const {
            if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
                return cellulesGrille[y][x];
            }
            return nullptr;
        }
    
        int getLargeur() const { return largeur; }
        int getHauteur() const { return hauteur; }

};