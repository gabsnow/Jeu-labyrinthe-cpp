// Hero.cpp
// Fait par Gabriel Bourgeois le 30 avril 2018
// Implémentation de la classe CHero

#include "Hero.h"
#include "Constantes.h"
#include <iostream>

CHero::CHero(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom, int Vitalite, int Defense) : CPersonnage(LaTexture, Pos, Nom) {
	SetVitalite(Vitalite);
	SetDefense(Defense);
	SetFortune(0);
}
void CHero::SetBouger(const CCarte& Carte){
	CPosition TempPos(getPosition());

	TempPos.x += HeroSpeed;
	Bouger_[Droite] = Carte.EstPositionValide(TempPos);
	TempPos = getPosition();

	TempPos.x -= HeroSpeed;
	Bouger_[Gauche] = Carte.EstPositionValide(TempPos);
	TempPos = getPosition();

	TempPos.y -= HeroSpeed;
	Bouger_[Haut] = Carte.EstPositionValide(TempPos);
	TempPos = getPosition();

	TempPos.y += HeroSpeed;
	Bouger_[Bas] = Carte.EstPositionValide(TempPos);
}
std::map<Direction, bool>& CHero::GetBouger() {
	return Bouger_;
}
int CHero::GetVitalite()const {
	return Vitalite_;
}
int CHero::GetDefense()const {
	return Defense_;
}
int CHero::GetFortune()const {
	return Fortune_;
}
void CHero::SetVitalite(int Vitalite) {
	if (Vitalite >= 0)
		Vitalite_ = Vitalite;
}
void CHero::SetDefense(int Defense) {
	if (Defense >= 0)
		Defense_ = Defense;
}
void CHero::SetFortune(int Fortune) {
	if (Fortune >= 0)
		Fortune_ = Fortune;
}
bool CHero::Deplacer(CCarte& Carte, const CPosition& Pos) {
	CPosition NewPos(Pos);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		NewPos.y += HeroSpeed;
		if (Carte.EstPositionValide(NewPos)) {
			setPosition(NewPos);
			SetDirection(Bas);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		NewPos.y -= HeroSpeed;
		if (Carte.EstPositionValide(NewPos)) {
			setPosition(NewPos);
			SetDirection(Haut);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		NewPos.x += HeroSpeed;
		if (Carte.EstPositionValide(NewPos)) {
			setPosition(NewPos);
			SetDirection(Droite);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		NewPos.x -= HeroSpeed;
		if (Carte.EstPositionValide(NewPos)) {
			setPosition(NewPos);
			SetDirection(Gauche);
		}
	}

	return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
}
bool CHero::Prendre(CObjet& Objet) {
	bool ObjetProche = PositionsProches(getPosition(), Objet.getPosition());
	if (ObjetProche) {
		SetVitalite(GetVitalite() + Objet.GetGainVie());
		SetDefense(GetDefense() + Objet.GetGainDefense());
		SetFortune(GetFortune() + Objet.GetGainFortune());

		std::cout << Objet << std::endl;
		std::cout << *this << std::endl;
	}
	return !ObjetProche;
}
void CHero::ReduireVie() {
	SetVitalite(GetVitalite() - 1);
}
void CHero::ReduireDefense() {
	SetDefense(GetDefense() - 1);
}
void CHero::ReduireFortune() {
	SetFortune(GetFortune() - 1);
}
std::ostream& operator<<(std::ostream& OS, const CHero& Hero) {
	OS << "Hero: " << Hero.GetNom() << std::endl;
	OS << "Vitalité:" << Hero.GetVitalite() << std::endl;
	OS << "Défense: " << Hero.GetDefense() << std::endl;
	OS << "Fortune: " << Hero.GetFortune() << std::endl;
	return OS;
}
