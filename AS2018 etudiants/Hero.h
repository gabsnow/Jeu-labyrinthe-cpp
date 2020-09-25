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

	// Vitalit� du personnage
	int Vitalite_;
	// D�fense du personnage
	int Defense_;
	// Fortune du personnage
	int Fortune_;

	/* Accesseurs et mutateurs */

	virtual void SetBouger(const CCarte& Carte);
	virtual std::map<Direction, bool>& GetBouger();
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur param�trique
	// Intrants: Texture, Position, Nom, Vitalit� et D�fense du h�ro
	////////////////////////////////////////////////////////////
	CHero(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom, int Vitalite, int Defense);

	/* Accesseurs et mutateurs */

	int GetVitalite()const;
	int GetDefense()const;
	int GetFortune()const;
	void SetVitalite(int Vitalite);
	void SetDefense(int Defense);
	void SetFortune(int Fortune);

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// D�placer
	// Calcule une nouvelle position en fonction de la touche appuy�e par le joueur
	// Intrants: Carte, Position du h�ro
	// Extrant: Retourne true si le joueur � appuy� sur la touche d'�chapement, 
	// ajuste la position du h�ro en fonction de son d�placement (s'il a lieu)
	////////////////////////////////////////////////////////////
	virtual bool Deplacer(CCarte& Carte, const CPosition& Pos);

	////////////////////////////////////////////////////////////
	// Prendre
	// Ramasse l'objet pass� en param�tre s'il est assez proche et ajoute ses caract�ristiques
	// � celles du personnage. Affiche ensuite un message indiquant les caract�ristiques de l'objet
	// et celles du joueur � la console
	// Intrant: L'objet que le h�ro tente de prendre
	// Extrant: Retourne true si l'objet n'est pas ramass�
	////////////////////////////////////////////////////////////
	bool Prendre(CObjet& Objet);

	////////////////////////////////////////////////////////////
	// R�duireVie
	// R�duit la vie du personnage de 1 point, jusqu'au minimum de z�ro
	////////////////////////////////////////////////////////////
	void ReduireVie();

	////////////////////////////////////////////////////////////
	// R�duireD�fense
	// R�duit la d�fense du personnage de 1 point, jusqu'au minimum de z�ro
	////////////////////////////////////////////////////////////
	void ReduireDefense();

	////////////////////////////////////////////////////////////
	// R�duireFortune
	// R�duit la fortune du personnage de 1 point, jusqu'au minimum de z�ro
	////////////////////////////////////////////////////////////
	void ReduireFortune();
};

////////////////////////////////////////////////////////////
// operator<<
// Affiche les caract�ristiques du h�ro dans un flux de sortie
// Intrant: Flux de sortie, H�ro
// Extrant: Flux de sortie
////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& OS, const CHero& Hero);

#endif // !HERO_H
