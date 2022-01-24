#include "Environment.h"
class BedroomStage
{
public:
	BedroomStage() = default; BedroomStage(int width, int height);
	Environment env = Environment("BedroomStage");
	sf::RectangleShape background_image; 
};

