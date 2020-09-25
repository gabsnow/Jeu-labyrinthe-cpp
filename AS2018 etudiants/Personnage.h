#ifndef PERSONNAGE_H
#define PERSONNAGE_H
// Personnage.h
// Fait par Gabriel Bourgeois le 30 avril 2018
// Interface de la classe CPersonnage
#include "Animation.h"
#include "Carte.h"
#include "Constantes.h"
#include <map>
#include <string>
#include <SFML\Graphics.hpp>

class CPersonnage :
	public CAnimation {
protected:
	/* Attributs */

	// Nom du personnage
	std::string Nom_;
	// Map de <directions,bool> indiquant vers quelle(s) direction(s) le personnage peut se déplacer
	std::map<Direction, bool>Bouger_;

	/* Accesseurs et mutateurs */

	virtual void SetBouger(const CCarte& Carte) = 0;
	void SetNom(std::string Nom);
	virtual std::map<Direction, bool>& GetBouger() = 0;
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur paramétrique
	// Intrants: Texture, Position, Nom du personnage
	////////////////////////////////////////////////////////////
	CPersonnage(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom);

	/* Accesseurs et mutateurs */

	std::string GetNom()const;

	/* Méthodes */

	////////////////////////////////////////////////////////////
	// Deplacer
	// Méthode virtuelle pure pour déplacer un personnage dans la carte
	// Intrants: Carte, Position du personnage
	// Extrant: Booléen
	////////////////////////////////////////////////////////////
	virtual bool Deplacer(CCarte& Carte, const CPosition& Pos) = 0;
};

#endif // !PERSONNAGE_H
