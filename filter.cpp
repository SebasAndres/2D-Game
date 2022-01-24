#include "filter.h"
void filter::addCondition (std::pair<std::string, std::string> condition) {
	this->self.push_back(condition);
}