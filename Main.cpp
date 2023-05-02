#include <iostream>
#include <string>
#include "PersonType.h"
#include "CandidateType.h"
#include "Functions.h"
using namespace std;

bool ssnCheck(int ssn);
void personMenu(int select);
void candidateMenu(int select);

int main()
{
	bool menu = true;
	int userSelect;

	while (menu)
	{
		cout << "MAIN MENU\n" << endl;
		cout << "1. Personal Info Menu" << endl;
		cout << "2. Candidate Info Menu" << endl;
		cout << "3. Exit" << endl;

		cin >> userSelect;

		switch (userSelect)
		{
		case 1:
			personMenu(userSelect);
			break;
		case 2:
			candidateMenu(userSelect);
			break;
		case 3:
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
