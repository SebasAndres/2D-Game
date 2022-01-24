#include <iostream>
#include "Game.h"
#define NOMINMAX
#include <windows.h>
#include "gameDict.h"

#define MAX_JOYSTICK_CONNECTED 1

#define forn(MX) for (int w=1; w<MX; ++w)

sf::Color billboardColor = sf::Color::Black; sf::Font billFont;
sf::Music Music;

#define nTicksTransition 30
const int tSleep = 60; int Ox, Oy = -0.77;

void Game::initVariables() {
	this->Window = nullptr;
	this->_MENU_ = MENU(this->wndWidth, this->wndHeight);
	this->_BROOM_ = BedroomStage(this->wndWidth, this->wndHeight);
	billFont.loadFromFile("Fonts/stocky.ttf");
	srand((unsigned int)time(NULL));
	playMusic(this->pathMusic[(int)rand() % this->nMusic], true);
	this->currentScreen = _MENU_.env;
	if (activeJoysticks()) { currentScreen.player.usingJoystick(); }
	else { std::cout << "No joystick active" << std::endl; }
}

void Game::playMusic(std::string path, bool verb) {
	Music.openFromFile(path);
	Music.setVolume(this->MUSIC_VOLUME); Music.play();
	if (verb) {
		std::string music_title; for (int j=12; j < path.size()-4; j++) { music_title += path[j]; }
		Billboard mBillboard = Billboard(music_title, billboardColor, "Fonts/LibreBaskerville-Regular.ttf", 
										this->wndWidth*0.4, this->wndHeight*0.06, 
										this->wndWidth*0.59, this->wndHeight*0.92
										);
		_MENU_.env.billboards.push_back(mBillboard);
	}
	this->currentScreen = _MENU_.env;
}

void Game::initWindow() {
	this->videoMode = sf::VideoMode(this->wndWidth, this->wndHeight);
	this->Window = new sf::RenderWindow(this->videoMode, gameName, sf::Style::Titlebar);
}

void Game::manageKeyPressed(int Key) {

	if (compare(this->currentScreen.envName, _MENU_.env.envName)) {
		if (Key == sf::Keyboard::Enter) { Exe(currentScreen.Selected); }
		else if (Key == sf::Keyboard::Up) {
			this->currentScreen.buttons.at(0).changeToSecondColor();
			this->currentScreen.buttons.at(1).changeToFirstColor();
			this->currentScreen.Selected = "menu_start_button";
		} 
		else if (Key == sf::Keyboard::Down) {
			this->currentScreen.buttons.at(1).changeToSecondColor();
			this->currentScreen.buttons.at(0).changeToFirstColor();
			this->currentScreen.Selected = "option";
		}
		else {}
	}

	if (Key == sf::Keyboard::Escape) { Exe("options"+currentScreen.envName); }

	else if (compare(this->currentScreen.envName, _BROOM_.env.envName)) {
		if (Key == sf::Keyboard::A || Key == sf::Keyboard::Left) {
			currentScreen.player.move("left");
		}
		else if (Key == sf::Keyboard::S || Key == sf::Keyboard::Down) {
			currentScreen.player.move("down");
		}
		else if (Key == sf::Keyboard::D || Key == sf::Keyboard::Right) { 
			currentScreen.player.move("right");
		}
		else if (Key == sf::Keyboard::W || Key == sf::Keyboard::Up) { 
			currentScreen.player.move("front");
		}
	}
}

void Game::manageMouseMovement(int x, int y) {
	int C = 0;
	for (Button bt : this->currentScreen.buttons) {
		if (x >= bt.xPosition & x <= bt.xPosition + bt.width &
			y >= bt.yPosition & y <= bt.yPosition + bt.height)
		{ // Change fillColor of button to "selected"
			this->currentScreen.buttons.at(C).changeToSecondColor();
		} // Return to normal color
		else { this->currentScreen.buttons.at(C).changeToFirstColor(); }
		C++;
	}
}

bool Game::compare(std::string s1, std::string s2) {
	bool equal = true;
	if (s1.size() == s2.size()) {
		for (int w = 0; w < s1.size(); w++) {
			if (s1[w] != s2[w]) { equal = false; }
		}
	}
	else { equal = false; }
	return equal;
}

void Game::Exe(std::string f) {
	
	std::string cleanf; 
	if (f.size() >= 6){
		for (int y = 0; y < 6; ++y) { cleanf += f[y]; }
	}

	if (compare(f, "menu_start_button")) {
		// Soft transition w/ black screen
		int oVolume = this->MUSIC_VOLUME;
		for (int t = 0; t < nTicksTransition; t++) {
			this->MUSIC_VOLUME -= oVolume/nTicksTransition; Music.setVolume(this->MUSIC_VOLUME); Sleep(tSleep);
		}
		Music.stop();
		this->currentScreen = _BROOM_.env;
	}
	else if (compare(cleanf, "option")) { // Add / Delete to Menu Env. Box with option
		currentScreen.Options(this->wndWidth, this->wndHeight); 
	}

	std::cout << "cleanf: " << cleanf << std::endl;
}

void Game::manageMouseClicked(sf::Event::MouseButtonEvent mData) {
	if (mData.button == 0) { // Left click
		for (Button bt : this->currentScreen.buttons) {
			int x = mData.x; int y = mData.y;
			if (x >= bt.xPosition & x <= bt.xPosition + bt.width &
				y >= bt.yPosition & y <= bt.yPosition + bt.height)
			{ Exe(bt.function); }
		}
	}
	else { ; }
}

void Game::eventPolling() {
	while (this->Window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed: this->Window->close(); break;
		case sf::Event::KeyPressed: manageKeyPressed(event.key.code); break;
		case sf::Event::MouseMoved: manageMouseMovement(event.mouseMove.x, event.mouseMove.y);
		case sf::Event::MouseButtonPressed: manageMouseClicked(event.mouseButton);
		}
	}
	forn(31) { if (sf::Joystick::isButtonPressed(0, w)) { manageButtonPressed(w); } }
	float dx = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float dy = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
	if (currentScreen.envName != _MENU_.env.envName){
		currentScreen.player.jMove(dx, dy, Ox, Oy); Ox = dx; Oy = dy;
	}
}

void Game::manageButtonPressed(int jButton) { // Only joystick
	std::string cmd = gameDict().dictAt(jButton);
	if (cmd.size() > 0) {
		if (cmd == "joystick_up") {
			if (compare(currentScreen.envName, _MENU_.env.envName)) {
				this->currentScreen.buttons.at(0).changeToSecondColor();
				this->currentScreen.buttons.at(1).changeToFirstColor();
				this->currentScreen.Selected = "menu_start_button";
			}
			else { // 2. Move character up
				this->currentScreen.player.move("front");
			}
		}
		else if (cmd == "joystick_down") {
			if (compare(currentScreen.envName, _MENU_.env.envName)) {
				this->currentScreen.buttons.at(0).changeToFirstColor();
				this->currentScreen.buttons.at(1).changeToSecondColor();
				this->currentScreen.Selected = "option";
			}
			else { // 2. Move character down
				this->currentScreen.player.move("down");
			}
		}
		else if (cmd == "joystick_left") {
			if (!compare(currentScreen.envName, _MENU_.env.envName)) {
				this->currentScreen.player.move("left");
			}
		}
		else if (cmd == "joystick_right") {
			if (!compare(currentScreen.envName, _MENU_.env.envName)) 
				this->currentScreen.player.move("right");
		}
		else if (cmd == "joystick_x") {
			if (currentScreen.Selected.size() > 0) Exe(currentScreen.Selected);
		}
		else if (cmd == "joystick_start") {
			currentScreen.Options(this->wndWidth, this->wndHeight);
		}
	}
}
 
void Game::timeBusiness() {	
	if (compare (this->currentScreen.envName, "Menu")){
		if (Music.getStatus() == sf::SoundSource::Stopped) {
			playMusic(this->pathMusic[(int)rand() % this->nMusic], true);
		}
	}
}

void Game::moveTo(std::string path, std::string from) {
	if (path == "Bedroom") {
		currentScreen = _BROOM_.env;
	} 
	// ...
}

void Game::update() {
	eventPolling(); timeBusiness();
	std::string shouldI = currentScreen.inChangePosition(); // It will return "" if it's not in a "change position"
	if (shouldI.size() > 0) { moveTo(shouldI, currentScreen.envName);  }
}

void Game::render() {
	this->Window->clear(this->background_color);
	// Draw elements of current environment
	drawEnvironment(this->currentScreen);

	//std::cout << currentScreen.player.sprite.getPosition().x << " ";
	//std::cout << currentScreen.player.sprite.getPosition().y << std::endl;

	this->Window->display();
}

void Game::drawEnvironment(Environment env) {
	for (sf::RectangleShape rS : env.rShapes) { this->Window->draw(rS); }
	for (sf::Text Tx : env.Texts) { this->Window->draw(Tx); }
	for (Billboard b : env.billboards) {
		this->Window->draw(b.rShape); 
		this->Window->draw(b.txt);
	}
	for (Button bt : env.buttons) {
		this->Window->draw(bt.rectangleContainer);
		this->Window->draw(bt.Tag);
	}
	if (env.player.isUsed) { this->Window->draw(env.player.sprite); }
}

bool Game::activeJoysticks() {
	int activeJoysticks = 0;
	for (int e = 0; e < MAX_JOYSTICK_CONNECTED; e++) {
		if (sf::Joystick::isConnected(e)) {
			std::cout << "Joystick #" << e << " is connected" << std::endl;
			activeJoysticks++;
		}
	}

	// manage what to do if #activeJoysticks joysticks are connected
	// JYSareConnected(activeJoysticks);

	if (activeJoysticks > 0) { return true; }
	else { return false; }
}

bool Game::isRunning() { return this->Window->isOpen(); }

Game::Game() { initVariables(); initWindow(); }