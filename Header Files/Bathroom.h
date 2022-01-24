#pragma once
#include "Environment.h"
class Bathroom
{
	Bathroom() = default; Bathroom(int width, int height);
	Environment env = Environment("Bathroom");
	sf::RectangleShape background_image;
};

