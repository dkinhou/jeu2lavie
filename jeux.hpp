#pragma once 
#include "grille.hpp"
//#include "graphique.hpp"
#include "rule.hpp"
#include <fstream>

class jeux {
    private:
        std::string fichier;        
        grille *g;
        
    public:
        jeux(){
            std::cout<<"Entrez le nom du fichier de départ : "<<std::endl;
            std::cin>>fichier;
            

        }    
        std::string get_sf(){
            return fichier;
        }

        grille setgrille{
            std::fstream file(fichier);
            if(file.is_open()){
                int l,h;
                file>>h>>l;
                g = grille(h,l);
                for(int i=0;i<h;i++){
                    for(int j=0;j<l;j++){
                        char c;
                        file>>c;
                        if(c=='1'){
                            g.setcellule(j,i,std::make_unique<celluleVivante>());
                        } else {
                            g.setcellule(j,i,std::make_unique<celluleMorte>());
                        }
                    }
                }
            } else {
                std::cout<<"Erreur lors de l'ouverture du fichier : "<<fichier<<std::endl;
            }
         return g;
        }
        

        void saveGrille(int generation){
            std::ofstream file(dossierSauvegarde + "/generation_" + std::to_string(generation) + ".txt");
            if(file.is_open()){
                file<<gnext.getHauteur()<<" "<<gnext.getLargeur()<<std::endl;
                for(int i=0;i<gnext.getHauteur();i++){
                    for(int j=0;j<gnext.getLargeur();j++){
                        cellules* cell = gnext.getCellule(j,i);
                        file<<(cell->getetat() ? '1' : '0');
                    }
                    file<<std::endl;
                }
            } else {
                std::cout<<"Erreur lors de l'ouverture du fichier de sauvegarde."<<std::endl;
            }
        }
};