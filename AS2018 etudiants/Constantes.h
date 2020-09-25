#ifndef CONSTANTES_H
#define CONSTANTES_H
// Constants.h 
// D�claration des constantes servant � param�trer ais�ment le jeu
// Fait par Gabriel Bourgeois le 16 mai 2018
//////////////////////////////////////////////////////////////////

// Nombre de sous au d�but du jeu
const int GoldNb(15);

// Nombre d'autres objets (pains, boucliers) au d�but du jeu
const int OtherObjetNb(15);

// Nombre total d'objets au d�but du jeu
const int ObjectNb(GoldNb + OtherObjetNb);

// Nombre de sous que doit poss�der le h�ros pour gagner
const int GoldToWin(10);

// Nombre de monstres au total dans le jeu
const int MonsterNb(30);

// Longueur d'un d�placement de monstre (en pixels)
const int MonsterSpeed(3);

// Longueur d'un d�placement du h�ros (en pixels)
const int HeroSpeed(6);

// Nombre de tours minimum et maximum pendant lesquels un monstre
// conservera sa direction avant de la changer pour se rapprocher
// du h�ros.  Plus les nombres sont petits, plus les monstres tentent
// de suivre le h�ros, mais moins ils ont de chance de contourner
// les obstacles.
const int MinTurns(5);
const int MaxTurns(20);

// Dimensions de la fen�tre de jeu
const int WindowWidth(1024);
const int WindowHeight(768);

// Dimension du monde
const int MapWidth(2398);
const int MapHeight(2298);

// Dimensions du rectangle pour les indicateurs
const int IndicatorBGWidth(1024);
const int IndicatorBGHeight(100);

// Nombre d'indicateurs
const int IndicatorNb(3);

// Taille de l'�criture pour "Pause" et pour le message de fin
const int PauseCharSize(224);

// Taille de l'indice des indicateurs
const int IndicatorCharSize(75);

// Nombre de textures � charger
const int TextureNb(8);

// Nombre de textes � charger
const int TextNb(5);

// Nombre de sons � charger
const int SoundNb(7);

// Nombre de millisecondes � attendre pour rafraichir le jeu
const int SleepTime(30);

// Enum�ration repr�sentant les indicateurs
enum Indicator {
	I_Heart = 0, // Indicateur/Indice de vie
	I_Shield, // Indicateur/Indice de bouclier
	I_Gold, // Indicateur/Indice de fortune
	I_Pause, // Message de pause
	I_End // Message de fin
};

// �num�ration repr�sentant les objets du monde
enum Object {
	O_Map = 0, // Carte du jeu
	O_Hero, // Hero
	O_Brute, // Brute 
	O_Thief, // Voleur
	O_Bread, // Pain
	O_Shield, // Bouclier
	O_Gold, // Sou
	O_Hearts // Coeur
};

// �num�ration repr�sentant les sons du jeu
enum GameSound {
	S_Punch = 0,
	S_Whip,
	S_PickCoin,
	S_PickShield,
	S_PickBread,
	S_Win,
	S_GameOver
};

#endif // !CONSTANTES_H
