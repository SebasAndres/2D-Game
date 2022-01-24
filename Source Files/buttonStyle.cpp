#include "buttonStyle.h"
buttonStyle::buttonStyle(sf::Color mainColor, sf::Color BorderColor, sf::Color tagColor,
	std::string pathFont, float OutlineThickness, int charSize)
{
	this->mainColor = mainColor; this->borderColor = BorderColor; this->tagColor = tagColor;
	if (notTooClear(mainColor)){
		this->secondColor = sf::Color(
			this->mainColor.r + rgbIncrease, this->mainColor.g + rgbIncrease, this->mainColor.b + rgbIncrease
		);
	}
	else {
		this->secondColor = sf::Color(
			this->mainColor.r - rgbIncrease, this->mainColor.g - rgbIncrease, this->mainColor.b - rgbIncrease
		);
	}
	this->outlineThickness = OutlineThickness; this->pathFont = pathFont; this->charSize = charSize;
}

bool buttonStyle::notTooClear (sf::Color color) {
	int rgb[3] = {color.r, color.g, color.b};
	for (int w = 0; w < 3; w++) {
		if (rgb[w] > 255 - this->rgbIncrease) { return false; } // too clear!
	}
	return true;
}
