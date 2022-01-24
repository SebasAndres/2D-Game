#pragma once
#include <iostream>
#include "Environment.h"

class MENU
{
public:
	MENU() = default;
	MENU(int wWidth, int wHeight);

	Environment env = Environment("Menu"); 
	buttonStyle MenuButtonStyle; sf::RectangleShape menuRectangle, menuRectangle_;
	sf::Text StartText, OptionsText; Button StartButton, OptionsButton;
	sf::RectangleShape mRect;
	sf::Text Title;
};


