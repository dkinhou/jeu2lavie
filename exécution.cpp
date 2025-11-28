#include "jeux.hpp"
#include "graphique.hpp"

void printgraph()
{
    baserule regle;
    jeux game;

    std::unique_ptr<grille> gptr = game.setgrille();
    grille guse = std::move(*gptr);
    grille gnext;

    // Fenêtre créée UNE SEULE FOIS
    sf::RenderWindow window(
        sf::VideoMode(guse.getLargeur()*100, guse.getHauteur()*100),
        "Game of Life"
    );

    sf::Clock clock;
    const sf::Time interval = sf::milliseconds(30000); // temps entre générations

    while (window.isOpen())
    {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mise à jour de la génération toutes les X millisecondes
        if (clock.getElapsedTime() >= interval)
        {
            gnext = regle.appliquerRegle(guse);
            guse = std::move(gnext);
            clock.restart();
        }

        // Rendu
        window.clear();
        graph graph(guse.getHauteur(), guse.getLargeur(), guse);
        graph.renderGrid(window);
        window.display();
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