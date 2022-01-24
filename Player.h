#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player() = default; Player (std::string Mode, int w, int h);
	
	void setToTexture(int mode, int cnt);
	int index(std::string s1, std::vector<std::string> vect);
	void move(std::string direc); void jMove(float dx, float dy, float x, float y);
	bool compare(std::string s1, std::string s2);
	void usingJoystick();
	void setOrigin(int x, int y);

	sf::Sprite sprite; std::string Mode;
	std::vector<std::string> pathTextures[4]; 
	bool isUsed = false;
	int step = 10; // number of pixels moved each step
	int Cnt = 0;

	std::string currMode;
	std::vector<std::string> Modes = { "front", "down", "left", "right" };
};

