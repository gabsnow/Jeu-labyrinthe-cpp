#ifndef MONSTRE_H
#define MONSTRE_H
// Monstre.h
// Fait par Gabriel Bourgeois le 30 avril 2018
// Interface de la classe CMonstre
#include "Personnage.h"
#include "Hero.h"

class CMonstre :
	public CPersonnage {
protected:
	/* Attributs */

	// Nombre de tours pendant lesquels le monstre continuera d'avancer dans la direction qu'il a choisi
	int Tours_; 

	/* Accesseurs et mutateurs */

	void SetTours(int Tours);
	virtual void SetBouger(const CCarte& Carte);
	virtual std::map<Direction, bool>& GetBouger();

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// D�placer
	// D�place le monstre dans la direction donn�e en param�tre, prend pour acquis que le d�placement
	// est possible
	// Intrant: Direction
	////////////////////////////////////////////////////////////
	void Deplacer(const Direction& Dir);
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur param�trique
	// Intrants: Texture, Position, Nom du monstre
	////////////////////////////////////////////////////////////
	CMonstre(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom);

	/* Accesseurs et mutateurs */

	int GetTours()const;

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// Deplacer
	// Deplace le monstre en choissisant une position valide dans laquelle il peut se raprocher du
	// h�ro. Si plus d'un choix est possible, il en choisira un au hasard, si aucun choix n'est possible, il
	// choisira une direction possible au hasard. Il selectionne un nombre de tours pour maintenir sa
	// direction pendant lesquels il continura d'avancer vers la m�me direction tant que possible. Lorsque le 
	// nombre de tours � atteint 0 ou qu'il se heurte � un mur, il s�lectionne une nouvelle direction.
	// Intrants: Carte, Position du h�ro
	// Extrant: Retourne toujours true
	////////////////////////////////////////////////////////////
	virtual bool Deplacer(CCarte& Carte, const CPosition& Pos);

	////////////////////////////////////////////////////////////
	// Attaquer
	// M�thode virtuelle pure pour attaquer le h�ro
	// Intrant: H�ro
	////////////////////////////////////////////////////////////
	virtual bool Attaquer(CHero& Hero) = 0;
};

#endif // !MONSTRE_H
