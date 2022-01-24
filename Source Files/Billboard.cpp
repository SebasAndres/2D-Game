#include "Billboard.h"
sf::Font Font;

Billboard::Billboard(std::string text, sf::Color color, std::string pathFont, int width, int height, int x, int y) {
	this->rShape.setSize(sf::Vector2f(width, height));
	this->rShape.setPosition(x, y); this->rShape.setFillColor(color);
	this->txt.setString(text); Font.loadFromFile(pathFont);
	this->txt.setFont(Font); this->txt.setCharacterSize(width*14/400); this->txt.setFillColor(sf::Color::White);
	this->txt.setPosition(x + 2500 / (1.5*text.size()), y + height/4);
}
