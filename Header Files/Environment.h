#pragma once
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Billboard.h"
#include "Player.h"
#include "filter.h"

class Environment
{
public:
	Environment() = default;
	Environment(std::string envName);

	bool inOptions = false; void Options(int w, int h);
	std::string inChangePosition(); 

	std::map <std::string, filter> linker;
	std::vector <std::string> paths;
	void setNextsEnv(std::vector<filter> filters, std::vector<std::string> linkedTo);

	std::string Selected; // Obj selected either by the joystick or the keyboard
	std::string envName;
	std::vector<sf::RectangleShape> rShapes;
	std::vector<sf::Text> Texts;
	std::vector<Button> buttons;
	std::vector<Billboard> billboards;
	Player player;

	// Sub environment -> Options
	std::vector<sf::Text> envOptionsText;
	std::vector<sf::RectangleShape> envOptionsShape;

};

