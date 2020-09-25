// Source.cpp
// Fait par Gabriel Bourgeois le 16 mai 2018
// Programme principal du jeu Treasure Hunter Version 2.0
// Activit� Synth�se 420-KAB-LG

#include "TreasureHunter.h"

int main(int argc, char *argv[]) {
	try {
		CTreasureHunter Game;

		while (Game.KeepPlaying())
			Game.Play();

		if (!Game.GetQuit())
			Game.End();
	}
	catch (std::string s) {
		std::cout << s << std::endl;
	}
	catch (...) {
		std::cout << "Erreur. (exception attrap�e)" << std::endl;
	}

	return 0;
}