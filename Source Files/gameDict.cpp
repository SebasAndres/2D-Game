#include "gameDict.h"
gameDict::gameDict() {
	this->dictionary[4] = "joystick_up";
	this->dictionary[6] = "joystick_down";
	this->dictionary[7] = "joystick_left";
	this->dictionary[5] = "joystick_right";
	this->dictionary[3] = "joystick_start";
	this->dictionary[14] = "joystick_x";
}
std::string gameDict::dictAt(int k) { return dictionary[k]; }
