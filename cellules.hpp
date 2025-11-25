#pragma once

#include <memory>

class etatCellule {
  public:
    virtual bool etat() const = 0;
};

class   celluleVivante : public etatCellule {
  public:
    bool etat()override { return true; }
}; 

class celluleMorte : public etatCellule {
  public:
    bool etat()override { return false; }
};

class cellules {
    etatCellule* etat;
  public:
    cellules(etatCellule* e) : etat(e) {}
    void setetat(bool vivant){
        if(vivant){
            etat = new celluleVivante();
        } else {
            etat = new celluleMorte();
        }
    }
    bool getetat(){
        return etat->etat();
    }
    char tochar(){
        return etat->etat() ? 'O' : '.';
    }
};

