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
    sf::Keyboard::Key currentPatternKey = sf::Keyboard::Unknown;
    bool paused = false;

    // Fenêtre créée UNE SEULE FOIS
    sf::RenderWindow window(
        sf::VideoMode(guse.getLargeur()*100, guse.getHauteur()*100),
        "Game of Life"
    );

    sf::Clock clock;
    const sf::Time interval = sf::milliseconds(1500); // temps entre générations

    while (window.isOpen())
    {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Space){
                    paused = !paused;
                }
            }

            if (event.type == sf::Event::Closed)
              window.close();

            
            
            if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                int cellX = mouseX / 100;
                int cellY = mouseY / 100;

                // CORRECTION ICI : On vérifie l'état matériel de la touche B
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { 
                    currentPatternKey = sf::Keyboard::B; 
                    game.blinkers(cellX, cellY, guse);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { 
                    currentPatternKey = sf::Keyboard::G; 
                    game.gliders(cellX, cellY, guse);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { 
                    currentPatternKey = sf::Keyboard::S; 
                    game.spaceship(cellX, cellY, guse);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { 
                    currentPatternKey = sf::Keyboard::V; 
                    game.ajouterObstacle(cellX, cellY, guse, true);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { 
                    currentPatternKey = sf::Keyboard::M; 
                    game.ajouterObstacle(cellX, cellY, guse, false);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    currentPatternKey = sf::Keyboard::A;
                    game.ajoutercellule(cellX, cellY, guse, true);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    currentPatternKey = sf::Keyboard::D;
                    game.ajoutercellule(cellX, cellY, guse, false);
                }
            }
            }            
        }    

        // Mise à jour de la génération toutes les X millisecondes
        if (paused == false && clock.getElapsedTime() >= interval)
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
};    



  void printconsole()
  {
    baserule regle;
    jeux game;
    game.normal();
    std::unique_ptr<grille> gptr = game.setgrille();
    grille guse = std::move(*gptr);
    grille gnext;
    int gmax;
    std::cout << "Combien de générations voulez-vous afficher ?" << std::endl;
    std::cin >> gmax;
    for (int generation = 0; generation < gmax; ++generation) {
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
        int genmax;
        std::cout << "Entrez le numéro de génération à tester :" << std::endl;
        std::cin >> genmax;
        testunitaire(*gatenduePtr, genmax);
    }

    return 0;
}