#pragma once
#include <SFML/Graphics.hpp>
class buttonStyle
{
private:
	int rgbIncrease = 30;
public:
	buttonStyle() = default;
	buttonStyle(sf::Color mainColor, sf::Color BorderColor, sf::Color tagColor,
		std::string pathFont, float OutlineThickness, int charSize);
	bool notTooClear(sf::Color color);
	sf::Color mainColor, borderColor, tagColor, secondColor;
	int charSize; std::string pathFont;
	float outlineThickness;
};

