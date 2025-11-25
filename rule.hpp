#pragma once

#include <string>
#include <vector>
#include "grille.hpp"

class rule {
  public:
    virtual void appliquerRegle(grille& g) = 0;
    virtual ~rule() {}
};

class baserule{
    public:
        void appliquerRegle(grille& g) {
            // Implémentation de la règle de base du Jeu de la Vie
            grille nouvelleGrille = g; // Crée une copie de la grille actuelle
    
            for (int y = 0; y < g.getHauteur(); ++y) {
                for (int x = 0; x < g.getLargeur(); ++x) {
                    cellules* cell = g.getCellule(x, y);
                    int voisinsVivants = compterVoisinsVivants(g, x, y);
    
                    if (cell && cell->estVivante()) {
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
    
            g = std::move(nouvelleGrille); // Met à jour la grille avec la nouvelle génération
        }
    
    private:
        int compterVoisinsVivants(const grille& g, int x, int y) {
            int count = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même
                    cellules* voisin = g.getCellule(x + dx, y + dy);
                    if (voisin && voisin->estVivante()) {
                        count++;
                    }
                }
            }
            return count;
        }
};