#ifndef TREASUREHUNTER_H
#define TREASUREHUNTER_H
// TreasureHunter.h
// Fait par Gabriel Bourgeois le 15 mai 2018
// Interface de la classe CTreasureHunter qui repr�sente un jeu

#include "Constantes.h"
#include "Carte.h"
#include "Hero.h"
#include "Brute.h"
#include "Voleur.h"
#include <iostream>
#include <locale> // pour les accents
#include <cstdlib> // pour le rand et le srand
#include <ctime> // pour le time dans le srand
#include <string>
#include <SFML/Audio.hpp>

class CTreasureHunter {
private:
	/* Attributs */

	int GoldLeft_; // Sous restants dans la carte
	bool HeroAlive_; // True si le hero est vivant
	bool Paused_; // True si le jeu est mis en pause
	bool Quit_; // True si le joueur a demander de quitter
	bool TooFewGold_; // True s'il ne reste pas assez de sous pour gagner
	bool Won_; // True si le joueur � gagn�
	sf::RenderWindow* Window_; // Fen�tre pour afficher le jeu
	sf::View* View_; // Vision du jeu 
	sf::Event CurrentEvent_; // Dernier �venemment enregistr�
	CCarte* Map_; // Carte du jeu
	sf::Image MapMask_; // Masque de la carte
	sf::Font GameFont_; // Police utilis� pour les �critures
	sf::RectangleShape* IndicatorsBG_; // Fond pour les indicateurs
	sf::Texture Textures_[TextureNb]; // Tableau de textures pour les objets de la carte
	sf::Sprite Indicators_[IndicatorNb]; // Tableau d'indicateurs � afficher
	sf::Text Texts_[TextNb]; // Tableau de textes � afficher
	CHero* Hero_; // Hero
	CMonstre* Monsters_[MonsterNb]; // Tableau de pointeurs de monstres
	CObjet* Objects_[ObjectNb]; // Tableau de pointeurs d'objets
	sf::Music Music_; // Musique du jeu
	sf::Sound Sound_[SoundNb]; // Son du jeu
	sf::SoundBuffer SoundBuffer_[SoundNb]; // Tableau de tampon de sons (tous les sons du jeu)

	// Bloquer la copie
	CTreasureHunter(const CTreasureHunter&);
	CTreasureHunter& operator=(const CTreasureHunter&);

public:
	/* Constructeurs et destructeurs */

	////////////////////////////////////////////////////////////
	// Constructeur sans param�tre
	////////////////////////////////////////////////////////////
	CTreasureHunter();

	////////////////////////////////////////////////////////////
	// Destructeur
	////////////////////////////////////////////////////////////
	~CTreasureHunter();

	/* Accesseurs */

	int GetGoldLeft()const;
	bool GetHeroAlive()const;
	bool GetPaused()const;
	bool GetQuit()const;
	bool GetTooFewGold()const;
	bool GetWon()const;
	const sf::RenderWindow* GetWindow()const;
	const sf::View* GetView()const;
	const sf::Event& GetCurrentEvent()const;
	const CCarte* GetMap()const;
	const sf::Image& GetMapMask()const;
	const sf::Font& GetGameFont()const;
	const sf::RectangleShape* GetIndicatorsBG()const;
	const sf::Texture* GetTextures()const;
	const sf::Sprite* GetIndicators()const;
	const sf::Text* GetTexts()const;
	const CHero* GetHero()const;
	const CMonstre* GetMonsters()const;
	const CObjet* GetObjects()const;
	const sf::Music& GetMusic()const;
	const sf::Sound* GetSound()const;
	const sf::SoundBuffer* GetSoundBuffer()const;

	/* Mutateurs */

	void SetGoldLeft(int GoldLeft);
	void SetHeroAlive(bool HeroAlive);
	void SetPaused(bool Paused);
	void SetQuit(bool Quit);
	void SetTooFewGold(bool TooFewGold);
	void SetWon(bool Won);
	void SetWindow(sf::RenderWindow* Window);
	void SetView(sf::View* View);
	void SetCurrentEvent(const sf::Event& CurrentEvent);
	void SetMap(CCarte* Map);
	void SetMapMask(const sf::Image& MapMask);
	void SetGameFont(sf::Font GameFont);
	void SetIndicatorsBG(sf::RectangleShape* IndicatorsBG);
	void SetTexture(sf::Texture Texture, Object O);
	void SetTextures(sf::Texture Textures[]);
	void SetIndicator(sf::Sprite Sprite, Indicator I);
	void SetIndicators(sf::Sprite Indicators[]);
	void SetText(sf::Text Text, Indicator I);
	void SetTexts(sf::Text Texts[]);
	void SetHero(CHero* Hero);
	void SetMonster(CMonstre* Monster, int Index);
	void SetMonsters(CMonstre* Monsters[]);
	void SetObject(CObjet* Objet, int Index);
	void SetObjects(CObjet* Object[]);
	void SetMusic(std::string Path); 
	void SetSound(sf::Sound Sound, int Index);
	void SetSound(sf::Sound Sound[]);
	void SetSoundBuffer(sf::SoundBuffer SoundBuffer, int Index);
	void SetSoundBuffer(sf::SoundBuffer SoundBuffer[]);

	/* M�thodes */

	////////////////////////////////////////////////////////////
	// AttackHero
	// V�rifie si chacun des monstres peut attaquer
	// ou voler le h�ro. Si le monstre est assez pr�s du h�ro,
	// il l'attaque/vole et r�duit sa vie/d�fense/fortune selon
	// le type de monstre. Un son est jou� lorsqu'un monstre touche
	// le h�ro selon le type du monstre
	////////////////////////////////////////////////////////////
	void AttackHero();

	////////////////////////////////////////////////////////////
	// Deplacer
	// D�place le h�ro selon la touche appuy�e par le joueur et d�place
	// tous les monstres pour qu'ils se rapprochent du joueur (si possible)
	////////////////////////////////////////////////////////////
	void Deplacer();

	////////////////////////////////////////////////////////////
	// DisplayAll
	// Affiche � la fen�tre la carte, les objets, les monstres, le h�ro, 
	// les indicateurs, les textes, etc. Tout ce qui se doit d'�tre afficher 
	// est affich� � l'aide de cette m�thode.
	////////////////////////////////////////////////////////////
	void DisplayAll();

	////////////////////////////////////////////////////////////
	// DisplayEndMessage
	// Affiche le message de la fin selon si le joueur � gagn�, s'il 
	// est mort ou s'il � perdu � cause qu'il � perdu trop de sous. 
	// Un son est jou� selon le message qui est affich� � la fen�tre
	////////////////////////////////////////////////////////////
	void DisplayEndMessage();

	////////////////////////////////////////////////////////////
	// End
	// G�re la fin de la partie. Arr�te la  musique et appel les m�thodes 
	// DisplayAll et DisplayEndMessage. Attend que le joueur demande de quitter
	// sois en appuyant sur la touche d'echappement ou en cliquant sur
	// le "X" de la fen�tre.
	////////////////////////////////////////////////////////////
	void End();

	////////////////////////////////////////////////////////////
	// GetRandomPos
	// G�n�re une position valide au hasard en se basant sur la 
	// largeur et la hauteur de la carte (MapWidth, MapHeight).
	// La position est v�rifi�e � l'aide de la m�thode "EstPositionValide"
	// de la classe CCarte.
	// Extrant: CPosition (x, y)
	////////////////////////////////////////////////////////////
	CPosition GenRandomPos()const;

	////////////////////////////////////////////////////////////
	// InitAll
	// Apelle toutes les m�thodes d'initialisation et s'assure
	// que tout est bien initialis� (indicateurs, monstres, objets, etc.)
	////////////////////////////////////////////////////////////
	void InitAll();

	////////////////////////////////////////////////////////////
	// InitIndicators
	// Initialise le tableau d'indicateurs. Affecte les textures
	// appropri�s � chacun et g�re l'origine des indicateurs ansi
	// que leur taille (scale). G�re aussi le fond des indicateurs.
	////////////////////////////////////////////////////////////
	void InitIndicators();

	////////////////////////////////////////////////////////////
	// InitMonsters
	// Initialise le tableau de monstre au hasard. Les monstres 
	// cr��s sont soit une brute (CBrute), sois un voleur (CVoleur).
	// Leur position est g�n�r� au hasard par la m�thode "GenRandomPos".
	////////////////////////////////////////////////////////////
	void InitMonsters();

	////////////////////////////////////////////////////////////
	// InitObjects
	// Initialise le tableau d'objets. Les premiers objets
	// cr��s sont des sous. Les autres sont au hasard, sois un bouclier
	// sois un pain.
	// Leur position est g�n�r� au hasard par la m�thode "GenRandomPos".
	////////////////////////////////////////////////////////////
	void InitObjects();

	////////////////////////////////////////////////////////////
	// InitTexts
	// Initialise le tableau de textes et ses caract�ristiques:
	// Police, couleur, taille, style, texte, etc.
	////////////////////////////////////////////////////////////
	void InitTexts();

	////////////////////////////////////////////////////////////
	// KeepPlaying
	// V�rifie s'il y a assez de sous dans la carte pour que le 
	// h�ro puisse gagner et si le h�ro � ramass� assez de sous
	// pour gagner.
	// Extrant: Retourne true quand le joueur n'a pas demand� � quitter, 
	// le h�ro est toujours vivant, le joueur n'a pas gagn�, il reste assez de sous
	// pour gagner et la fen�tre est toujours ouverte
	////////////////////////////////////////////////////////////
	bool KeepPlaying();

	////////////////////////////////////////////////////////////
	// LoadAll
	// Apelle toutes les m�thodes de chargements et s'assure
	// que tout est bien charg� (textures, sons, police, etc.)
	////////////////////////////////////////////////////////////
	void LoadAll();

	////////////////////////////////////////////////////////////
	// LoadGameFont
	// Charge la police utilis�e dans le jeu. Le chemin d'access 
	// est affect� � GameFont_
	////////////////////////////////////////////////////////////
	void LoadGameFont();

	////////////////////////////////////////////////////////////
	// LoadMapMask
	// Charge le masque du monde. Le chemin d'access est affect�
	// � l'image MapMask_
	////////////////////////////////////////////////////////////
	void LoadMapMask();

	////////////////////////////////////////////////////////////
	// LoadMusic
	// Charge la musique du jeu. Le chemin d'access est affect�
	// � Music_;
	////////////////////////////////////////////////////////////
	void LoadMusic();

	////////////////////////////////////////////////////////////
	// LoadSounds
	// Charge tous les sons en m�moire et initialise les tableaux
	// Sound_ et SoundBuffer_. Le chemin d'acces des sons est affect�
	// au tableau SoundBuffer_, qui est lui-m�me affect� au tableau de Sound_.
	////////////////////////////////////////////////////////////
	void LoadSounds();

	////////////////////////////////////////////////////////////
	// LoadTextures
	// Charge toutes les textures en affectant le chemin d'acces
	// des textures au tableau Textures_
	////////////////////////////////////////////////////////////
	void LoadTextures();

	////////////////////////////////////////////////////////////
	// PickObjects
	// V�rifie si chaque objet est ramassable par le 
	// h�ro. Si l'objet est assez pr�s, le hero le ramasse et 
	// ajoute le gain de l'objet � ses caract�ristiques. Un son
	// est jou� selon l'objet ramass�
	////////////////////////////////////////////////////////////
	void PickObjects();

	////////////////////////////////////////////////////////////
	// Play
	// Appel des m�thodes n�c�ssaires au bon fonctionnement du jeu,
	// rafraichit la fenetre et g�rer le temps d'attente entre
	// deux affichages.
	////////////////////////////////////////////////////////////
	void Play();

	////////////////////////////////////////////////////////////
	// SetEvent
	// �coute si un �vennement se produit. Si c'est le cas, l'�venement
	// est affect� � CurrentEvent_. G�re les �venements de fermeture
	// de la fen�tre et de mise en pause du jeu (avec la touche "P")
	// Extrant: Retourne true si le joueur tente de quitter le jeu
	// � l'aide de la touche d'�chappement ou en cliquant manuellement
	// sur le "X" de la fen�tre.
	////////////////////////////////////////////////////////////
	bool SetEvent();
};

////////////////////////////////////////////////////////////
// ObjToStr
// Converti une variable de type "Object" (�num�ration) en 
// objet string selon l'objet.
// Intrant: Variable de type Object (�num�ration)
// Extrant: String qui contient le "nom �quivalent" de l'objet
////////////////////////////////////////////////////////////
std::string ObjToStr(Object O);

////////////////////////////////////////////////////////////
// SndToStr
// Converti une variable de type "GameSound" (�num�ration) en 
// objet string selon le son.
// Intrant: Variable de type GameSound (�num�ration)
// Extrant: String qui contient le "nom �quivalent" du son
////////////////////////////////////////////////////////////
std::string SndToStr(GameSound S);

#endif // !TREASUREHUNTER_H
