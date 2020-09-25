// Voleur.cpp
// Fait par Gabriel Bourgeois le 30 avril 2018
// Impl�mentation de la classe CVoleur

#include "Voleur.h"
#include <iostream>

CVoleur::CVoleur(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom) : CMonstre(LaTexture, Pos, Nom) {

}
 bool CVoleur::Attaquer(CHero& Hero) {
	if (PositionsProches(getPosition(), Hero.getPosition())) {
		if (Hero.GetFortune() > 0) {
			Hero.ReduireFortune();
			std::cout << "Le voleur vole 1 point de fortune au h�ro." << std::endl;
		}
		else if (Hero.GetDefense() > 0){
			Hero.ReduireDefense();
			std::cout << "Le voleur vole 1 point de d'armure au h�ro." << std::endl;
		}
		else {
			std::cout << "Le voleur constate qu'il n'y a rien d'int�ressant � voler ici, le h�ro est nu." << std::endl;
		}
		std::cout << Hero << std::endl;
	}
	return true;
}