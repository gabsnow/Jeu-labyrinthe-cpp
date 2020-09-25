#ifndef TREASUREHUNTER_H
#define TREASUREHUNTER_H
// TreasureHunter.h
// Fait par Gabriel Bourgeois le 15 mai 2018
// Interface de la classe CTreasureHunter qui représente un jeu

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
	bool Won_; // True si le joueur à gagné
	sf::RenderWindow* Window_; // Fenêtre pour afficher le jeu
	sf::View* View_; // Vision du jeu 
	sf::Event CurrentEvent_; // Dernier évenemment enregistré
	CCarte* Map_; // Carte du jeu
	sf::Image MapMask_; // Masque de la carte
	sf::Font GameFont_; // Police utilisé pour les écritures
	sf::RectangleShape* IndicatorsBG_; // Fond pour les indicateurs
	sf::Texture Textures_[TextureNb]; // Tableau de textures pour les objets de la carte
	sf::Sprite Indicators_[IndicatorNb]; // Tableau d'indicateurs à afficher
	sf::Text Texts_[TextNb]; // Tableau de textes à afficher
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
	// Constructeur sans paramètre
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

	/* Méthodes */

	////////////////////////////////////////////////////////////
	// AttackHero
	// Vérifie si chacun des monstres peut attaquer
	// ou voler le héro. Si le monstre est assez près du héro,
	// il l'attaque/vole et réduit sa vie/défense/fortune selon
	// le type de monstre. Un son est joué lorsqu'un monstre touche
	// le héro selon le type du monstre
	////////////////////////////////////////////////////////////
	void AttackHero();

	////////////////////////////////////////////////////////////
	// Deplacer
	// Déplace le héro selon la touche appuyée par le joueur et déplace
	// tous les monstres pour qu'ils se rapprochent du joueur (si possible)
	////////////////////////////////////////////////////////////
	void Deplacer();

	////////////////////////////////////////////////////////////
	// DisplayAll
	// Affiche à la fenêtre la carte, les objets, les monstres, le héro, 
	// les indicateurs, les textes, etc. Tout ce qui se doit d'être afficher 
	// est affiché à l'aide de cette méthode.
	////////////////////////////////////////////////////////////
	void DisplayAll();

	////////////////////////////////////////////////////////////
	// DisplayEndMessage
	// Affiche le message de la fin selon si le joueur à gagné, s'il 
	// est mort ou s'il à perdu à cause qu'il à perdu trop de sous. 
	// Un son est joué selon le message qui est affiché à la fenêtre
	////////////////////////////////////////////////////////////
	void DisplayEndMessage();

	////////////////////////////////////////////////////////////
	// End
	// Gère la fin de la partie. Arrête la  musique et appel les méthodes 
	// DisplayAll et DisplayEndMessage. Attend que le joueur demande de quitter
	// sois en appuyant sur la touche d'echappement ou en cliquant sur
	// le "X" de la fenêtre.
	////////////////////////////////////////////////////////////
	void End();

	////////////////////////////////////////////////////////////
	// GetRandomPos
	// Génère une position valide au hasard en se basant sur la 
	// largeur et la hauteur de la carte (MapWidth, MapHeight).
	// La position est vérifiée à l'aide de la méthode "EstPositionValide"
	// de la classe CCarte.
	// Extrant: CPosition (x, y)
	////////////////////////////////////////////////////////////
	CPosition GenRandomPos()const;

	////////////////////////////////////////////////////////////
	// InitAll
	// Apelle toutes les méthodes d'initialisation et s'assure
	// que tout est bien initialisé (indicateurs, monstres, objets, etc.)
	////////////////////////////////////////////////////////////
	void InitAll();

	////////////////////////////////////////////////////////////
	// InitIndicators
	// Initialise le tableau d'indicateurs. Affecte les textures
	// appropriés à chacun et gère l'origine des indicateurs ansi
	// que leur taille (scale). Gère aussi le fond des indicateurs.
	////////////////////////////////////////////////////////////
	void InitIndicators();

	////////////////////////////////////////////////////////////
	// InitMonsters
	// Initialise le tableau de monstre au hasard. Les monstres 
	// créés sont soit une brute (CBrute), sois un voleur (CVoleur).
	// Leur position est généré au hasard par la méthode "GenRandomPos".
	////////////////////////////////////////////////////////////
	void InitMonsters();

	////////////////////////////////////////////////////////////
	// InitObjects
	// Initialise le tableau d'objets. Les premiers objets
	// créés sont des sous. Les autres sont au hasard, sois un bouclier
	// sois un pain.
	// Leur position est généré au hasard par la méthode "GenRandomPos".
	////////////////////////////////////////////////////////////
	void InitObjects();

	////////////////////////////////////////////////////////////
	// InitTexts
	// Initialise le tableau de textes et ses caractéristiques:
	// Police, couleur, taille, style, texte, etc.
	////////////////////////////////////////////////////////////
	void InitTexts();

	////////////////////////////////////////////////////////////
	// KeepPlaying
	// Vérifie s'il y a assez de sous dans la carte pour que le 
	// héro puisse gagner et si le héro à ramassé assez de sous
	// pour gagner.
	// Extrant: Retourne true quand le joueur n'a pas demandé à quitter, 
	// le héro est toujours vivant, le joueur n'a pas gagné, il reste assez de sous
	// pour gagner et la fenêtre est toujours ouverte
	////////////////////////////////////////////////////////////
	bool KeepPlaying();

	////////////////////////////////////////////////////////////
	// LoadAll
	// Apelle toutes les méthodes de chargements et s'assure
	// que tout est bien chargé (textures, sons, police, etc.)
	////////////////////////////////////////////////////////////
	void LoadAll();

	////////////////////////////////////////////////////////////
	// LoadGameFont
	// Charge la police utilisée dans le jeu. Le chemin d'access 
	// est affecté à GameFont_
	////////////////////////////////////////////////////////////
	void LoadGameFont();

	////////////////////////////////////////////////////////////
	// LoadMapMask
	// Charge le masque du monde. Le chemin d'access est affecté
	// à l'image MapMask_
	////////////////////////////////////////////////////////////
	void LoadMapMask();

	////////////////////////////////////////////////////////////
	// LoadMusic
	// Charge la musique du jeu. Le chemin d'access est affecté
	// à Music_;
	////////////////////////////////////////////////////////////
	void LoadMusic();

	////////////////////////////////////////////////////////////
	// LoadSounds
	// Charge tous les sons en mémoire et initialise les tableaux
	// Sound_ et SoundBuffer_. Le chemin d'acces des sons est affecté
	// au tableau SoundBuffer_, qui est lui-même affecté au tableau de Sound_.
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
	// Vérifie si chaque objet est ramassable par le 
	// héro. Si l'objet est assez près, le hero le ramasse et 
	// ajoute le gain de l'objet à ses caractéristiques. Un son
	// est joué selon l'objet ramassé
	////////////////////////////////////////////////////////////
	void PickObjects();

	////////////////////////////////////////////////////////////
	// Play
	// Appel des méthodes nécéssaires au bon fonctionnement du jeu,
	// rafraichit la fenetre et gérer le temps d'attente entre
	// deux affichages.
	////////////////////////////////////////////////////////////
	void Play();

	////////////////////////////////////////////////////////////
	// SetEvent
	// Écoute si un évennement se produit. Si c'est le cas, l'évenement
	// est affecté à CurrentEvent_. Gère les évenements de fermeture
	// de la fenêtre et de mise en pause du jeu (avec la touche "P")
	// Extrant: Retourne true si le joueur tente de quitter le jeu
	// à l'aide de la touche d'échappement ou en cliquant manuellement
	// sur le "X" de la fenêtre.
	////////////////////////////////////////////////////////////
	bool SetEvent();
};

////////////////////////////////////////////////////////////
// ObjToStr
// Converti une variable de type "Object" (énumération) en 
// objet string selon l'objet.
// Intrant: Variable de type Object (énumération)
// Extrant: String qui contient le "nom équivalent" de l'objet
////////////////////////////////////////////////////////////
std::string ObjToStr(Object O);

////////////////////////////////////////////////////////////
// SndToStr
// Converti une variable de type "GameSound" (énumération) en 
// objet string selon le son.
// Intrant: Variable de type GameSound (énumération)
// Extrant: String qui contient le "nom équivalent" du son
////////////////////////////////////////////////////////////
std::string SndToStr(GameSound S);

#endif // !TREASUREHUNTER_H
