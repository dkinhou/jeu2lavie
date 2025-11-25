#pragma once

class cellules {
  public:
    virtual bool estVivante() const = 0;
    virtual void setVivante(bool etat) = 0;
    virtual ~cellules() {}
};

class   celluleVivante : public cellules {
  private:
    bool vivante;

  public:
    celluleVivante() : vivante(true) {}
    bool estVivante() const override { return vivante; }
    void setVivante(bool etat) override { vivante = etat; }
}; 

class celluleMorte : public cellules {
  private:
    bool vivante;

  public:
    celluleMorte() : vivante(false) {}
    bool estVivante() const override { return vivante; }
    void setVivante(bool etat) override { vivante = etat; }
};