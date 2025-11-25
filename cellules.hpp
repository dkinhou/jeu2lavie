#pragma once

class cellsule {
  public:
    virtual bool estVivante() const = 0;
    virtual void setVivante(bool etat) = 0;
    virtual ~cellsule() {}
};

