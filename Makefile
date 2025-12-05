all:
	g++ -std=c++17 exécution.cpp jeux.cpp cellules.cpp rule.cpp grille.cpp graphique.cpp -o game_of_life -lsfml-graphics -lsfml-window -lsfml-system
	./game_of_life
