#pragma once
#include <iostream>
#include <string>

class History
{
public:
	float savedValue;
	std::string savedCatigorie;
	std::string savedType;

	History();
	History(float& newValue, std::string& newCatigorie, std::string newType)
	{
		savedValue = newValue;
		savedCatigorie = newCatigorie;
		savedType = newType;
	}
};
