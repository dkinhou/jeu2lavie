#pragma once 
#include "grille.hpp"
//#include "graphique.hpp"
#include "rule.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <filesystem>

class jeux {
    private:
        std::string fichier;
        std::string dossierSauvegarde;
        std::unique_ptr<grille> g;
        
    public:
        jeux(){
        }
        
        void testunit(){
            std::cout<<"Entrez le nom du fichier attendue : "<<std::endl;
            std::cin>>fichier;

        }

        void normal(){
            std::cout<<"Entrez le nom du fichier de départ : "<<std::endl;
            std::cin>>fichier;
            dossierSauvegarde = fichier + "_out";
            if(!std::filesystem::exists(dossierSauvegarde)){
                std::filesystem::create_directories(dossierSauvegarde);
            }
        }
        std::string get_sf(){
            return fichier;
        }

        std::string get_df(){
            return dossierSauvegarde;
        }

        std::unique_ptr<grille> setgrille(){
            std::fstream file(fichier);
            if(file.is_open()){
                int l,h;
                file>>h>>l;
                auto grid = std::make_unique<grille>(h,l);
                for(int i=0;i<h;i++){
                    for(int j=0;j<l;j++){
                        char c;
                        file>>c;
                                if(c=='1'){
                                    grid->setcellule(j,i,std::make_unique<celluleVivante>());
                                } else if(c=='0'){
                                    grid->setcellule(j,i,std::make_unique<celluleMorte>());
                                } else if(c=='X'){
                                    grid->setcellule(j,i,std::make_unique<celluleObstaclemorte>());
                                } else if(c=='Y'){
                                    grid->setcellule(j,i,std::make_unique<celluleObstaclevivante>());
                                }
                    }
                }
                g = std::move(grid);
            } else {
                std::cout<<"Erreur lors de l'ouverture du fichier : "<<fichier<<std::endl;
            }
         return std::move(g);
        }
        

        void saveGrille(const grille& gnext, int generation){
            std::ofstream file(dossierSauvegarde + "/generation_" + std::to_string(generation) + ".txt");
            if(file.is_open()){
                file<<gnext.getHauteur()<<" "<<gnext.getLargeur()<<std::endl;
                for(int i=0;i<gnext.getHauteur();i++){
                    for(int j=0;j<gnext.getLargeur();j++){
                        cellules* cell = gnext.getCellule(j,i);
                        if(cell && (cell->tochar() == 'X' || cell->tochar() == 'Y')){
                            file<<cell->tochar();
                        } else {
                        file<<((cell && cell->getetat()) ? '1' : '0');
                        }
                    }
                    file<<std::endl;
                }
            } else {
                std::cout<<"Erreur lors de l'ouverture du fichier de sauvegarde."<<std::endl;
            }
        }

        // Ajouter des formes prédéfinies

    void blinkers(int x_offset, int y_offset, grille& gr){
        gr.setcellule(x_offset, y_offset + 1, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 1, y_offset + 1, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 2, y_offset + 1, std::make_unique<celluleVivante>());
    }

    void gliders(int x_offset, int y_offset, grille& gr){
        gr.setcellule(x_offset + 1, y_offset, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 2, y_offset + 1, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset, y_offset + 2, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 1, y_offset + 2, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 2, y_offset + 2, std::make_unique<celluleVivante>());
    }

    void spaceship(int x_offset, int y_offset, grille& gr){
        gr.setcellule(x_offset + 1, y_offset, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 2, y_offset, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 3, y_offset, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 4, y_offset, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset, y_offset + 1, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 4, y_offset + 1, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 4, y_offset + 2, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset, y_offset + 3, std::make_unique<celluleVivante>());
        gr.setcellule(x_offset + 3, y_offset + 3, std::make_unique<celluleVivante>());
    }

    void ajouterObstacle(int x_offset, int y_offset, grille& gr, bool vivante){
        if(vivante){
            gr.setcellule(x_offset, y_offset, std::make_unique<celluleObstaclevivante>());
        } else {
            gr.setcellule(x_offset, y_offset, std::make_unique<celluleObstaclemorte>());
        }
    }
    void ajoutercellule(int x, int y, grille& gr, bool vivante){
        if(vivante){
            gr.setcellule(x, y, std::make_unique<celluleVivante>());
        } else {
            gr.setcellule(x, y, std::make_unique<celluleMorte>());
        }
    }


};