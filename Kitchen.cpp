#include "Kitchen.h"
sf::Texture kitchen_texture;

Kitchen::Kitchen (int w, int h) {
	this->background_image.setSize(sf::Vector2f(w, h));
	this->background_image.setPosition(0, 0);
	kitchen_texture.loadFromFile("Images/Scenes/kitchen.jpg");
	const sf::Texture* texture = &kitchen_texture;
	this->background_image.setTexture(texture);

	Player player = Player("casual", w, h);
	player.setOrigin(0,h); // left bottom

	this->env.player = player;
	this->env.rShapes = { background_image };
}
