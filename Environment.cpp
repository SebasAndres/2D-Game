#include "Environment.h"
#include <map>

Environment::Environment(std::string envName) { 
	this->envName = envName;
}

void Environment::setNextsEnv (std::vector<filter> filters, std::vector<std::string> linkedTo) {
	for (int z=0; z<linkedTo.size(); z++){
		this->linker[linkedTo[z]] = filters[z];
		this->paths.push_back(linkedTo[z]);
	}
}

std::string Environment::inChangePosition() {
	std::string nextPath = "";
	for (int r = 0; r < linker.size(); r++) {
		// Si se cumplen las condiciones en link[r].filter => devolver link[r].pathName
		bool ConditionsAreSatisfied = true;
		for (std::pair <std::string, std::string> cc : linker[paths[r]].self) {
			float u;
			if (cc.first == "x") { u = player.sprite.getPosition().x; }
			else { u = player.sprite.getPosition().y; }

			float val; std::string buff;
			for (int i = 1; i < cc.second.size(); i++) { buff += cc.second[i]; }
			val = std::stof(buff);

			if (cc.second[0] == 'M') { // check if cc.second[1:] > u				
				if (!val > u) { ConditionsAreSatisfied = false; }
			}
			else { // check if cc.second[1:] < u
				if (val > u) { ConditionsAreSatisfied = false; }
			}
		}
		if (ConditionsAreSatisfied) { nextPath = paths[r]; break; }
	}
	return nextPath;
}

void Environment::Options (int wWidth, int wHeight) {
	
	sf::RectangleShape mRect;
	mRect.setFillColor(sf::Color(186, 186, 186));
	mRect.setPosition(wWidth * 0.40, wHeight * 0.30);
	mRect.setSize(sf::Vector2f(wWidth * 0.53, wHeight * 0.55));
	mRect.setOutlineColor(sf::Color::Black);
	mRect.setOutlineThickness(2.f);
	
	this->envOptionsText = {};
	this->envOptionsShape = { mRect };

	if (this->inOptions) { // Remove box of options
		for (sf::Text txt : envOptionsText) { Texts.pop_back(); }
		for (sf::RectangleShape shape : envOptionsShape) { rShapes.pop_back(); }
	}
	else { // Add to env elements of options
		for (sf::Text txt : envOptionsText) { Texts.push_back(txt); }
		for (sf::RectangleShape rShape : envOptionsShape) { rShapes.push_back(rShape); }
	}

	this->inOptions = !this->inOptions;
}