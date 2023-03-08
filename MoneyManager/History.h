#pragma once
#include "MoneyManager.h"
class History
{
public:
	float savedValue;
	std::string savedCatigorie;

	History()
	{

	}
	History(float newValue, std::string newCatigorie)
	{
		savedValue = newValue;
		savedCatigorie = newCatigorie;
	}
};