// Objet.cpp
// Fait par Gabriel Bourgeois le 30 avril 2018
// Implémentation de la classe CObjet

#include "Objet.h"
#include "Constantes.h"

CObjet::CObjet(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom, int GainVie, int GainFortune, int GainDefense) : sf::Sprite(LaTexture) {
	setOrigin(getGlobalBounds().width / 2.0f, getGlobalBounds().height);
	setPosition(Pos);
	SetNom(Nom);
	SetGainVie(GainVie);
	SetGainFortune(GainFortune);
	SetGainDefense(GainDefense);
}
std::string CObjet::GetNom()const {
	return Nom_;
}
int CObjet::GetGainVie()const {
	return GainVie_;
}
int CObjet::GetGainDefense()const {
	return GainDefense_;
}
int CObjet::GetGainFortune()const {
	return GainFortune_;
}
void CObjet::SetNom(std::string Nom) {
	Nom_ = Nom;
}
void CObjet::SetGainVie(int GainVie) {
	GainVie_ = GainVie;
}
void CObjet::SetGainDefense(int GainDefense) {
	GainDefense_ = GainDefense;
}
void CObjet::SetGainFortune(int GainFortune) {
	GainFortune_ = GainFortune;
}
void CObjet::Afficher(sf::RenderWindow& Fenetre) {
	Fenetre.draw(*this);
}
std::ostream& operator<<(std::ostream& OS, CObjet& Objet) {
	OS << "Objet: " << Objet.GetNom() << std::endl;
	if (Objet.GetGainVie() > 0)
		OS << "Gain de vitalité:" << Objet.GetGainVie() << std::endl;
	if (Objet.GetGainDefense() > 0)
		OS << "Gain de défense: " << Objet.GetGainDefense() << std::endl;
	if (Objet.GetGainFortune() > 0)
		OS << "Gain de fortune: " << Objet.GetGainFortune() << std::endl;

	return OS;
}