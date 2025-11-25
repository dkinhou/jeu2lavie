#pragma once
/*
#include <string>
#include <vector>
#include "grille.hpp"
#include <SFML/Graphics.hpp>

class graphique {
  private:
    sf::RenderWindow window;
    int cellSize;
    sf::Color aliveColor;
    sf::Color deadColor;

  public:
    graphique(int width, int height, int cellSize = 10)
        : window(sf::VideoMode(width * cellSize, height * cellSize), "Jeu de la Vie"),
          cellSize(cellSize), aliveColor(sf::Color::Green), deadColor(sf::Color::Black) {}

    void drawGrille(const grille& g) {
        window.clear(deadColor);
        for (int y = 0; y < g.getHauteur(); ++y) {
            for (int x = 0; x < g.getLargeur(); ++x) {
                cellules* cell = g.getCellule(x, y);
                if (cell && cell->estVivante()) {
                    sf::RectangleShape rectangle(sf::Vector2f(cellSize - 1, cellSize - 1));
                    rectangle.setPosition(x * cellSize, y * cellSize);
                    rectangle.setFillColor(aliveColor);
                    window.draw(rectangle);
                }
            }
        }
        window.display();
    }

    bool isOpen() const {
        return window.isOpen();
    }

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
};
*/



#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

const int cellSize = 10;
const int gridWidth = 80;
const int gridHeight = 80;

std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

void initializeGrid() {
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
}

void renderGrid(sf::RenderWindow &window) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    
    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window);

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
