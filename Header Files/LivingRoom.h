#pragma once
#include "Environment.h"
class LivingRoom
{
public: 
	LivingRoom() = default; LivingRoom(int width, int height);
	sf::RectangleShape background_image;
	Environment env = Environment("LivingRoom");
};

