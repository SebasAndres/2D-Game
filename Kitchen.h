#pragma once
#include "Environment.h"
class Kitchen {
public:
	Kitchen() = default; Kitchen(int width, int height);
	Environment env = Environment("Kitchen");
	sf::RectangleShape background_image;
};

