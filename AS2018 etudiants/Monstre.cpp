// Monstre.cpp
// Fait par Gabriel Bourgeois le 30 avril 2018
// Implémentation de la classe CMonstre

#include "Monstre.h"
#include <vector>

CMonstre::CMonstre(sf::Texture& LaTexture, const CPosition& Pos, std::string Nom) : CPersonnage(LaTexture, Pos, Nom) {
	SetTours(0);
}
void CMonstre::SetBouger(const CCarte& Carte) {
	CPosition TempPos(getPosition());
	
	TempPos.x += MonsterSpeed;
	Bouger_[Droite] = Carte.EstPositionValide(TempPos);
	TempPos = getPosition();

	TempPos.x -= MonsterSpeed;
	Bouger_[Gauche] = Carte.EstPositionValide(TempPos);
	TempPos = getPosition();

	TempPos.y -= MonsterSpeed;
	Bouger_[Haut] = Carte.EstPositionValide(TempPos);
	TempPos = getPosition();

	TempPos.y += MonsterSpeed;
	Bouger_[Bas] = Carte.EstPositionValide(TempPos);
}
std::map<Direction, bool>& CMonstre::GetBouger() {
	return Bouger_;
}
int CMonstre::GetTours()const {
	return Tours_;
}
void CMonstre::SetTours(int Tours) {
	Tours_ = Tours;
}
void CMonstre::Deplacer(const Direction& Dir) {
	CPosition Position(getPosition());
	switch (Dir) {
	case Droite:
		Position.x += MonsterSpeed;
		break;
	case Gauche:
		Position.x -= MonsterSpeed;
		break;
	case Haut:
		Position.y -= MonsterSpeed;
		break;
	case Bas:
		Position.y += MonsterSpeed;
	}
	setPosition(Position);
}
bool CMonstre::Deplacer(CCarte& Carte, const CPosition& Pos) {
	SetBouger(Carte);

	if (GetTours() == 0) {
		std::vector<Direction> DirMonstre;
		int NbChoix(0);

		if (Pos.x > getPosition().x && Bouger_[Droite]) {
			DirMonstre.push_back(Droite);
			NbChoix++;
		}
		if (Pos.x < getPosition().x && Bouger_[Gauche]) {
			DirMonstre.push_back(Gauche);
			NbChoix++;
		}
		if (Pos.y > getPosition().y && Bouger_[Bas]) {
			DirMonstre.push_back(Bas);
			NbChoix++;
		}
		if (Pos.y < getPosition().y && Bouger_[Haut]) {
			DirMonstre.push_back(Haut);
			NbChoix++;
		}

		switch (NbChoix) {
		case 1:
			Deplacer(DirMonstre[0]);
			SetDirection(DirMonstre[0]);
			break;
		case 2:
			if (rand() % 2 == 0) {
				Deplacer(DirMonstre[0]);
				SetDirection(DirMonstre[0]);
			}
			else {
				Deplacer(DirMonstre[1]);
				SetDirection(DirMonstre[1]);
			}
			break;
		case 0:
			Direction Dir;
			do {
				 Dir = static_cast<Direction>(rand() % 4);
			} while (!Bouger_[Dir]);
			Deplacer(Dir);
			SetDirection(Dir);
			break;
		default:
			break;
		}
		SetTours(rand() % (MaxTurns - MinTurns + 1 ) + MinTurns);
	}
	else {
		if (Bouger_[GetDirection()]) {
			Deplacer(GetDirection());
			SetTours(GetTours() - 1);
		}
		else {
			SetTours(0);
			Deplacer(Carte, Pos);
		}
	}
	return true;
}