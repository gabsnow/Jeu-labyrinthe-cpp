#ifndef VOLEUR_H
#define VOLEUR_H
// Voleur.h
// Fait par Gabriel Bourgeois le 30 avril 2018
// Interface de la classe CVoleur
#include "Monstre.h"

class CVoleur :
	public CMonstre {
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur param�trique
	// Intrants: Texture, Position, Nom du voleur
	////////////////////////////////////////////////////////////
	CVoleur(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom);

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// Attaquer
	// Si le h�ro est proche, le monstre l'attaque. Si le h�ro poss�de de la fortune, on lui enl�ve un point,
	// sinon, si le h�ro poss�de de la d�fense, le voleur lui en enl�ve un point, sinon, le voleur d�clare qu'il
	// n'y a rien d'int�ressant � voler ici. Affiche tous les d�tails de l'attaque et les caract�ristiques finales du h�ros.
	// Intrants: H�ro
	// Extrant: Retourne toujours true
	////////////////////////////////////////////////////////////
	virtual bool Attaquer(CHero& Hero);
};

#endif // !VOLEUR_H
