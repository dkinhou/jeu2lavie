#pragma once

#include <SFML/Graphics.hpp>//inclure les bibliotheques SFML pour la gestion graphique
#include <vector>//inclure la bibliotheque vector pour utiliser les vecteurs
#include <ctime>//inclure la bibliotheque ctime pour la gestion du temps
#include <cstdlib>//inclure la bibliotheque cstdlib pour les fonctions utilitaires
#include <memory>//inclure la bibliotheque memory pour la gestion de la memoire
#include "grille.hpp"//inclure le fichier grille.hpp pour utiliser la classe grille
#include "jeux.hpp"//inclure le fichier jeux.hpp pour utiliser la classe jeux

//utilisation des espaces de noms std et sf
using namespace std;
using namespace sf;

class graph 
{
    private:
        int cellsize;//taille de chaque cellule dans la grille
        int gridWidth;//largeur de la grille
        int gridHeight;//hauteur de la grille
        grille& grid;//reference a un objet grille
        Event event;//objet pour gerer les evenements de la fenetre
        RenderWindow window;//objet fenetre SFML pour afficher la grille
    public:
        graph(int gridHeight, int gridWidth, grille& grid );//constructeur personnalisé de la classe graph
        void renderGrid(RenderWindow &window);//methode pour afficher la grille dans une fenetre SFML
        int getcellsize();//methode pour obtenir la taille d'une cellule
        void closewindow(); //methode pour fermer la fenetre SFML
        void clearwindow(); //methode pour nettoyer la fenetre SFML
        void displaywindow();//methode pour afficher le contenu de la fenetre SFML
        void handleEvents(Event event, jeux& game, grille& guse, bool& paused);//methode pour gerer les evenements de la fenetre SFML
        RenderWindow& getwindow(); //methode pour obtenir la fenetre SFML



};



