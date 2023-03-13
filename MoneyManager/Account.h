#pragma once
#include <vector>
#include "History.h"

class Account
{
public:
	bool isVerified;
	float moneyAmount;
	std::vector<History> history;
	
	int getId()
	{
		return userId;
	}

	std::string getPassword()
	{
		return userPassword;
	}

	void setPassword(std::string& newPassword)
	{
		userPassword = newPassword;
	}

	Account()
	{
		isVerified = false;
		userId = -1;
		userPassword = "";
		moneyAmount = 0.0f;
	}
	Account(int& newId, std::string& newPassword, float& newMoneyAmount)
	{
		isVerified = false;
		userId = newId;
		userPassword = newPassword;
		moneyAmount = newMoneyAmount;
	}

private:
	int userId;
	std::string userPassword;
};
