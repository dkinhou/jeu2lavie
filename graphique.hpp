#pragma once

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