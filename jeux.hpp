#pragma once 
#include "grille.hpp"
#include "rule.hpp"
#include <fstream>// Bibliothèque pour la gestion des fichiers
#include <iostream>
#include <string>
#include <memory>
#include <filesystem>// Bibliothèque pour la gestion des fichiers et des répertoires

using namespace std;

class jeux {
    private:
        string fichier;// fichier de départ
        string dossierSauvegarde;// dossier de sauvegarde
        unique_ptr<grille> g;// grille actuelle
        
    public:
        jeux();// constructeur
        void testunit();// mode pour faire test unitaire (enregistrer une grille attendue)
        void normal();// mode normal (ouvrir une grille de départ)
        string get_sf();// obtenir le fichier de départ
        string get_df();// obtenir le dossier de sauvegarde
        unique_ptr<grille> setgrille();// initialiser la grille à partir du fichier
        

    void saveGrille(const grille& gnext, int generation);// sauvegarder la grille dans un fichier

    // Ajouter des formes prédéfinies

    void blinkers(int x_offset, int y_offset, grille& gr);// ajouter un clignoteur à la grille

    void gliders(int x_offset, int y_offset, grille& gr);// ajouter un planeur à la grille

    void spaceship(int x_offset, int y_offset, grille& gr);// ajouter un vaisseau spatial à la grille

    void ajouterObstacle(int x_offset, int y_offset, grille& gr, bool vivante);// ajouter un obstacle à la grille

    void ajoutercellule(int x, int y, grille& gr, bool vivante);// ajouter une cellule à la grille

};