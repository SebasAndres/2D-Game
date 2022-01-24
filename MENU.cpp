#include "MENU.h"

sf::Texture ref_menuTexture, ref_menuLeft;
sf::Font font;

MENU::MENU(int wWidth, int wHeight) {
	this->menuRectangle.setSize(sf::Vector2f(wWidth / 4.f, wHeight));
	this->menuRectangle.setPosition(0, 0);
	ref_menuLeft.loadFromFile("Images/red.jpg");
	const sf::Texture* menuLeftTexture = &ref_menuLeft;
	this->menuRectangle.setTexture(menuLeftTexture);
	this->menuRectangle.setFillColor(sf::Color(128, 0, 0));
	this->MenuButtonStyle = buttonStyle(
		sf::Color::Black, sf::Color::White, 
		sf::Color::White, "Fonts/LibreBaskerville-Regular.ttf", 1.f, wHeight / 25
	);
	ref_menuTexture.loadFromFile("Images/autumn-tree.jpg");
	ref_menuTexture.setSmooth(true); 
	const sf::Texture* menuTexture = &ref_menuTexture;
	this->menuRectangle_.setSize(sf::Vector2f(wWidth - wWidth/4.f, wHeight));
	this->menuRectangle_.setPosition(wWidth/4.f, 0);
	this->menuRectangle_.setTexture(menuTexture);

	this->Title.setString("Just in the middle");
	font.loadFromFile("Fonts/Cassandra.ttf"); this->Title.setFont(font);
	this->Title.setPosition(wWidth-wWidth*0.6, wHeight*0.1);

	this->StartButton = Button(MenuButtonStyle, "Iniciar",
		0.166 * wWidth, 0.1 * wHeight, 0.166 * wWidth, 0.34 * wHeight, "menu_start_button");
	this->OptionsButton = Button(MenuButtonStyle, "Opciones",
		0.166 * wWidth, 0.1 * wHeight, 0.134 * wWidth, 0.60 * wHeight, "menu_options_button");
	this->env.rShapes = { menuRectangle, menuRectangle_ };
	this->env.buttons = { StartButton, OptionsButton };
	this->env.Texts = { Title };
}
