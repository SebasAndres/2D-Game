#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Billboard
{
public: 
	Billboard() = default;
	Billboard(std::string text, sf::Color color, std::string pathFont, int width, int height, int x, int y);
	sf::RectangleShape rShape; sf::Text txt;
};

