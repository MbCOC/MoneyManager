#pragma once
void checkEnterKey();
void setTextColor(std::string newColor = "");
void showMassage(std::string text, std::string textColor = "");
void showFloat(float value, std::string textColor = "");
void showError(std::string errorText);
int checkInputInt();
float checkInputFloat();
std::string checkInputStr();