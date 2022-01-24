#include "Button.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

sf::Font nFont;

Button::Button(buttonStyle style, std::string tag, int width, int height,
	float xPosition, float yPosition, std::string function) {

	this->style = style; this->function = function;
	this->height = height; this->width = width; this->xPosition = xPosition; this->yPosition = yPosition;

	this->rectangleContainer.setSize(sf::Vector2f(width, height));
	this->rectangleContainer.setPosition(xPosition, yPosition);
	this->rectangleContainer.setFillColor(style.mainColor);
	this->rectangleContainer.setOutlineColor(style.borderColor);
	this->rectangleContainer.setOutlineThickness(style.outlineThickness);

	float cteMarginX = 0.305;

	nFont.loadFromFile(style.pathFont);
	this->Tag.setFont(nFont); this->Tag.setString(tag);
	this->Tag.setFillColor(style.tagColor);
	this->Tag.setPosition(xPosition + width / 2 - tag.size() * style.charSize * cteMarginX, yPosition + height * 0.25);
	this->Tag.setCharacterSize(style.charSize);
}

void Button::changeToFirstColor() { this->rectangleContainer.setFillColor(style.mainColor); }

void Button::changeToSecondColor() { this->rectangleContainer.setFillColor(style.secondColor); }
