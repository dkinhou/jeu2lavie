#include "jeux.hpp"
#include "graphique.hpp"

void printgraph()
{
    baserule regle;
    jeux game;
      std::unique_ptr<grille> gptr = game.setgrille();
    grille guse = std::move(*gptr);
    grille gnext;
    for (int generation = 0; generation < 10; ++generation) {
        gnext = regle.appliquerRegle(guse);
        guse = std::move(gnext);
        graph graph(guse.getHauteur(), guse.getLargeur(), guse);
    
      sf::RenderWindow window(sf::VideoMode(guse.getLargeur()*10, guse.getHauteur()*10), "Game of Life");

     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        graph.renderGrid(window);

        sf::sleep(sf::milliseconds(3000));
            }   
        }
    }    



  void printconsole()
  {
    baserule regle;
    jeux game;
    std::unique_ptr<grille> gptr = game.setgrille();
    grille guse = std::move(*gptr);
    grille gnext;
    for (int generation = 0; generation < 10; ++generation) {
        gnext = regle.appliquerRegle(guse);
        guse = std::move(gnext);
        game.saveGrille(guse, generation);
    }
  }
int main() {
    std::cout << "choisissez votre mode :"
              << "1. affichage console"
              << "2. affichage graphique" <<std::endl;
    int mode;
    std::cin >> mode;

    if (mode==1) printconsole();
    if(mode==2) printgraph();

    return 0;
}