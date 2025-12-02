#include "rule.hpp"

//Implémentation de la méthode appliquerRegle pour la règle de base du Jeu de la Vie
grille baserule::appliquerRegle(grille& g) {
            // Implémentation de la règle de base du Jeu de la Vie
            
            grille nouvelleGrille(g.getHauteur(), g.getLargeur()); // Crée une nouvelle grille vide
            // Parcourir chaque cellule de la grille
            for (int y = 0; y < g.getHauteur(); ++y) {
                for (int x = 0; x < g.getLargeur(); ++x) {
                    cellules* cell = g.getCellule(x, y);
                    int voisinsVivants = compterVoisinsVivants(g, x, y);
                    bool currentAlive = (cell && cell->getetat());
                    bool nextAlive = false;
                    if (cell && (cell->tochar() == 'X' || cell->tochar() == 'Y')) {
                        // Garder les obstacles inchangés
                        if (cell->tochar() == 'X') {
                            nouvelleGrille.setcellule(x, y, make_unique<celluleObstaclemorte>());
                        } else {
                            nouvelleGrille.setcellule(x, y, make_unique<celluleObstaclevivante>());
                        }
                        continue;
                    }
                    if (currentAlive) {
                        // survivre avexc 2 ou 3 voisins
                        if (voisinsVivants == 2 || voisinsVivants == 3) {
                            nextAlive = true;
                        }
                    } else {
                        // cellule morte devient vivante avec exactement 3 voisins
                        if (voisinsVivants == 3) {
                            nextAlive = true;
                        }
                    }
                    
                    // Mettre à jour la cellule dans la nouvelle grille
                    if (nextAlive) {
                        nouvelleGrille.setcellule(x, y, make_unique<celluleVivante>());
                    } else {
                        nouvelleGrille.setcellule(x, y, make_unique<celluleMorte>());
                    }
                }
            }
    
            return nouvelleGrille;
}


//Implémentation de la méthode compterVoisinsVivants avec conditions de bordure toroïdales
  int baserule::compterVoisinsVivants(const grille& g, int x, int y) {
            int count = 0;
            // Parcourir les 8 voisins
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même
                    int voisin_x = (x + dx + g.getLargeur()) % g.getLargeur();// Equations suivant x pour bordure toroïdale
                    int voisin_y = (y + dy + g.getHauteur()) % g.getHauteur();// Equations suivant y pour bordure toroïdale
                    cellules* voisin = g.getCellule(voisin_x, voisin_y);
                    if (voisin && voisin->getetat()){
                        count++;
                    }
                }
            }
            return count;
        }


