#include "Bathroom.h"
sf::Texture background_texture;
Bathroom::Bathroom(int w, int h) {
	this->background_image.setSize(sf::Vector2f(w, h));
	this->background_image.setPosition(0, 0);
	background_texture.loadFromFile("Images/Scenes/bathroom.jpg");
	const sf::Texture* texture = &background_texture;
	this->background_image.setTexture(texture);
	Player player = Player("casual", w, h);
	player.setOrigin(0, h*0.3); // left "top"
	this->env.player = player;
	this->env.rShapes = { background_image };
}
