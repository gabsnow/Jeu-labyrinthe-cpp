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
	// Map de <directions,bool> indiquant vers quelle(s) direction(s) le personnage peut se d�placer
	std::map<Direction, bool>Bouger_;

	/* Accesseurs et mutateurs */

	virtual void SetBouger(const CCarte& Carte) = 0;
	void SetNom(std::string Nom);
	virtual std::map<Direction, bool>& GetBouger() = 0;
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur param�trique
	// Intrants: Texture, Position, Nom du personnage
	////////////////////////////////////////////////////////////
	CPersonnage(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom);

	/* Accesseurs et mutateurs */

	std::string GetNom()const;

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// Deplacer
	// M�thode virtuelle pure pour d�placer un personnage dans la carte
	// Intrants: Carte, Position du personnage
	// Extrant: Bool�en
	////////////////////////////////////////////////////////////
	virtual bool Deplacer(CCarte& Carte, const CPosition& Pos) = 0;
};

#endif // !PERSONNAGE_H
