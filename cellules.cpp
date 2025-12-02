#include "cellules.hpp"

//Implémentation de la méthode pour obtenir l'état de la cellule vivante
bool celluleVivante::getetat() const {
    return true;
}

//Implémentation de la méthode pour obtenir la représentation en caractère de la cellule vivante
char celluleVivante::tochar() const {
    return '1';
}

//Implémentation de la méthode pour obtenir l'état de la cellule morte
bool celluleMorte::getetat() const {
    return false;
}

//Implémentation de la méthode pour obtenir la représentation en caractère de la cellule morte
char celluleMorte::tochar() const {
    return '0';
}

//Implémentation de la méthode pour obtenir l'état de la cellule obstacle morte
bool celluleObstaclemorte::getetat() const {
    return false;
}

//Implémentation de la méthode pour obtenir la représentation en caractère de la cellule obstacle morte
char celluleObstaclemorte::tochar() const {
    return 'X';
}

//Implémentation de la méthode pour obtenir l'état de la cellule obstacle vivante
bool celluleObstaclevivante::getetat() const {
    return true;
}

//Implémentation de la méthode pour obtenir la représentation en caractère de la cellule obstacle vivante
char celluleObstaclevivante::tochar() const {
    return 'Y';
}

