#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "grille.hpp"

class graph 
{
    private:
    const int cellsize=100;
    int gridWidth;
    int gridHeight;
    grille& grid;

    public:
    graph(int gridHeight, int gridWidth, grille& grid ): gridHeight(gridHeight), gridWidth(gridWidth),  grid(grid){}
    void renderGrid(sf::RenderWindow &window)
    {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellsize - 1.0f, cellsize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if ((grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == '1') {
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
            }
            else if ((grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == 'Y') {
                cell.setFillColor(sf::Color::Green);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
                //cell.setFillColor(sf::Color::White);
            }
            else if (!(grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == 'X') {
                cell.setFillColor(sf::Color::Red);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
                //cell.setFillColor(sf::Color::White);
            }
        }
    }
    window.display();
    }
    
    int getcellsize(){ return cellsize;}



};