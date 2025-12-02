#include "graphique.hpp"

//Implementation du constructeur de la classe graph
graph::graph(int gridHeight, int gridWidth, grille& grid ): gridHeight(gridHeight), gridWidth(gridWidth),  grid(grid){}

//Implementation de la methode renderGrid pour afficher la grille dans une fenetre SFML
void graph::renderGrid(RenderWindow &window)
    {
    int x, y;
    
    window.clear();
    RectangleShape cell(Vector2f(cellsize - 1.0f, cellsize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if ((grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == '1') {
                cell.setFillColor(Color::White);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
            }
            else if ((grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == 'Y') {
                cell.setFillColor(Color::Green);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
                
            }
            else if (!(grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == 'X') {
                cell.setFillColor(Color::Red);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
                
            }
        }
    }
    window.display();
    }
    
    //Implementation de la methode getcellsize pour obtenir la taille d'une cellule
    int graph::getcellsize(){ return cellsize;}