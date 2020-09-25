#ifndef CARTE_H
#define CARTE_H
////////////////////////////////////////////////////////////
// Carte.h
//
// Déclaration de la classe CCarte qui représente le monde
// dans lequel évoluent les personnages et les objets
// 
// Joan-Sébastien Morales 
// Création: 28 avril 2010
// Version 1.0
// Version 1.1 - Bloquer la copie
// Version 2.0 - 9 mai 2014 Adaptation à SFML - Carte dérive de Sprite
////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include "Position.h"

//--------------------------------------------------------//
// CCarte
//--------------------------------------------------------//
class CCarte: public sf::Sprite
{
private:
	// Bloquer la copie
	CCarte(const CCarte&);
	CCarte& operator=(const CCarte&);

	// Image d'obstruction
	sf::Image& Obstruction_;
public:
	////////////////////////////////////////////////////////////
	// CCarte
	// Constructeur paramétrique
	//
	// Intrants: 
	// Texture: Texture contenant l'image du monde 
	//                  
	// Obstruction: L'image d'obstruction est une version de
	//              l'image du monde où les pixels
	//              où les personnages peuvent passer
	//              sont de couleurs noires(RGB 0,0,0)
	////////////////////////////////////////////////////////////
	CCarte(sf::Texture& LaTexture, sf::Image& Obstruction);

	////////////////////////////////////////////////////////////
	// Afficher
	// Affiche la carte dans une fenêtre
	//
	// Intrant: Fenetre: Fenêtre dans laquelle la carte doit
	//                    être affichée
	////////////////////////////////////////////////////////////
	void Afficher(sf::RenderWindow& Fenetre)const;

	////////////////////////////////////////////////////////////
	// EstPositionValide
	// Permet de vérifier si un personnage peut se trouver à
	// une certain position sur la carte
	//
	// Intrant: Position: Position du personnage
	//
	// Extrant: Vrai si le personnage peut se trouver à cette
	//          position sur la carte, faux dans le cas 
	//          contraire
	////////////////////////////////////////////////////////////
	bool EstPositionValide(const CPosition& Position)const;
};

#endif // !CARTE_H
