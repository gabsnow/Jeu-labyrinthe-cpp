// TreasureHunter.cpp
// Fait par Gabriel Bourgeois le 15 mai 2018
// Implémentation de la classe CTreasureHunter qui représente le jeu

#include "TreasureHunter.h"
#include "Constantes.h"
#include <locale>
#include <ctime>
#include <cstdlib>
#include <SFML\Audio.hpp>

/* Constructeurs et destructeurs */
CTreasureHunter::CTreasureHunter() :
	GoldLeft_(GoldNb), HeroAlive_(true), Paused_(false), Quit_(false), TooFewGold_(false), Won_(false) {
	
	// Permettre les accents à la console
	std::locale::global(std::locale{ "" });

	// Initialisation de srand pour permettre la génération de nombre au hasard
	srand(static_cast<unsigned int>(time(NULL)));

	// Chargement de tous les éléments nécéssaires au jeu
	LoadAll();

	// Initialisation de tous les éléments nécéssaires au jeu
	InitAll();

	// Partir la musique
	Music_.play();
}
CTreasureHunter::~CTreasureHunter() {
	if (View_)
		delete View_;

	for (int i(0); i < ObjectNb; i++)
		if (Objects_[i])
			delete Objects_[i];

	for (int i(0); i < MonsterNb; i++)
		delete Monsters_[i];

	if (IndicatorsBG_)
		delete IndicatorsBG_;

	if (Hero_)
		delete Hero_;

	if (Map_)
		delete Map_;

	Window_->close();

	if (Window_)
		delete Window_;
}

/* Accesseurs */
int CTreasureHunter::GetGoldLeft()const {
	return GoldLeft_;
}
bool CTreasureHunter::GetHeroAlive()const {
	return HeroAlive_;
}
bool CTreasureHunter::GetPaused()const {
	return Paused_;
}
bool CTreasureHunter::GetQuit()const {
	return Quit_;
}
bool CTreasureHunter::GetTooFewGold()const {
	return TooFewGold_;
}
bool CTreasureHunter::GetWon()const {
	return Won_;
}
const sf::RenderWindow* CTreasureHunter::GetWindow()const {
	return Window_;
}
const sf::View* CTreasureHunter::GetView()const {
	return View_;
}
const sf::Event& CTreasureHunter::GetCurrentEvent()const {
	return CurrentEvent_;
}
const CCarte* CTreasureHunter::GetMap()const {
	return Map_;
}
const sf::Image& CTreasureHunter::GetMapMask()const {
	return MapMask_;
}
const sf::Font& CTreasureHunter::GetGameFont()const {
	return GameFont_;
}
const sf::RectangleShape* CTreasureHunter::GetIndicatorsBG()const {
	return IndicatorsBG_;
}
const sf::Texture* CTreasureHunter::GetTextures()const {
	return Textures_;
}
const sf::Sprite* CTreasureHunter::GetIndicators()const {
	return Indicators_;
}
const sf::Text* CTreasureHunter::GetTexts()const {
	return Texts_;
}
const CHero* CTreasureHunter::GetHero()const {
	return Hero_;
}
const CMonstre* CTreasureHunter::GetMonsters()const {
	return Monsters_[0];
}
const CObjet* CTreasureHunter::GetObjects()const {
	return Objects_[0];
}
const sf::Music& CTreasureHunter::GetMusic()const {
	return Music_;
}
const sf::Sound* CTreasureHunter::GetSound()const {
	return Sound_;
}
const sf::SoundBuffer* CTreasureHunter::GetSoundBuffer()const {
	return SoundBuffer_;
}

/* Mutateurs */
void CTreasureHunter::SetGoldLeft(int GoldLeft) {
	GoldLeft_ = GoldLeft;
}
void CTreasureHunter::SetHeroAlive(bool HeroAlive) {
	HeroAlive_ = HeroAlive;
}
void CTreasureHunter::SetPaused(bool Paused) {
	Paused_ = Paused;
	if (GetPaused())
		Music_.pause();
	else
		Music_.play();
}
void CTreasureHunter::SetQuit(bool Quit) {
	Quit_ = Quit;
}
void CTreasureHunter::SetTooFewGold(bool TooFewGold) {
	TooFewGold_ = TooFewGold;
}
void CTreasureHunter::SetWon(bool Won) {
	Won_ = Won;
}
void CTreasureHunter::SetWindow(sf::RenderWindow* Window) {
	if (Window) {
		if (Window_)
			delete Window_;
		Window_ = Window;

		if (View_)
			delete View_;
		SetView(new sf::View(Window_->getView()));
	}
	else
		throw std::string("Erreur lors de l'affectation de la fenetre. Classe: CTreasureHunter. Méthode: SetWindow(sf::RenderWindow* Window).");
}
void CTreasureHunter::SetView(sf::View* View) {
	if (View) {
		if (View_)
			delete View_;
		View_ = View;
	}
	else
		throw std::string("Erreur lors de l'affectation de la vision. Classe: CTreasureHunter. Méthode: SetView(sf::View* View).");

}
void CTreasureHunter::SetCurrentEvent(const sf::Event& CurrentEvent) {
	CurrentEvent_ = CurrentEvent;
}
void CTreasureHunter::SetMap(CCarte* Map) {
	if (Map) {
		if (Map_)
			delete Map_;
		Map_ = Map;
	}
	else
		throw std::string("Erreur lors de l'affectation de la carte. Classe: CTreasureHunter. Méthode: SetMap(CCarte* Map).");
}
void CTreasureHunter::SetMapMask(const sf::Image& MapMask) {
	MapMask_ = MapMask;
}
void CTreasureHunter::SetGameFont(sf::Font GameFont) {
	GameFont_ = GameFont;
}
void CTreasureHunter::SetIndicatorsBG(sf::RectangleShape* IndicatorsBG) {
	if (IndicatorsBG) {
		if (IndicatorsBG_)
			delete IndicatorsBG_;
		IndicatorsBG_ = IndicatorsBG;
	}
	else
		throw std::string("Erreur lors de l'affectation du fond pour les indicateurs. Classe: CTreasureHunter. Méthode: SetIndicatorsBG(sf::RectangleShape* IndicatorsBG).");
}
void CTreasureHunter::SetTexture(sf::Texture Texture, Object O) {
	Textures_[O] = Texture;
}
void CTreasureHunter::SetTextures(sf::Texture Textures[]) {
	for (int i(0); i < TextureNb; i++)
		SetTexture(Textures[i], static_cast<Object>(i));
}
void CTreasureHunter::SetIndicator(sf::Sprite Sprite, Indicator I) {
	Indicators_[I] = Sprite;
}
void CTreasureHunter::SetIndicators(sf::Sprite Indicators[]) {
	for (int i(0); i < IndicatorNb; i++)
		SetIndicator(Indicators[i], static_cast<Indicator>(i));
}
void CTreasureHunter::SetText(sf::Text Text, Indicator I) {
	Texts_[I] = Text;
}
void CTreasureHunter::SetTexts(sf::Text Texts[]) {
	for (int i(0); i < TextNb; i++)
		SetText(Texts[i], static_cast<Indicator>(i));
}
void CTreasureHunter::SetHero(CHero* Hero) {
	if (Hero) {
		if (Hero_)
			delete Hero_;
		Hero_ = Hero;
	}
	else
		throw std::string("Erreur lors de l'affectation du hero. Classe: CTreasureHunter. Méthode: SetHero(CHero* Hero).");
}
void CTreasureHunter::SetMonster(CMonstre* Monster, int Index) {
	if (Monster) {
		if (Monsters_[Index])
			delete Monsters_[Index];
		Monsters_[Index] = Monster;
	}
	else
		throw std::string("Erreur lors de l'affectation d'un monstre. Classe: CTreasureHunter. Méthode: SetMonsters(CMonstre* Monster, int Index).");

}
void CTreasureHunter::SetMonsters(CMonstre* Monsters[]) {
	for (int i(0); i < MonsterNb; i++)
		SetMonster(Monsters[i], i);
}
void CTreasureHunter::SetObject(CObjet* Objet, int Index) {
	if (Objet) {
		if (Objects_[Index])
			delete Objects_[Index];
		Objects_[Index] = Objet;
	}
	else
		throw std::string("Erreur lors de l'affectation d'un objet. Classe: CTreasureHunter. Méthode: SetObject(CObject* Object, int Index).");
}
void CTreasureHunter::SetObjects(CObjet* Object[]) {
	for (int i(0); i < ObjectNb; i++)
		SetObject(Object[i], i);
}
void CTreasureHunter::SetMusic(std::string Path) {
	if (!Music_.openFromFile(Path))
		throw std::string("Erreur lors de l'affectation de la musique. Classe: CTreasureHunter. Méthode: SetMusic(std::string Path).");
}
void CTreasureHunter::SetSound(sf::Sound Sound, int Index) {
	Sound_[Index] = Sound;
}
void CTreasureHunter::SetSound(sf::Sound Sound[]) {
	for (int i(0); i < SoundNb; i++)
		SetSound(Sound[i], i);
}
void CTreasureHunter::SetSoundBuffer(sf::SoundBuffer SoundBuffer, int Index) {
	SoundBuffer_[Index] = SoundBuffer;
}
void CTreasureHunter::SetSoundBuffer(sf::SoundBuffer SoundBuffer[]) {
	for (int i(0); i < SoundNb; i++)
		SetSoundBuffer(SoundBuffer[i], i);
}

/* Méthodes */
void CTreasureHunter::AttackHero() {
	if (!GetPaused()) {
		// Tous les monstres essaient d'attaquer le héros
		for (int i(0); i < MonsterNb; i++)
			if (GetHeroAlive()) {
				SetHeroAlive(Monsters_[i]->Attaquer(*Hero_));

				if (PositionsProches(Hero_->getPosition(), Monsters_[i]->getPosition())) {
					if (Monsters_[i]->GetNom() == "Brute")
						Sound_[S_Punch].play();
					else if (Monsters_[i]->GetNom() == "Voleur")
						Sound_[S_Whip].play();
				}
			}
	}
}
void CTreasureHunter::Deplacer() {
	if (!GetPaused()) {
		// Déplacer le héros et déterminer si le joueur a demandé de quitter le jeu
		SetQuit(Hero_->Deplacer(*Map_, Hero_->getPosition()));

		// Déplacer tous les monstres
		for (int i(0); i < MonsterNb; i++)
			Monsters_[i]->Deplacer(*Map_, Hero_->getPosition());
	}
}
void CTreasureHunter::DisplayAll() {
	/* Affichage */
	// Fenêtre
	// View Vue = Fenetre.getView(); // VOIR SI ON A BESOIN DE SA DANS UNE BOUCLE ?
	View_->setCenter(Hero_->getPosition());
	Window_->setView(*View_);

	// Afficher la carte
	Map_->Afficher(*Window_);

	// Afficher tous les objets
	for (int i(0); i < ObjectNb; i++)
		if (Objects_[i])
			Objects_[i]->Afficher(*Window_);

	// Afficher tous les monstres
	for (int i(0); i < MonsterNb; i++)
		Monsters_[i]->Afficher(*Window_);

	// Afficher le héros
	if (GetHeroAlive())
		Hero_->Afficher(*Window_);

	/* Afficher les indicateurs */

	int HerosX(static_cast<int>(Hero_->getPosition().x)), HerosY(static_cast<int>(Hero_->getPosition().y));

	// Position du rectangle noir
	IndicatorsBG_->setPosition(static_cast<float>(HerosX - WindowWidth / 2.0f), static_cast<float>(HerosY + WindowHeight / 2.0f - 50));

	// Position du coeur et du texte
	Indicators_[I_Heart].setPosition(static_cast<float>(HerosX - (WindowWidth / 2.0f - 50)), static_cast<float>(HerosY + (WindowHeight / 2.0f + 25)));
	Texts_[I_Heart].setString(std::to_string(Hero_->GetVitalite()));
	Texts_[I_Heart].setPosition(Indicators_[I_Heart].getPosition().x + 50, Indicators_[I_Heart].getPosition().y - 75);

	// Position du bouclier et du texte
	Indicators_[I_Shield].setPosition(static_cast<float>(HerosX - (WindowWidth / 2.0f - 450)), static_cast<float>(HerosY + (WindowHeight / 2.0f + 25)));
	Texts_[I_Shield].setString(std::to_string(Hero_->GetDefense()));
	Texts_[I_Shield].setPosition(Indicators_[I_Shield].getPosition().x + 50, Indicators_[I_Shield].getPosition().y - 75);

	// Position de la fortune et du texte
	Indicators_[I_Gold].setPosition(static_cast<float>(HerosX - (WindowWidth / 2.0f - 850)), static_cast<float>(HerosY + (WindowHeight / 2.0f + 25)));
	Texts_[I_Gold].setString(std::to_string(Hero_->GetFortune()));
	Texts_[I_Gold].setPosition(Indicators_[I_Gold].getPosition().x + 50, Indicators_[I_Gold].getPosition().y - 75);


	// Afficher les indicateurs à la fenetre
	Window_->draw(*IndicatorsBG_);
	for (int i(0); i < IndicatorNb; i++) {
		Window_->draw(Indicators_[i]);
		Window_->draw(Texts_[i]);
	}

	// Afficher "Pause"
	if (GetPaused()) {
		Texts_[I_Pause].setPosition(HerosX - (Texts_[I_Pause].getGlobalBounds().width / 2), HerosY - (Texts_[I_Pause].getGlobalBounds().height));
		Window_->draw(Texts_[I_Pause]);
	}
}
void CTreasureHunter::DisplayEndMessage() {
	// Si le joueur a gagné
	if (GetWon()) {
		Sound_[S_Win].play();
		std::cout << "Tu as gagné!" << std::endl;
		Texts_[I_End].setCharacterSize(PauseCharSize);
		Texts_[I_End].setString("Gagné!");
	}
	// Si le joueur a perdu
	else {
		Sound_[S_GameOver].play();
		Texts_[I_End].setCharacterSize(PauseCharSize / 2);
		// Si le joueur est mort
		if (!GetHeroAlive()) {
			std::cout << "Tu es mort!" << std::endl;
			Texts_[I_End].setString("Tu es mort!");
		}
		// S'il n'y avait plus assez de sous pour gagner
		else if (GetTooFewGold()) {
			std::cout << "Tu as perdu, il n'y avait plus assez de sous pour gagner!" << std::endl;
			Texts_[I_End].setString("Tu as perdu!");
		}
	}
	Texts_[I_End].setPosition(Hero_->getPosition().x - (Texts_[I_Pause].getGlobalBounds().width / 2), Hero_->getPosition().y - (Texts_[I_Pause].getGlobalBounds().height));
	Window_->draw(Texts_[I_End]);
	Window_->display();
}
void CTreasureHunter::End() {
	Music_.stop();
	DisplayAll();
	DisplayEndMessage();
	while (!SetEvent());
}
CPosition CTreasureHunter::GenRandomPos()const {
	float TempX(0.0f), TempY(0.0f);
	do {
		TempX = static_cast<float>(rand() % MapWidth);
		TempY = static_cast<float>(rand() % MapHeight);
	} while (!Map_->EstPositionValide(CPosition(TempX, TempY)));

	return CPosition(TempX, TempY);
}
void CTreasureHunter::InitAll() {
	// Initialisation de la fenêtre, du monde et du hero
	SetWindow(new sf::RenderWindow(sf::VideoMode(WindowWidth, WindowHeight + IndicatorBGHeight), "Treasure Hunter"));
	SetMap(new CCarte(Textures_[O_Map], MapMask_));
	SetHero(new CHero(Textures_[O_Hero], CPosition(1000, 1000), "San Goku", 10, 10));

	// Initialisation des indicateurs
	InitIndicators();
	// Initialisation des monstres
	InitMonsters();
	// Initialisation des objets
	InitObjects();
	// Initialisation des textes
	InitTexts();
}
void CTreasureHunter::InitIndicators() {
	// Affectation des textures aux indicateurs
	Indicators_[I_Heart].setTexture(Textures_[O_Hearts]);
	Indicators_[I_Shield].setTexture(Textures_[O_Shield]);
	Indicators_[I_Gold].setTexture(Textures_[O_Gold]);

	// Mise à l'origine des indicateurs et mise à l'échelle (x3)
	for (int i(0); i < IndicatorNb; i++) {
		Indicators_[i].setOrigin(Indicators_[i].getGlobalBounds().width / 2.0f, Indicators_[i].getGlobalBounds().height);
		Indicators_[i].setScale(3.0f, 3.0f);
	}

	// Création d'un fond qui fait la largeur de l'affichage pour afficher les indicateurs
	SetIndicatorsBG(new sf::RectangleShape(sf::Vector2f(static_cast<float>(IndicatorBGWidth), static_cast<float>(IndicatorBGHeight))));
	IndicatorsBG_->setFillColor(sf::Color::Black); // Affectation de la couleur noir pour le fond
}
void CTreasureHunter::InitMonsters() {
	// Initialisation du tableau de Monstres
	// Choisir entre une Brute et un Voleur au hasard pour chaque Monstre
	// Le placer à une position VALIDE aléatoire dans le monde.
	for (int i(0); i < MonsterNb; i++)
		if (rand() % 2 == 0)
			// On fait une brute
			SetMonster(new CBrute(Textures_[O_Brute], GenRandomPos(), "Brute"), i);
		else
			// On fait un voleur
			SetMonster(new CVoleur(Textures_[O_Thief], GenRandomPos(), "Voleur"), i);
}
void CTreasureHunter::InitObjects() {
	// Initialisation des sous (le nombre de sous est déterminé par la constante NbSous
	// et les sous sont placés en premier dans le tableau d'objets)
	// Choisir une position aléatoire VALIDE pour chaque sou dans le monde.
	for (int i(0); i < GoldNb; i++)
		SetObject(new CObjet(Textures_[O_Gold], GenRandomPos(), "Gold", 0, 1, 0), i);

	// Initialisation des autres objets dans le tableau d'objets
	// Pour chacun d'eux, choisir au hasard entre un pain et un bouclier
	// Leur choisir une position aléatoire VALIDE dans le monde.
	for (int i(OtherObjetNb); i < ObjectNb; i++)
		SetObject( rand() % 2 == 0 ?
			new CObjet(Textures_[O_Shield], GenRandomPos(), "Shield", 0, 0, 1) : // On fait un bouclier
			new CObjet(Textures_[O_Bread], GenRandomPos(), "Bread", 1, 0, 0), i); // On fait un pain
}
void CTreasureHunter::InitTexts() {
	// Initialisation des caractéristiques du texte pour les indicateurs et les messages
	for (int i(0); i < TextNb; i++) {
		Texts_[i].setFont(GetGameFont()); // Affectation de la police aux textes
		Texts_[i].setCharacterSize(IndicatorCharSize); // Affectation de la taille de la police aux textes
		Texts_[i].setStyle(sf::Text::Bold); // Affectation du style "gras" aux textes
	}
	Texts_[I_Heart].setFillColor(sf::Color::Red); // Affectation de la couleur de l'indice de l'indicateur de vie
	Texts_[I_Shield].setFillColor(sf::Color::Green); // Affectation de la couleur de l'indice de l'indicateur de bouclier
	Texts_[I_Gold].setFillColor(sf::Color::Yellow); // Affectation de la couleur de l'indice de l'indicateur de fortune

	Texts_[I_Pause].setString("Pause"); // Affectation du message pour "pause"
	Texts_[I_Pause].setCharacterSize(PauseCharSize); // Affectation de la taille du "pause"
	Texts_[I_Pause].setFillColor(sf::Color::Red); // Affectation de la couleur du "pause"

	Texts_[I_End].setCharacterSize(PauseCharSize); // Affectation de la taille du message de fin
	Texts_[I_End].setFillColor(sf::Color::Red); // Affectation de la couleur du message de fin
}
bool CTreasureHunter::KeepPlaying() {
	SetTooFewGold(GetGoldLeft() + Hero_->GetFortune() < GoldToWin);
	SetWon(Hero_->GetFortune() >= GoldToWin);

	return !GetQuit() && !GetTooFewGold() && !GetWon() && GetHeroAlive() && GetWindow()->isOpen();
}
void CTreasureHunter::LoadAll() {
	// Chargement des textures
	LoadTextures();
	// Chargement du masque de la carte
	LoadMapMask();
	// Chargement de la musique
	LoadMusic();
	// Chargement des sons du jeu
	LoadSounds();
	// Chargement de la police du jeu
	LoadGameFont();
}
void CTreasureHunter::LoadGameFont() {
	// Chargement de la police
	if (!GameFont_.loadFromFile("Fonts/Shortcut.TTF"))
		throw std::string("Erreur lors du chargement de la police. Classe: CTreasureHunter. Méthode: Constructeur.");
}
void CTreasureHunter::LoadMapMask() {
	if (!MapMask_.loadFromFile("res\\MasqueDuMonde.png"))
		throw std::string("Erreur lors du chargement du masque de la carte. Classe: CTreasureHunter. Méthode: LoadMapMask.");
}
void CTreasureHunter::LoadMusic() {
	// Charge la musique
	SetMusic("Music\\Gotti.ogg");
	Music_.setLoop(true);
}
void CTreasureHunter::LoadSounds() {
	for (int i(0); i < SoundNb; i++) {
		if(!SoundBuffer_[i].loadFromFile("Sound/" + SndToStr(static_cast<GameSound>(i)) + ".wav"))
			throw std::string("Erreur lors du chargement d'un son. Classe: CTreasureHunter. Méthode: LoadSounds.");

		Sound_[i].setBuffer(SoundBuffer_[i]);
	}
}
void CTreasureHunter::LoadTextures() {
	for (int i(0); i < TextureNb; i++) {
		if (!Textures_[i].loadFromFile("res\\" + ObjToStr(static_cast<Object>(i)) + ".png"))
			throw std::string("Erreur lors du chargement d'une texture. Classe: CTreasureHunter. Méthode: LoadTextures.");
	}
}
void CTreasureHunter::PickObjects() {
	if (!GetPaused()) {
		// Le héros essaie de prendre tous les objets
		// S'il arrive à prendre un sou : afficher le nombre de sous restant dans le monde
		for (int i(0); i < ObjectNb; i++)
			if (Objects_[i]) {
				if (!Hero_->Prendre(*Objects_[i])) {
					if (Objects_[i]->GetNom() == "Gold") {
						Sound_[S_PickCoin].play();
						SetGoldLeft(GetGoldLeft() - 1);
						std::cout << "Nombre de sous restants dans le monde: " << GetGoldLeft() << std::endl << std::endl;
					}
					else if (Objects_[i]->GetNom() == "Shield")
						Sound_[S_PickShield].play();
					else if (Objects_[i]->GetNom() == "Bread")
						Sound_[S_PickBread].play();

					delete Objects_[i];
					Objects_[i] = nullptr;
				}
			}
	}
}
void CTreasureHunter::Play() {
	// Vérification des événements
	SetEvent();
	if (KeepPlaying()) {
		Deplacer();
		PickObjects();
		AttackHero();
		DisplayAll();

		// Rafraichir la fenêtre
		if (KeepPlaying())
			Window_->display();

		// Attendre 30 millisecondes pour ralentir le jeu
		sf::sleep(sf::milliseconds(SleepTime));
	}
}
bool CTreasureHunter::SetEvent() {

	while (Window_->pollEvent(CurrentEvent_) && !GetQuit()) {
		switch (CurrentEvent_.type) {
		case sf::Event::Closed: // Si l'on veut fermer la fenêtre
			SetQuit(true);
			Window_->close();
			break;
		case sf::Event::KeyPressed:
			switch (CurrentEvent_.key.code) {
			case sf::Keyboard::Escape: // Si l'on appui sur la touche d'échappement
				SetQuit(true);
				Window_->close();
				break;
			case sf::Keyboard::P: // Si l'on appui sur la touche "P" pour toggle pause
				SetPaused(!GetPaused());
				if (GetPaused())
					std::cout << "*** JEU MIS EN PAUSE ***" << std::endl << std::endl;
				else
					std::cout << "*** PAUSE TERMINÉE ***" << std::endl << std::endl;
				break;
			}
			break;
		}
	}

	return GetQuit();
}

/* Fonctions */
std::string ObjToStr(Object O) {
	std::string Value("");

	switch (O) {
	case O_Map:
		Value = "lemonde";
		break;
	case O_Hero:
		Value = "Heros";
		break;
	case O_Brute:
		Value = "Brute";
		break;
	case O_Thief:
		Value = "voleur";
		break;
	case O_Bread:
		Value = "pain";
		break;
	case O_Shield:
		Value = "bouclier";
		break;
	case O_Gold:
		Value = "sou";
		break;
	case O_Hearts:
		Value = "coeur";
		break;
	default:
		Value = "Undefined";
	}

	return Value;
}
std::string SndToStr(GameSound S) {
	std::string Value("");

	switch (S) {
	case S_Punch:
		Value = "Punch";
		break;
	case S_Whip:
		Value = "Whip";
		break;
	case S_PickCoin:
		Value = "PickCoin";
		break;
	case S_PickShield:
		Value = "Thud";
		break;
	case S_PickBread:
		Value = "Bite";
		break;
	case S_Win:
		Value = "Win";
		break;
	case S_GameOver:
		Value = "Gameover";
		break;
	default:
		Value = "Undefined";
		break;
	}

	return Value;
}