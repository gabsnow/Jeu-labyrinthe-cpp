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
	// Constructeur param�trique
	// Intrants: Texture, Position et Nom de la brute
	////////////////////////////////////////////////////////////
	CBrute(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom);

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// Ataquer
	// Si le h�ro est proche, le monstre l'attaque: si le h�ro poss�de de la d�fense, on lui retire un point,
	// sinon, la brute enl�ve 1 point de vie au h�ro. Affiche tous les d�tails de l'attaque et les caract�ristiques finales
	// du h�ros.
	// Intrant: Le h�ro que la brute tentera d'attaquer
	// Extrant: Retourne true si le h�ro est toujours en vie apr�s l'attaque
	////////////////////////////////////////////////////////////
	virtual bool Attaquer(CHero& Hero);
};

#endif // !BRUTE_H
