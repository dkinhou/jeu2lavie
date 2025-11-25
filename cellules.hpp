#pragma once



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
    
    bool getetat(){
        return etat->etat();
    }
    char tochar(){
        return etat->etat() ? 'O' : '.';
    }
};

