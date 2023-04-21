#include <iostream>
#include <string>
#include "PersonType.h"
using namespace std;

bool ssnCheck(int ssn);

int main()
{
	bool menu = true;
	int userSelect, ssn;
	string firstName, lastName;

	PersonType testCandidate;

	while (menu) //makeshift menu to test class member functions
	{
		cout << "MAIN MENU\n" << endl;
		cout << "1. Set Personal Info" << endl;
		cout << "2. Display First Name" << endl;
		cout << "3. Display Last Name" << endl;
		cout << "4. Display SSN" << endl;
		cout << "5. Display Full Name" << endl;
		cout << "6. Display All Personal Info" << endl;
		cout << "7. Display Formatted SSN" << endl;
		cout << "8. Exit\n" << endl;

		cin >> userSelect;

		switch (userSelect)
		{
		case 1:
			cout << "Enter your first name: ";
			cin >> firstName;
			cout << "Enter your last name: ";
			cin >> lastName;
			cout << "Enter your Social Security Number: ";
			cin >> ssn;

			if (!ssnCheck(ssn))
				cout << "Invalid SSN." << endl;
			else
			{
				testCandidate.setPersonInfo(firstName, lastName, ssn);
				cout << "Personal info has been updated." << endl;
			}

			system("pause");
			break;

		case 2:
			cout << endl << testCandidate.getFirstName() << endl;
			system("pause");
			break;

		case 3:
			cout << endl << testCandidate.getLastName() << endl;
			system("pause");
			break;

		case 4:
			cout << endl << testCandidate.getSSN() << endl;
			system("pause");
			break;

		case 5:
			cout << endl;
			testCandidate.printName();
			system("pause");
			break;

		case 6:
			cout << endl;
			testCandidate.printPersonInfo();
			system("pause");
			break;

		case 7:
			cout << endl;
			testCandidate.printSSN();

			if (userSelect == 7) //brings system pause prompt to next line for more uniform formatting
				cout << endl;

			system("pause");
			break;

		case 8:
			cout << "You are now exiting the program." << endl;
			menu = false;
			break;

		default:
			cout << "Invalid input. Please try again." << endl;
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}

bool ssnCheck(int ssn) //checks user input has valid amount of digits for ssn
{
	int digit = 0;

	if (ssn > 999999999)
		return false;

	for (int i = 0; i < 9; ++i)
	{
		if (ssn > 0)
			++digit;
		ssn /= 10;
	}

	return digit == 9;
} 