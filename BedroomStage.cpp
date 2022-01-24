#include "BedroomStage.h"

sf::Texture bedroom_texture;
BedroomStage::BedroomStage(int w, int h) {
	this->background_image.setSize(sf::Vector2f(w,h));	
	this->background_image.setPosition(0, 0);
	
	bedroom_texture.loadFromFile("Images/Scenes/bedroom.jpg");
	const sf::Texture* texture = &bedroom_texture;
	this->background_image.setTexture(texture);
	
	this->env.player = Player("casual", w, h);
	this->env.rShapes = { background_image };
}
