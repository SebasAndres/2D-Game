#pragma once
#include <iostream>
#include<vector>
#include <string>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Environment.h"
#include "Button.h"
#include "Billboard.h"
#include "BedroomStage.h"
#include "MENU.h"

#define gameName "Just in the middle"
#define forn (MAX) for (int q=0; q<MAX; q++)

class Game
{
private:
	sf::RenderWindow* Window;
	sf::VideoMode videoMode;
	sf::Event event;
	// Window Basic Configuration
	void initVariables(); void initWindow(); void eventPolling(); void timeBusiness();
	sf::Color background_color = sf::Color::Black;
	int wndWidth = 1000; int wndHeight = 500;
	// ** 
	// ---------------------------------> Setup different screens
	Environment currentScreen; // It contains the set of objects shown at that moment
	MENU _MENU_; BedroomStage _BROOM_;
	// Player / Characters
	// **
	// Music & Sounds
	int nMusic = 10; int MUSIC_VOLUME = 60;
	std::string pathMusic[10] = {
		"Audio/Music/Illenium - Sleepwalker (feat. Joni Fatora).wav",
		"Audio/Music/Kygo - Here for You (feat. Ella Henderson).wav",
		"Audio/Music/Linkin Park - Sorry for Now.wav",
		"Audio/Music/Whethan - Be Like You (feat. Broods).wav",
		"Audio/Music/Whethan, K.Flay - Hurting On Purpose.wav",
		"Audio/Music/Madeon & Porter Robinson - Shelter (IDD Edit).wav",
		"Audio/Music/Virginia To Vegas - Just Friends.wav",
		"Audio/Music/King Princess - 1950.wav",
		"Audio/Music/IDD - Intro (with Halsey - Ghost vocals).wav",
		"Audio/Music/Manila Killa - Everyday, Everyday [IDD REMIX].wav"
	};
public:
	Game(); void update(); void render(); bool isRunning(); void playMusic (std::string path, bool verb);
	void drawEnvironment(Environment env); void manageMouseMovement(int x, int y);
	void moveTo(std::string path, std::string from);
	void manageMouseClicked(sf::Event::MouseButtonEvent mData);
	void manageButtonPressed(int jButton);
	void manageKeyPressed(int key); bool compare(std::string s1, std::string s2);
	void Exe(std::string f);
	bool activeJoysticks(); 
};
