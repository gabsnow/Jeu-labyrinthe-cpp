// Personnage.cpp
// Fait par Gabriel Bourgeois le 30 avril 2018
// Implémentation de la classe CPersonnage

#include "Personnage.h"

CPersonnage::CPersonnage(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom) : CAnimation(LaTexture, Pos) {
	SetNom(Nom);
}
void CPersonnage::SetNom(std::string Nom) {
	Nom_ = Nom;
}
std::string CPersonnage::GetNom()const {
	return Nom_;
}