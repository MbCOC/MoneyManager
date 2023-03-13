#pragma once
#include <iostream>
#include <string>

class History
{
private:
	float value;
	std::string category;
	std::string type;

public:
	float getValue()
	{
		return value;
	}

	std::string getCategory()
	{
		return category;
	}

	std::string getType()
	{
		return type;
	}

	History();
	History(float& newValue, std::string& newCategory, std::string newType)
	{
		value = newValue;
		category = newCategory;
		type = newType;
	}
};
