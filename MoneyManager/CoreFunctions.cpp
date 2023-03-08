#include "MoneyManager.h"
#include <algorithm>

void checkEnterKey() {
	std::cin.get();
	std::cin.get();
	system("cls");
}

void setTextColor(std::string newColor = "") {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	std::transform(newColor.begin(), newColor.end(), newColor.begin(), ::tolower);

	if (newColor == "red")
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED);
	}
	else if (newColor == "green")
	{
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	}
	else if (newColor == "blue")
	{
		SetConsoleTextAttribute(console, FOREGROUND_BLUE);
	}
	else if (newColor == "yellow")
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else if (newColor == "purple")
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE);
	}
	else
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

void showMassage(std::string text, std::string textColor = "") {
	setTextColor(textColor);
	std::cout << text;
	setTextColor("white");
}

void showFloat(float value, std::string textColor = "") {
	setTextColor(textColor);
	std::cout << std::fixed << std::setprecision(1) << value;
	setTextColor("white");
}

void showError(std::string errorText) {
	std::transform(errorText.begin(), errorText.end(), errorText.begin(), ::toupper);
	setTextColor("red");
	std::cout << "\nERROR: " << errorText;
	setTextColor("white");
}

int checkInputInt() {
	try
	{
		std::string input;
		std::cin >> input;
		return std::stoi(input);
	}
	catch (const std::invalid_argument&)
	{
		showError("INVALID ARGUMENT\n");
		return -1;
	}
	catch (const std::out_of_range&)
	{
		showError("ARGUMENT IS OUT OF THE RANGE\n");
		return -1;
	}
}

float checkInputFloat() {
	try
	{
		std::string input;
		std::cin >> input;
		return std::stof(input);
	}
	catch (const std::invalid_argument&)
	{
		showError("INVALID ARGUMENT\n");
		return -1;
	}
	catch (const std::out_of_range&)
	{
		showError("ARGUMENT IS OUT OF THE RANGE\n");
		return -1;
	}
}

std::string checkInputStr() {
	try
	{
		std::string input;
		std::cin >> input;
		return input;
	}
	catch (const std::invalid_argument&)
	{
		showError("invalid argument - enter a string\n");
		return "";
	}
}