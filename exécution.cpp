#include "jeux.hpp"
#include "graphique.hpp"

void printgraph()
{
    baserule regle;
    jeux game;
    game.normal();
    std::unique_ptr<grille> gptr = game.setgrille();
    grille guse = std::move(*gptr);
    grille gnext;

    // Fenêtre créée UNE SEULE FOIS
    sf::RenderWindow window(
        sf::VideoMode(guse.getLargeur()*100, guse.getHauteur()*100),
        "Game of Life"
    );

    sf::Clock clock;
    const sf::Time interval = sf::milliseconds(3000); // temps entre générations

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
    game.normal();
    std::unique_ptr<grille> gptr = game.setgrille();
    grille guse = std::move(*gptr);
    grille gnext;
    
    for (int generation = 0; generation < 10; ++generation) {
        gnext = regle.appliquerRegle(guse);
        guse = std::move(gnext);
        game.saveGrille(guse, generation);
    }
  }


  void testunitaire(grille& gatendue, int generation)
  {
    baserule regle;
    jeux game;
    game.normal();
    std::unique_ptr<grille> gptr = game.setgrille();
    grille guse = std::move(*gptr);
    grille gnext;
    
    for (int gen = 0; gen < generation; ++gen) {
        gnext = regle.appliquerRegle(guse);
        guse = std::move(gnext);
    }

    // Comparer guse avec gatendue
    for (int y = 0; y < guse.getHauteur(); ++y) {
        for (int x = 0; x < guse.getLargeur(); ++x) {
            if (guse.getCellule(x, y)->getetat() != gatendue.getCellule(x, y)->getetat()) {
                std::cout << "Test unitaire échoué à la génération " << generation << " à la position (" << x << ", " << y << ")\n";
                return;
            }
        }
    }
    std::cout << "Test unitaire réussi pour la génération " << generation << "\n";
    
  }

int main() {
    std::cout << "choisissez votre mode :"<<std::endl
              << "1. affichage console" << std::endl
              << "2. affichage graphique" <<std::endl
              << "3. test unitaire" <<std::endl;
    int mode;
    std::cin >> mode;

    if (mode==1) printconsole();
    if(mode==2) printgraph();
    if(mode == 3){
        jeux attendueGame;
        attendueGame.testunit();
        std::unique_ptr<grille> gatenduePtr;
        gatenduePtr = attendueGame.setgrille();
        testunitaire(*gatenduePtr, 10);
    }

    return 0;
}