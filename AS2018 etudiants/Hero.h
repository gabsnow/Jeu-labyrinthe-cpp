#ifndef HERO_H
#define HERO_H
// Hero.h
// Fait par Gabriel Bourgeois le 30 avril 2018
// Interface de la classe CHero
#include "Personnage.h"
#include "Objet.h"
#include <ostream>

class CHero :
	public CPersonnage {
protected:
	/* Attributs */

	// Vitalité du personnage
	int Vitalite_;
	// Défense du personnage
	int Defense_;
	// Fortune du personnage
	int Fortune_;

	/* Accesseurs et mutateurs */

	virtual void SetBouger(const CCarte& Carte);
	virtual std::map<Direction, bool>& GetBouger();
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur paramétrique
	// Intrants: Texture, Position, Nom, Vitalité et Défense du héro
	////////////////////////////////////////////////////////////
	CHero(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom, int Vitalite, int Defense);

	/* Accesseurs et mutateurs */

	int GetVitalite()const;
	int GetDefense()const;
	int GetFortune()const;
	void SetVitalite(int Vitalite);
	void SetDefense(int Defense);
	void SetFortune(int Fortune);

	/* Méthodes */

	////////////////////////////////////////////////////////////
	// Déplacer
	// Calcule une nouvelle position en fonction de la touche appuyée par le joueur
	// Intrants: Carte, Position du héro
	// Extrant: Retourne true si le joueur à appuyé sur la touche d'échapement, 
	// ajuste la position du héro en fonction de son déplacement (s'il a lieu)
	////////////////////////////////////////////////////////////
	virtual bool Deplacer(CCarte& Carte, const CPosition& Pos);

	////////////////////////////////////////////////////////////
	// Prendre
	// Ramasse l'objet passé en paramètre s'il est assez proche et ajoute ses caractéristiques
	// à celles du personnage. Affiche ensuite un message indiquant les caractéristiques de l'objet
	// et celles du joueur à la console
	// Intrant: L'objet que le héro tente de prendre
	// Extrant: Retourne true si l'objet n'est pas ramassé
	////////////////////////////////////////////////////////////
	bool Prendre(CObjet& Objet);

	////////////////////////////////////////////////////////////
	// RéduireVie
	// Réduit la vie du personnage de 1 point, jusqu'au minimum de zéro
	////////////////////////////////////////////////////////////
	void ReduireVie();

	////////////////////////////////////////////////////////////
	// RéduireDéfense
	// Réduit la défense du personnage de 1 point, jusqu'au minimum de zéro
	////////////////////////////////////////////////////////////
	void ReduireDefense();

	////////////////////////////////////////////////////////////
	// RéduireFortune
	// Réduit la fortune du personnage de 1 point, jusqu'au minimum de zéro
	////////////////////////////////////////////////////////////
	void ReduireFortune();
};

////////////////////////////////////////////////////////////
// operator<<
// Affiche les caractéristiques du héro dans un flux de sortie
// Intrant: Flux de sortie, Héro
// Extrant: Flux de sortie
////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& OS, const CHero& Hero);

#endif // !HERO_H
