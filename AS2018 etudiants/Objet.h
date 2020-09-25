#ifndef OBJET_H
#define OBJEC_H
// Objet.h
// Fait par Gabriel Bourgeois le 30 avril 2018
// Interface de la classe CObjet
#include "Position.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <ostream>

class CObjet : 
	public sf::Sprite{
private:
	/* Attributs */

	// Nom de l'objet
	std::string Nom_;
	// Vitalit� que procure l'objet quand il est ramass�
	int GainVie_;
	// D�fense que procure l'objet quand il est ramass�
	int GainDefense_;
	// Fortune que procure l'objet quand il est ramass�
	int GainFortune_;
public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur param�trique
	// Intrants: Texture, Position, Nom, Gain en vitalit�, Gain en Fortune, Gain en d�fense de l'objet
	////////////////////////////////////////////////////////////
	CObjet(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom, int GainVie, int GainFortune, int GainDefense);

	/* Accesseurs et mutateurs */

	std::string GetNom()const;
	int GetGainVie()const;
	int GetGainDefense()const;
	int GetGainFortune()const;
	void SetNom(std::string Nom);
	void SetGainVie(int GainVie);
	void SetGainDefense(int GainDefense);
	void SetGainFortune(int GainFortune);

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// Afficher
	// Affiche l'objet dans la carte � la fen�tre
	// Intrants: Fen�tre
	////////////////////////////////////////////////////////////
	void Afficher(sf::RenderWindow& Fenetre);
};

////////////////////////////////////////////////////////////
// operator<<
// Affiche les caract�ristiques de l'objet au flux de sortie
// Intrants: Flux de sortie, Objet
// Extrant: Flux de sortie
////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& OS, CObjet& Objet);

#endif // !OBJET.H
