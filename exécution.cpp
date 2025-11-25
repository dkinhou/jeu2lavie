#include "jeux.hpp"

int main() {
    baserule regle;
    jeux game;
    grille g = game.setgrille();
    grille guse = g;
    grille gnext;
    for (int generation = 0; generation < 10; ++generation) {
        gnext = regle.appliquerRegle(guse);
        guse = gnext;
        game.saveGrille(generation);
    }
    return 0;
}