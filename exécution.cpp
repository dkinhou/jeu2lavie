#include "jeux.hpp"


int main() {
    baserule regle;
    jeux game;
    std::unique_ptr<grille> gptr = game.setgrille();
    if(!gptr){
        return 1;
    }
    grille guse = std::move(*gptr);
    grille gnext;
    for (int generation = 0; generation < 10; ++generation) {
        gnext = regle.appliquerRegle(guse);
        guse = std::move(gnext);
        game.saveGrille(guse, generation);
    }
    return 0;
}