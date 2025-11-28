#pragma once

#include <memory>

class cellules {
  public:
    virtual bool getetat() const = 0;
    virtual char tochar() const = 0;
    virtual ~cellules() = default;
};

class celluleVivante : public cellules {
  public:
    bool getetat() const override { return true; }
    char tochar() const override { return '1'; }
};

class celluleMorte : public cellules {
  public:
    bool getetat() const override { return false; }
    char tochar() const override { return '0'; }

};


class celluleObstaclemorte : public cellules {
  public:
    bool getetat() const override { return false; }
    char tochar() const override { return 'X'; }
};

class celluleObstaclevivante : public cellules {
  public:
    bool getetat() const override { return true; }
    char tochar() const override { return 'Y'; }
};