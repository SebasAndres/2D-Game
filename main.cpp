#include <iostream>
#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {	

	// Mirar el codigo hecho en Game.h, Game.cpp y los archivos de Source Files y Header files	
	// Mirar el codigo hecho en Game.h, Game.cpp y los archivos de Source Files y Header files	
	// Mirar el codigo hecho en Game.h, Game.cpp y los archivos de Source Files y Header files	
	// Mirar el codigo hecho en Game.h, Game.cpp y los archivos de Source Files y Header files	
	// Mirar el codigo hecho en Game.h, Game.cpp y los archivos de Source Files y Header files	
	
	Game nGame = Game();
	while (nGame.isRunning()) {
		nGame.update(); nGame.render();	
	}
	return 0;
}
