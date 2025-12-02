#include "jeux.hpp"
#include "graphique.hpp"

void printgraph()
{
    baserule regle;
    jeux game;
    game.normal();
    unique_ptr<grille> gptr = game.setgrille();
    grille guse = move(*gptr);
    grille gnext;
    bool paused = false;

    graph graph(guse.getHauteur(), guse.getLargeur(), guse);

    Clock clock;
    const Time interval = milliseconds(1500); // temps entre générations

    while (graph.getwindow().isOpen())
    {
        // Gestion des événements
        Event event;
        while (graph.getwindow().pollEvent(event)) {
            graph.handleEvents(event, game, guse, paused);           
        }    

        // Mise à jour de la génération toutes les X millisecondes
        if (paused == false && clock.getElapsedTime() >= interval)
        {
            gnext = regle.appliquerRegle(guse);
            guse = move(gnext);
            clock.restart(); 
        }

        // Rendu
        graph.clearwindow();
        graph.renderGrid(graph.getwindow());
        graph.displaywindow();
        
    }
};    



  void printconsole()
  {
    baserule regle;
    jeux game;
    game.normal();
    unique_ptr<grille> gptr = game.setgrille();
    grille guse = move(*gptr);
    grille gnext;
    int gmax;
    cout << "Combien de générations voulez-vous afficher ?" << std::endl;
    cin >> gmax;
    for (int generation = 0; generation < gmax; ++generation) {
        gnext = regle.appliquerRegle(guse);
        guse = move(gnext);
        game.saveGrille(guse, generation);
    }
  }


  void testunitaire(grille& gatendue, int generation)
  {
    baserule regle;
    jeux game;
    game.normal();
    unique_ptr<grille> gptr = game.setgrille();
    grille guse = move(*gptr);
    grille gnext;
    
    for (int gen = 0; gen < generation; ++gen) {
        gnext = regle.appliquerRegle(guse);
        guse = move(gnext);
    }

    // Comparer guse avec gatendue
    for (int y = 0; y < guse.getHauteur(); ++y) {
        for (int x = 0; x < guse.getLargeur(); ++x) {
            if (guse.getCellule(x, y)->getetat() != gatendue.getCellule(x, y)->getetat()) {
                cout << "Test unitaire échoué à la génération " << generation << " à la position (" << x << ", " << y << ")\n";
                return;
            }
        }
    }
    cout << "Test unitaire réussi pour la génération " << generation << "\n";
    
  }

int main() {
    cout << "choisissez votre mode :" << endl
              << "1. affichage console" << endl
              << "2. affichage graphique" << endl
              << "3. test unitaire" << endl;
    int mode;
    cin >> mode;

    if (mode==1) printconsole();
    if(mode==2) printgraph();
    if(mode == 3){
        jeux attendueGame;
        attendueGame.testunit();
        unique_ptr<grille> gatenduePtr;
        gatenduePtr = attendueGame.setgrille();
        int genmax;
        cout << "Entrez le numéro de génération à tester :" << endl;
        cin >> genmax;
        testunitaire(*gatenduePtr, genmax);
    }

    return 0;
}