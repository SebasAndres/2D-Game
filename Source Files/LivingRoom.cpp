#include "LivingRoom.h"
sf::Texture lRoom_texture;
LivingRoom::LivingRoom(int w, int h) {
	this->background_image.setSize(sf::Vector2f(w, h));
	this->background_image.setPosition(0, 0);
	lRoom_texture.loadFromFile("Images/Scenes/living_room.jpg");
	const sf::Texture* texture = &lRoom_texture;
	this->background_image.setTexture(texture);
	Player player = Player("casual", w, h);
	player.setOrigin(0, h * 0.3); // left "top"
	this->env.player = player;
	this->env.rShapes = { background_image };
}
