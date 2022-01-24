#include <iostream>
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
	Game nGame = Game();
	while (nGame.isRunning()) {
		nGame.update(); nGame.render();	
	}
	return 0;
}