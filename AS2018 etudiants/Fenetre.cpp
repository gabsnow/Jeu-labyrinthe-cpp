// Fenetre.cpp
// Fait par Gabriel Bourgeois le 15 mai 2018
// Implémentation de la classe CFenetre

#include "Fenetre.h"

//CFenetre::CFenetre(string Titre, int Largeur, int Hauteur)
//{
//	// Nombre de bits par pixels par défaut
//	const int iBITSPERPIXELDEFAUT=32;
//
//	SetLargeur(Largeur);
//	SetHauteur(Hauteur);
//
//    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
//    SetSurface( SDL_SetVideoMode(GetLargeur(), GetHauteur(), 
//		        iBITSPERPIXELDEFAUT, SDL_HWSURFACE) );
//
//	SDL_WM_SetCaption(Titre.c_str(), 0);
//}
//void CFenetre::SetSurface(SDL_Surface *Surface)
//{
//	if(!Surface) throw string("CFenetre: Impossible de charger le mode vidéo");
//	Surface_ = Surface;
//}
//void CFenetre::SetHauteur(int Hauteur)
//{
//	if(Hauteur<=0) throw string("CFenetre: Hauteur invalide");
//	Hauteur_=Hauteur;
//}
//void CFenetre::SetLargeur(int Largeur)
//{
//	if(Largeur<=0) throw string("CFenetre: Largeur invalide");
//	Largeur_=Largeur;
//}
//int CFenetre::GetHauteur() const
//{
//	return Hauteur_;
//}
//int CFenetre::GetLargeur() const
//{
//	return Largeur_;
//}
//void CFenetre::Rafraichir() const
//{
//	SDL_Flip(Surface_);
//}
//CFenetre::~CFenetre()
//{
//	SDL_Quit();
//}
void CFenetre::SetCamera(const CPosition& Camera)
{
	Camera_ = Camera;
   View Vue = getView();
   Vue.setCenter(Camera);
   setView(Vue);
}
const CPosition& CFenetre::GetCamera() const
{
	return Camera_;
}

