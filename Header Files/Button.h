#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "buttonStyle.h"
class Button
{
public:
	Button() = default;
	Button(buttonStyle style, std::string tag, int width, int height,
		float xPosition, float yPosition, std::string function);

	sf::RectangleShape rectangleContainer; sf::Text Tag;
	int width, height; float xPosition, yPosition; buttonStyle style;
	std::string function;
	void changeToFirstColor(); void changeToSecondColor();
};

