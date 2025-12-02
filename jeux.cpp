#include "jeux.hpp"

 jeux::jeux(){}

 // Implementation du mode pour faire test unitaire (enregistrer une grille attendue)
void jeux::testunit(){
            cout<<"Entrez le nom du fichier attendue : "<<endl;
            cin>>fichier;

        }

// Implémentation du mode normal (ouvrir une grille de départ)
void jeux::normal(){
 cout<<"Entrez le nom du fichier de départ : "<<endl;
 cin>>fichier;
                dossierSauvegarde = fichier + "_out";
                if(!filesystem::exists(dossierSauvegarde)){
                    filesystem::create_directories(dossierSauvegarde);
                }
}

// Obtenir le fichier de départ
string jeux::get_sf(){
    return fichier;
}

// Obtenir le dossier de sauvegarde
string jeux::get_df(){
    return dossierSauvegarde;
}
    
// Initialiser la grille à partir du fichier
unique_ptr<grille> jeux::setgrille(){
    fstream file(fichier);
    // Lire les dimensions de la grille et initialiser la grille
    if(file.is_open()){
        int l,h;
        file>>h>>l;
        auto grid = make_unique<grille>(h,l);
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
        // Affecter la grille initialisée à l'attribut g
        g = move(grid);
    } else {
        cout<<"Erreur lors de l'ouverture du fichier : "<<fichier<<endl;
    }
    return move(g);
}

// Sauvegarder la grille dans un fichier
void jeux::saveGrille(const grille& gnext, int generation){
    ofstream file(dossierSauvegarde + "/generation_" + to_string(generation) + ".txt");
    // Écrire les dimensions de la grille
    if(file.is_open()){
        file<<gnext.getHauteur()<<" "<<gnext.getLargeur()<<endl;
        for(int i=0;i<gnext.getHauteur();i++){
            for(int j=0;j<gnext.getLargeur();j++){
                cellules* cell = gnext.getCellule(j,i);
                if(cell && (cell->tochar() == 'X' || cell->tochar() == 'Y')){
                    file<<cell->tochar();
                } else {
                file<<((cell && cell->getetat()) ? '1' : '0');
                }
            }
            file<<endl;
        }
    } else {
        cout<<"Erreur lors de l'ouverture du fichier de sauvegarde."<<endl;
    }
}

// Ajouter des formes prédéfinies

// Ajouter un clignoteur à la grille
void jeux::blinkers(int x_offset, int y_offset, grille& gr){
    gr.setcellule(x_offset, y_offset + 1, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 1, y_offset + 1, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 2, y_offset + 1, std::make_unique<celluleVivante>());
}

// Ajouter un planeur à la grille
void jeux::gliders(int x_offset, int y_offset, grille& gr){
    gr.setcellule(x_offset + 1, y_offset, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 2, y_offset + 1, make_unique<celluleVivante>());
    gr.setcellule(x_offset, y_offset + 2, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 1, y_offset + 2, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 2, y_offset + 2, make_unique<celluleVivante>());
}

// Ajouter un vaisseau spatial à la grille
void jeux::spaceship(int x_offset, int y_offset, grille& gr){
    gr.setcellule(x_offset + 1, y_offset, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 2, y_offset,make_unique<celluleVivante>());
    gr.setcellule(x_offset + 3, y_offset, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 4, y_offset, make_unique<celluleVivante>());
    gr.setcellule(x_offset, y_offset + 1, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 4, y_offset + 1, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 4, y_offset + 2, make_unique<celluleVivante>());
    gr.setcellule(x_offset, y_offset + 3, make_unique<celluleVivante>());
    gr.setcellule(x_offset + 3, y_offset + 3, make_unique<celluleVivante>());
}

// Ajouter un obstacle à la grille
void jeux::ajouterObstacle(int x_offset, int y_offset, grille& gr, bool vivante){
    if(vivante){
        gr.setcellule(x_offset, y_offset, make_unique<celluleObstaclevivante>());
    } else {
        gr.setcellule(x_offset, y_offset, make_unique<celluleObstaclemorte>());
    }
}

// Ajouter une cellule à la grille
void jeux::ajoutercellule(int x, int y, grille& gr, bool vivante){
    if(vivante){
        gr.setcellule(x, y, make_unique<celluleVivante>());
    } else {
        gr.setcellule(x, y, make_unique<celluleMorte>());
    }
}
