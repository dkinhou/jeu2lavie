#pragma once

#include <string>
#include <vector>
#include <memory>
#include "grille.hpp"

class rule {
    public:
        virtual grille appliquerRegle(grille& g) = 0;
        virtual ~rule() {}
};

class baserule : public rule {
    public:

        grille appliquerRegle(grille& g) override {
            // Implémentation de la règle de base du Jeu de la Vie
            
            grille nouvelleGrille(g.getHauteur(), g.getLargeur()); // Crée une nouvelle grille vide
    
            for (int y = 0; y < g.getHauteur(); ++y) {
                for (int x = 0; x < g.getLargeur(); ++x) {
                    cellules* cell = g.getCellule(x, y);
                    int voisinsVivants = compterVoisinsVivants(g, x, y);

                    bool currentAlive = (cell && cell->getetat());
                    bool nextAlive = false;
                    if (currentAlive) {
                        // survive with 2 or 3 neighbors
                        if (voisinsVivants == 2 || voisinsVivants == 3) {
                            nextAlive = true;
                        }
                    } else {
                        // dead cell becomes alive with exactly 3 neighbors
                        if (voisinsVivants == 3) {
                            nextAlive = true;
                        }
                    }
                    if (nextAlive) {
                        nouvelleGrille.setcellule(x, y, std::make_unique<celluleVivante>());
                    } else {
                        nouvelleGrille.setcellule(x, y, std::make_unique<celluleMorte>());
                    }
                }
            }
    
            return nouvelleGrille;
        }
    
    
        int compterVoisinsVivants(const grille& g, int x, int y) {
            int count = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même
                    cellules* voisin = g.getCellule(x + dx, y + dy);
                    if (voisin && voisin->getetat()){
                        count++;
                    }
                }
            }
            return count;
        }
};