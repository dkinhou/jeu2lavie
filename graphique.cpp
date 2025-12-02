    #include "graphique.hpp"

    // Ajout d'une constante pour la dimension maximale souhaitée
    const int MAX_DIMENSION = 1000; 

    // Implementation du constructeur de la classe graph
    graph::graph(int gridHeight, int gridWidth, grille& grid ) 
        : gridHeight(gridHeight), gridWidth(gridWidth), grid(grid) 
{
    // Calculer la taille de cellule pour que la grille entière rentre
    // On prend le maximum des deux dimensions de la grille
    int maxGridDim = std::max(gridHeight, gridWidth);

    // Calculer la nouvelle taille de cellule (au minimum 1 pixel)
    this->cellsize = std::max(1, MAX_DIMENSION / maxGridDim);

    // Initialiser la fenêtre avec la nouvelle taille
    this->window.create(
        sf::VideoMode(gridWidth * this->cellsize, gridHeight * this->cellsize), 
        "Game of Life"
    );
}
    //Implementation de la methode renderGrid pour afficher la grille dans une fenetre SFML
    void graph::renderGrid(RenderWindow &window)
    {
    int x, y;
    
    window.clear();
    // Dessiner les cellules
    RectangleShape cell(Vector2f(cellsize - 1.0f, cellsize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            // visualisation des cellules vivantes
            if ((grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == '1') {
                cell.setFillColor(Color::White);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
            }
            // visualisation des obstacles vivants
            else if ((grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == 'Y') {
                cell.setFillColor(Color::Green);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
                
            }
            // visualisation des cellules mortes
            else if (!(grid.getCellule(x, y))->getetat() && (grid.getCellule(x, y))->tochar() == '0') {
                cell.setFillColor(Color::Black);
                cell.setPosition(x * cellsize, y * cellsize);
                window.draw(cell);
            }
            // visualisation des obstacles morts
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

    //Implementation de la methode closewindow pour fermer la fenetre SFML
    void graph::closewindow(){window.close();} 

    //Implementation de la methode clearwindow pour nettoyer la fenetre SFML
    void graph::clearwindow(){window.clear();} 

    //Implementation de la methode displaywindow pour afficher le contenu de la fenetre SFML
    void graph::displaywindow(){window.display();} 

    //Gestion des evenements de la fenetre SFML
    void graph::handleEvents(Event event, jeux& game, grille& guse, bool& paused)
    {        
            // Gérer la mise en pause avec la touche Espace
            if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Space){
                    paused = !paused;
                }
            }
            // Fermer la fenêtre si l'événement de fermeture est détecté
            if (event.type == sf::Event::Closed)
              window.close();

            
            // Obtention de la position de la souris lors d'un clic 
            if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                int cellX = mouseX / this->cellsize;
                int cellY = mouseY / this->cellsize;

                // On vérifie l'état matériel de la touche B
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { 
                     // Ajouter un clignoteur à la position cliquée
                    game.blinkers(cellX, cellY, guse);
                }
                // On vérifie l'état matériel de la touche G
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { 
                    // Ajouter un planeur à la position cliquée
                    game.gliders(cellX, cellY, guse);
                }
                // On vérifie l'état matériel de la touche S
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { 
                    // Ajouter un vaisseau spatial à la position cliquée
                    game.spaceship(cellX, cellY, guse);
                }
                // On vérifie l'état matériel de la touche V
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { 
                    // Ajouter un obstacle vivant à la position cliquée
                    game.ajouterObstacle(cellX, cellY, guse, true);
                }
                // On vérifie l'état matériel de la touche M
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { 
                    // Ajouter un obstacle mort à la position cliquée
                    game.ajouterObstacle(cellX, cellY, guse, false);
                }
                // On vérifie l'état matériel de la touche A
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    // Ajouter une cellule vivante à la position cliquée
                    game.ajoutercellule(cellX, cellY, guse, true);
                }
                // On vérifie l'état matériel de la touche D
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    // Ajouter une cellule morte à la position cliquée
                    game.ajoutercellule(cellX, cellY, guse, false);
                }
            }
            } 
        
    }

    RenderWindow& graph::getwindow(){return window;}        