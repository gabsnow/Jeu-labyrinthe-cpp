// Brute.cpp
// Fait par Gabriel Bourgeois le 30 avril 2018
// Implémentation de la classe CBrute

#include "Brute.h"
#include <iostream>

CBrute::CBrute(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom) : CMonstre(LaTexture, Pos, Nom) {

}
bool CBrute::Attaquer(CHero& Hero) {
	if (PositionsProches(getPosition(), Hero.getPosition())) {
		if (Hero.GetDefense() > 0) {
			Hero.ReduireDefense();
			std::cout << "La brute attaque l'armure du héro et lui retire 1 point de défense." << std::endl;
		}
		else {
			Hero.ReduireVie();
			std::cout << "La brute attaque le héro et lui retire 1 point de vitalité." << std::endl;
		}
		std::cout << Hero << std::endl;
	}
	return Hero.GetVitalite() > 0;
}