#ifndef FENETRE_H
#define FENETRE_H
////////////////////////////////////////////////////////////
// Fenetre.h
//
// Déclaration de la classe CFenetre qui permet de manipuler
// une fenêtre Windows.
//
// Joan-Sébastien Morales 
// Création: 28 avril 2010
// Version 1.0
// Version 1.1 - Bloquer la copie
// Version 2.0 - Encapsule RenderWindow - 5 mai 2014
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <string>
#include "Position.h"
using namespace sf;

//--------------------------------------------------------//
// CFenetre
//--------------------------------------------------------//
class CFenetre : public RenderWindow
{
public:
	////////////////////////////////////////////////////////////
	// CFenetre
	// Constructeur mixte
	//
	// Intrants: 
	// Titre: Nom qui sera affiché dans la barre de titre de la
	//        fenêtre
	// Largeur: Largeur de la fenêtre en pixels
	// Hauteur: Hauteur de la fenêtre en pixels
	//
	////////////////////////////////////////////////////////////
   CFenetre(int Hauteur = 800, int Largeur = 800, std::string Titre = "") : RenderWindow(VideoMode(Hauteur, Largeur), Titre) {}

	////////////////////////////////////////////////////////////
	// ~CFenetre
	// Destructeur
	//
	////////////////////////////////////////////////////////////
	//~CFenetre();

	////////////////////////////////////////////////////////////
	// Rafraichir
	// Mettre à jour la fenêtre
	//
	////////////////////////////////////////////////////////////
	//void Rafraichir() const;

	////////////////////////////////////////////////////////////
	// SetCamera
	// Modifie la position de la caméra dans le monde.
	// Puisque le monde est plus grand que la fenêtre,
	// seulement une partie du monde sera affichée.
	// La fenêtre sera centrée sur la position de la 
	// caméra.
	//
	// Intrant: position de la caméra
	//
	////////////////////////////////////////////////////////////
	void SetCamera(const CPosition& Camera);

	////////////////////////////////////////////////////////////
	// GetCamera
	// Retourne la position de la caméra dans le monde
	//
	// Extrant: position de la caméra 
	//
	////////////////////////////////////////////////////////////
	const CPosition& GetCamera() const;

	////////////////////////////////////////////////////////////
	// GetHauteur
	// Retourne la hauteur de la fenêtre en pixels
	//
	// Extrant: Hauteur de la fenêtre 
	//
	////////////////////////////////////////////////////////////
	//int GetHauteur() const;

	////////////////////////////////////////////////////////////
	// GetLargeur
	// Retourne la largeur de la fenêtre en pixels
	//
	// Extrant: Largeur de la fenêtre 
	//
	////////////////////////////////////////////////////////////
	//int GetLargeur() const;

	////////////////////////////////////////////////////////////
	// GetSurface
	// Retourne la surface SDL utilisée par la fenêtre
	// *** VOUS NE DEVEZ PAS UTILISER CETTE MÉTHODE!!!
	//
	// Extrant: Pointeur sur la surface SDL 
	//
	////////////////////////////////////////////////////////////
	/*SDL_Surface* GetSurface() { return Surface_; }*/

private:
	// Bloquer la copie
	CFenetre(const CFenetre&);
	CFenetre& operator=(const CFenetre&);

	// Largeur en pixels de la fenêtre
	//int Largeur_;
	// Hauteur en pixels de la fenêtre
	//int Hauteur_;
	// Position de la caméra sur la carte
	// La fenêtre sera centrée sur cette position
	CPosition Camera_; // viewport??
	
	// Mutateurs privés
	//void SetHauteur(int Hauteur);
	//void SetLargeur(int Largeur);
	//void SetSurface(SDL_Surface *Surface);

	// Largeur et hauteur par défaut
	//const static int iLARGEURDEFAUT=800;
	//const static int iHAUTEURDEFAUT=800;

	// Surface SDL
   //RenderWindow Rw_;
};

#endif // !FENETRE_H
