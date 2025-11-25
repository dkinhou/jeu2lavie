#pragma once

#include "grille.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>

class console{
    private:
        std::string fichier;
        std::string dossierSauvegarde;
        
    public:
        console(){
            std::cout<<"Entrez le nom du fichier de départ : "<<std::endl;
            std::cin>>fichier;
            std::cout<<"Entrez le nom du dossier de sauvegarde : "<<std::endl;
            std::cin>>dossierSauvegarde;

        }    
        std::string get_sf(){
            return fichier;
        }

        std::string get_df(){
            return dossierSauvegarde;
        }

        void createDirectory(){
            if(std::filesystem::create_directory(dossierSauvegarde)){
                std::cout<<"Dossier de sauvegarde créé avec succès : "<<dossierSauvegarde<<std::endl;
            } else {
                std::cout<<"Le dossier de sauvegarde existe déjà ou une erreur est survenue."<<std::endl;
            }
        }
}
