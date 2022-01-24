#pragma once
#include <iostream>
#include <map>
class gameDict
{
public: 
	gameDict();
	std::map <int, std::string> dictionary;
	std::string dictAt(int k);
};
