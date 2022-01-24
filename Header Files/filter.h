#pragma once
#include <iostream>
#include <vector>
class filter
{
public: 
	filter() = default;
	std::vector<std::pair<std::string, std::string>> self;
	void addCondition (std::pair<std::string, std::string> condition);
};

