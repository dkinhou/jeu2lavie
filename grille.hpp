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

        grille(){}
        grille(int h, int l) : largeur(l), hauteur(h) {
            cellulesGrille.resize(h);
            for (auto &row : cellulesGrille) {
                row.resize(l);
            }
        }
    
        void setcellule(int x, int y, std::unique_ptr<cellules> c) {
            if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
                cellulesGrille[y][x] = std::move(c);
            }

        }
    
        cellules* getCellule(int x, int y) const {
            if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
                return cellulesGrille[y][x].get();
            }
            return nullptr;
        }
    
        int getLargeur() const { return largeur; }
        int getHauteur() const { return hauteur; }

};