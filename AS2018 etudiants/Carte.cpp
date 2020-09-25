// Carte.cpp
// Fait par Gabriel le 15 mai 2018
// Implémentation de la classe CCarte

#include "Carte.h"
using namespace sf;
using namespace std;

CCarte::CCarte(sf::Texture& LaTexture, sf::Image& Obstruction) : Sprite(LaTexture), Obstruction_(Obstruction)
{
}

void CCarte::Afficher(RenderWindow& Fenetre)const {
	Fenetre.draw(*this);
}

bool CCarte::EstPositionValide(const CPosition& Position)const {
   if (Position.x < 0 || Position.x >= Obstruction_.getSize().x || 
	   Position.y < 0 || Position.y >= Obstruction_.getSize().y)
      throw string("CCarte::EstPositionValide:: position en dehors de la carte!!");
   
   return Obstruction_.getPixel(static_cast<unsigned int>(Position.x), 
                                static_cast<unsigned int>(Position.y)) == Color::Black;
}

