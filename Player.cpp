#include <iostream>
#include "Player.h"

sf::Texture ref_texture;

Player::Player(std::string mode, int w, int h) {

	this->isUsed = true;
	this->Mode = mode;	
	
	std::string nPath = "Images/Characters/Player/";

	if (mode == "casual") {
		this->pathTextures[0] = { nPath + "frontCasual.png" };
		this->pathTextures[1] = { nPath + "backCasual.png" };
		this->pathTextures[2] = { nPath + "leftCasual.png" };
		this->pathTextures[3] = { nPath + "rightCasual.png" };
	}

	ref_texture.loadFromFile(pathTextures[0].at(0)); // Start front
	sprite.setTexture(ref_texture);
	sprite.setScale (120.f / sprite.getLocalBounds().width,
					 120.f / sprite.getLocalBounds().height);
	sprite.setPosition(w / 2, h / 2);

	currMode = "front";
}

bool Player::compare(std::string s1, std::string s2) {
	bool equal = true;
	if (s1.size() == s2.size()) {
		for (int w = 0; w < s1.size(); w++) {
			if (s1[w] != s2[w]) { equal = false; }
		}
	}
	else { equal = false; }
	return equal;
}

void Player::setToTexture (int mode, int cnt) {
	ref_texture.loadFromFile(pathTextures[mode].at(cnt));
	currMode = mode; sprite.setTexture(ref_texture);
}

void Player::setOrigin (int x, int y) { this->sprite.setPosition(x,y); }

void Player::jMove(float dx, float dy, float x, float y) {
	float Ox = sprite.getPosition().x;
	float Oy = sprite.getPosition().y;	
	this->sprite.setPosition(
		Ox + (dx+0.779)*0.05, Oy + (dy+0.779)*0.05
	);

	std::string direc;	
	if (Oy > Oy + (dy + 0.779) * 0.05) { direc = "down"; }
	else if (Oy < Oy + (dy + 0.779) * 0.05) { direc = "front"; }
	if (Ox < Ox + (dx + 0.779) * 0.05) { direc = "right"; }
	else if (Ox > Ox + (dx + 0.779) * 0.05) { direc = "left"; }


	if (compare(direc, Mode)) {
		if (Cnt < this->pathTextures[index(direc, Modes)].size() - 1) { Cnt++; }
	} else { this->Cnt = 0; }

	// std::cout << direc << " " << Ox << " " << Ox + (dx + 0.779) * 0.05;
	// std::cout << " " << Oy << " " << Oy + (dx + 0.779) * 0.05 << std::endl;

	setToTexture(index(direc, Modes), Cnt); Mode = direc;
}

void Player::move(std::string direc) {

	if (compare (direc, "right")) { 
		this->sprite.setPosition(sprite.getPosition().x + this->step, sprite.getPosition().y);
	}
	else if (compare(direc, "front")) {
		this->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - this->step); 
	}
	else if (compare(direc, "down")) {
		this->sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + this->step);
	}
	else if (compare(direc, "left")){ 
		this->sprite.setPosition(sprite.getPosition().x - this->step, sprite.getPosition().y);
	}

	if (compare(direc, Mode)) {
		if (Cnt < this->pathTextures[index(direc, Modes)].size()-1) { Cnt++; }
	}
	else { this->Cnt = 0; }

	setToTexture(index(direc, Modes), Cnt);
	Mode = direc;
}

int Player::index(std::string s1, std::vector<std::string> vect) {
	for (int z = 0; z < vect.size(); z++) {
		if (compare(s1, vect[z])) { return z; }
	}
	return -1;
}

void Player::usingJoystick() { this->step = 3; }