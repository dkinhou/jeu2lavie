#pragma once 
#include "grille.hpp"
#include "graphique.hpp"

class jeux {
  private:
    grille g;
    graphique gui;

  public:
    jeux(int largeur, int hauteur)
        : g(largeur, hauteur), gui(largeur, hauteur) {}

    void run() {
        while (gui.isOpen()) {
            gui.processEvents();
            gui.drawGrille(g);
            // Logique de mise à jour de la grille à ajouter ici
        }
    }
};