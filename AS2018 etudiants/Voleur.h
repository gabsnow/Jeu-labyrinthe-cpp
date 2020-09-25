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
	// Constructeur paramétrique
	// Intrants: Texture, Position, Nom du voleur
	////////////////////////////////////////////////////////////
	CVoleur(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom);

	/* Méthodes */

	////////////////////////////////////////////////////////////
	// Attaquer
	// Si le héro est proche, le monstre l'attaque. Si le héro possède de la fortune, on lui enlève un point,
	// sinon, si le héro possède de la défense, le voleur lui en enlève un point, sinon, le voleur déclare qu'il
	// n'y a rien d'intéressant à voler ici. Affiche tous les détails de l'attaque et les caractéristiques finales du héros.
	// Intrants: Héro
	// Extrant: Retourne toujours true
	////////////////////////////////////////////////////////////
	virtual bool Attaquer(CHero& Hero);
};

#endif // !VOLEUR_H
