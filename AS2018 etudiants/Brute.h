#ifndef BRUTE_H
#define BRUTE_H
// Brute.h
// Fait par Gabriel Bourgeois le 30 avril 2018
// Interface de la classe CBrute
#include "Monstre.h"

class CBrute :
	public CMonstre {
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur paramétrique
	// Intrants: Texture, Position et Nom de la brute
	////////////////////////////////////////////////////////////
	CBrute(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom);

	/* Méthodes */

	////////////////////////////////////////////////////////////
	// Ataquer
	// Si le héro est proche, le monstre l'attaque: si le héro possède de la défense, on lui retire un point,
	// sinon, la brute enlève 1 point de vie au héro. Affiche tous les détails de l'attaque et les caractéristiques finales
	// du héros.
	// Intrant: Le héro que la brute tentera d'attaquer
	// Extrant: Retourne true si le héro est toujours en vie après l'attaque
	////////////////////////////////////////////////////////////
	virtual bool Attaquer(CHero& Hero);
};

#endif // !BRUTE_H
