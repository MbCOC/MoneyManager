#include <iostream>

#include "CoreFunctions.h"
#include "Account.h"
#include "History.h"

//---App logic
int main()
{
	bool isOpen = true;
	bool isAccountVerified = false;
	Account *user = new Account();
	/*int startUserId = 26022008;							//---Test user id
	std::string startUserPassword = "dr26022008";					//---Test user password
	float startUserMoney = 500.0f;							//---Test user moneyAmount
	Account *user = new Account(startUserId, startUserPassword, startUserMoney);	//---Test user account*/
	//---Draw new interface
	while (isOpen)
	{
		showMassage("MONEY MANAGER", "yellow");
		std::cout << "\t\tSTATUS: ";
		//---Show options
		if (isAccountVerified)
		{
			showMassage("VERIFIED\n", "green");
			showMassage("Options: ", "green");
			std::cout << "1 - Check id | 2 - Check password | 3 - Check money balance\n"
				 << "\t 4 - Change password | 5 - Change money amount | 6 - Add note\n"
				 << "\t 7 - Show history | 8 - Clear history | 0 - Close app\n\n";
		}
		else
		{
			showMassage("UNVERIFIED\n", "red");
			showMassage("Options: ", "green");
			std::cout << "1 - Sign in | 2 - Create a new account | 0 - Close app\n\n";
		}
		//---Choosing option
		std::cout << "Choose an option: ";
		int chosenOption;
		setTextColor("yellow");
		chosenOption = checkInputInt();
		setTextColor();
		//---Verification check
		if (isAccountVerified)
		{
			std::string newPassword;
			std::string newPasswordCheck;
			float newMoneyAmount;

			float profitValue;
			std::string profitCategory;
			float expenseValue;
			std::string expenseCategory;
			//---Check chosen option
			switch (chosenOption)
			{
			case -1:
				break;
			case 0:
				isOpen = false;
				system("cls");
				showMassage("Application closed successful\n", "green");
				delete user;
				return EXIT_SUCCESS;
				break;
			case 1:
				std::cout << "\nYour id is: ";
				showMassage(std::to_string(user->getId()), "yellow");
				break;
			case 2:
				std::cout << "\nYour password is: ";
				showMassage(user->getPassword(), "yellow");
				break;
			case 3:
				std::cout << "\nYour money balance ($): ";
				showFloat(user->moneyAmount, "yellow");
				break;
			case 4:
				showMassage("\nChange password:\n", "green");
				std::cout << "Enter a new password: ";
				setTextColor("yellow");
				newPassword = checkInputStr();
				setTextColor();

				if (newPassword == user->getPassword())
				{
					showError("the new password can't be the same as the current password");
					break;
				}
				else if (newPassword.length() < 5)
				{
					showError("the new password is too short");
					break;
				}

				std::cout << "Confirm a new password: ";
				setTextColor("yellow");
				newPasswordCheck = checkInputStr();
				setTextColor();

				if (newPassword != newPasswordCheck)
				{
					showError("unsuccessful confirm password");
					break;
				}
				else
				{
					user->setPassword(newPassword);
					showMassage("\nPassword changed successful", "green");
					isAccountVerified = false;
				}
				break;
			case 5:
				showMassage("\nChange money amount:\n", "green");
				std::cout << "Enter a new money amount ($): ";
				setTextColor("yellow");
				newMoneyAmount = checkInputFloat();
				setTextColor();

				if (newMoneyAmount == -1 || newMoneyAmount < 0.0f)
				{
					if (newMoneyAmount < 0.0f)
					{
						showError("money amount can't be less then 0");
						break;
					}
				}

				user->moneyAmount = newMoneyAmount;
				showMassage("\nMoney amount changed successful", "green");
				break;
			case 6:
				showMassage("\nOptions: ", "green");
				std::cout << "1 - Add profit | 2 - Add expense\n";
				std::cout << "\nChoose an option: ";
				setTextColor("yellow");
				chosenOption = checkInputInt();
				setTextColor();

				switch (chosenOption)
				{
				case 1:
					std::cout << "Enter a profit value ($): ";
					setTextColor("yellow");
					profitValue = checkInputFloat();
					setTextColor();

					if (profitValue < 0.0f)
					{
						showError("profit amount can't be less then 0\n");
						break;
					}

					std::cout << "Enter a profit category: ";
					setTextColor("yellow");
					profitCategory = checkInputStr();
					setTextColor();

					user->moneyAmount += profitValue;
					user->history.push_back(History(profitValue, profitCategory, "profit"));
					showMassage("Your money amount now is ($): ");
					showFloat(user->moneyAmount, "yellow");
					break;
				case 2:
					std::cout << "Enter an expense value ($): ";
					setTextColor("yellow");
					expenseValue = checkInputFloat();
					setTextColor();

					if (expenseValue < 0.0f)
					{
						showError("expense value can't be less then 0\n");
						break;
					}

					if (expenseValue > user->moneyAmount)
					{
						showError("expense value can't be bigger then current money amount");
						break;
					}

					std::cout << "Enter an expense category: ";
					setTextColor("yellow");
					expenseCategory = checkInputStr();
					setTextColor();
					
					user->moneyAmount -= expenseValue;
					user->history.push_back(History(expenseValue, expenseCategory, "expense"));
					showMassage("Your money amount now is ($): ");
					showFloat(user->moneyAmount, "yellow");
					break;
				default:
					showError("unavailable option\n");
					break;
				}

				break;
			case 7:
				if (user->history.empty())
				{
					showMassage("\nHistory is clear", "green");
				}
				else
				{
					std::cout << "User ";
					showMassage(std::to_string(user->getId()), "green");
					std::cout << "'s history:\n\n";

					for (int i = 0; i < user->history.size(); i++)
					{
						std::cout << "Category: ";
						showMassage('\"' + user->history.at(i).savedCatigorie + '\"', "yellow");
						std::cout << " | Value: ";

						if (user->history.at(i).savedType == "profit")
						{
							showFloat(user->history.at(i).savedValue, "green");
						}
						else
						{
							showFloat(-user->history.at(i).savedValue, "red");
						}

						std::cout << std::endl;
					}
				}

				break;
			case 8:
				user->history.clear();
				showMassage("\nHistory cleared", "green");
				break;
			default:
				showError("unavailable option\n");
				break;
			}
			checkEnterKey();
		}
		else
		{
			int signInId, signUpId;
			float moneyAmount;
			std::string signInPassword, signUpPassword;
			//---Check chosen option
			switch (chosenOption)
			{
			case -1:
				break;
			case 0:
				isOpen = false;
				system("cls");
				showMassage("Application closed successful\n", "green");
				return EXIT_SUCCESS;
				delete user;
				break;
			case 1:
				std::cout << "\nEnter your id: ";
				setTextColor("yellow");
				signInId = checkInputInt();
				setTextColor();

				if (signInId == -1 || signInId < 10000) {
					if (signInId == -1)
					{
						break;
					}
					else if (signInId < 10000)
					{
						showError("Account id is too short");
						break;
					}
				}

				std::cout << "Enter your password: ";
				setTextColor("yellow");
				signInPassword = checkInputStr();
				setTextColor();

				if (signInPassword.length() < 5)
				{
					showError("password is too short");
					break;
				}

				if (signInId == user->getId() && signInPassword == user->getPassword())
				{
					showMassage("\nSigned in successful\n", "green");
					isAccountVerified = true;
				}
				else if (signInId != user->getId() && signInPassword != user->getPassword())
				{
					showError("uncorrect id and password");
					break;
				}
				else if (signInId != user->getId())
				{
					showError("uncorrect id");
					break;
				}
				else if (signInPassword != user->getPassword())
				{
					showError("uncorrect password");
					break;
				}

				break;
			case 2:
				showMassage("\nCreate a new account:\n", "yellow");
				std::cout << "Enter a new account id: ";

				setTextColor("yellow");
				signUpId = checkInputInt();
				setTextColor();

				if (signUpId == -1 || signUpId < 10000) {
					if (signUpId == -1)
					{
						showError("uncorrect input");
					}
					else if (signUpId < 10000)
					{
						showError("new account id is too short");
					}
					break;
				}

				std::cout << "Enter a new account password: ";
				setTextColor("yellow");
				signUpPassword = checkInputStr();
				setTextColor();

				if (signUpPassword.length() < 5)
				{
					showError("new password is too short");
					break;
				}

				std::cout << "Enter a new money amount ($): ";
				setTextColor("yellow");
				moneyAmount = checkInputFloat();
				setTextColor();

				if (moneyAmount < 0.0f)
				{
					showError("money amount can't be less then 0");
					break;
				}

				if (signUpId == user->getId())
				{
					showError("an account with this id already exists");
					break;
				}
				else
				{
					user = new Account(signUpId, signUpPassword, moneyAmount);
					showMassage("\nAccount created successful\n", "green");
				}

				break;
			default:
				showError("unavailable option\n");
				break;
			}

			checkEnterKey();
		}
	}
	
	delete user;
	return EXIT_SUCCESS;
}
