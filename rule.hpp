#pragma once

#include <string>
#include <vector>
#include "grille.hpp"

class rule {
  public:
    virtual void appliquerRegle(grille& g) = 0;
    virtual ~rule() {}
};

class baserule : public rule {
    public:
        grille appliquerRegle(grille& g) override {
            // Implémentation de la règle de base du Jeu de la Vie
            grille nouvelleGrille = g; // Crée une copie de la grille actuelle
    
            for (int y = 0; y < g.getHauteur(); ++y) {
                for (int x = 0; x < g.getLargeur(); ++x) {
                    cellules* cell = g.getCellule(x, y);
                    int voisinsVivants = compterVoisinsVivants(g, x, y);
    
                    if (cell->getetat()) {
                        // Règles pour une cellule vivante
                        if (voisinsVivants < 2 || voisinsVivants > 3) {
                            nouvelleGrille.setCellule(x, y, std::make_unique<celluleMorte>());
                        }
                    } else {
                        // Règles pour une cellule morte
                        if (voisinsVivants == 3) {
                            nouvelleGrille.setCellule(x, y, std::make_unique<celluleVivante>());
                        }
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
                    if (voisin.getetat()){
                        count++;
                    }
                }
            }
            return count;
        }
};