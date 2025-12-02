#pragma once


// Classe de base abstraite pour les cellules
class cellules {
  public:
    virtual bool getetat() const = 0;// Méthode virtuelle pure pour obtenir l'état de la cellule
    virtual char tochar() const = 0;// Méthode virtuelle pure pour obtenir la représentation en caractère de la cellule
    virtual ~cellules() = default;// Destructeur virtuel par défaut
};

// Classe dérivée pour une cellule vivante
class celluleVivante : public cellules {
  public:
    bool getetat() const override;
    char tochar() const override;
};

// Classe dérivée pour une cellule morte
class celluleMorte : public cellules {
  public:
    bool getetat() const override;
    char tochar() const override;

};

// Classe dérivée pour une cellule obstacle morte
class celluleObstaclemorte : public cellules {
  public:
    bool getetat() const override;
    char tochar() const override;
};

// Classe dérivée pour une cellule obstacle vivante
class celluleObstaclevivante : public cellules {
  public:
    bool getetat() const override;
    char tochar() const override;
};