#pragma once

#include <iostream>
#include <string>
#include "PersonType.h"
#include "CandidateType.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
bool ssnCheck(int ssn)
{
	if (ssn > 999999999)
		return false;
}

void personMenu(int select)
{
	bool menu = true;
	int ssn;
	std::string firstName, lastName;

	PersonType testPerson;

	while (menu) //makeshift menu to test class member functions
	{
		std::cout << "MAIN MENU\n" << std::endl;
		std::cout << "1. Set Personal Info" << std::endl;
		std::cout << "2. Display First Name" << std::endl;
		std::cout << "3. Display Last Name" << std::endl;
		std::cout << "4. Display SSN" << std::endl;
		std::cout << "5. Display Full Name" << std::endl;
		std::cout << "6. Display All Personal Info" << std::endl;
		std::cout << "7. Display Formatted SSN" << std::endl;
		std::cout << "8. Exit\n" << std::endl;

		std::cin >> select;

		switch (select)
		{
		case 1:
			std::cout << "Enter your first name: ";
			std::cin >> firstName;
			std::cout << "Enter your last name: ";
			std::cin >> lastName;
			std::cout << "Enter your Social Security Number: ";
			std::cin >> ssn;

			if (!ssnCheck(ssn))
				std::cout << "Invalid SSN." << std::endl;
			else
			{
				testPerson.setPersonInfo(firstName, lastName, ssn);
				std::cout << "Personal info has been updated." << std::endl;
			}

			system("pause");
			break;

		case 2:
			std::cout << std::endl << testPerson.getFirstName() << std::endl;
			system("pause");
			break;

		case 3:
			std::cout << std::endl << testPerson.getLastName() << std::endl;
			system("pause");
			break;

		case 4:
			std::cout << std::endl << testPerson.getSSN() << std::endl;
			system("pause");
			break;

		case 5:
			std::cout << std::endl;
			testPerson.printName();
			system("pause");
			break;

		case 6:
			std::cout << std::endl;
			testPerson.printPersonInfo();
			system("pause");
			break;

		case 7:
			std::cout << std::endl;
			testPerson.printSSN();

			if (select == 7) //brings system pause prompt to next line for more uniform formatting
				std::cout << std::endl;

			system("pause");
			break;

		case 8:
			std::cout << "Returning to main menu." << std::endl;
			menu = false;
			break;

		default:
			std::cout << "Invalid input. Please try again." << std::endl;
			system("pause");
			break;
		}
	}
}

void candidateMenu(int select)
{
	bool menu = true;
	int campus, newVotes;

	while (menu)
	{
		std::cout << "1. Update Votes by Campus" << std::endl;
		std::cout << "2. Display Total Votes" << std::endl;
		std::cout << "3. Display Votes by Campus" << std::endl;
		std::cout << "4. Print Candidate Info" << std::endl;
		std::cout << "5. Print Candidate Total Votes" << std::endl;
		std::cout << "6. Print Candidate Division Votes" << std::endl;

		cin >> select;

		switch (select)
			case 1:
				std::cout << "1. Santiago Canyon College" << std::endl;
				std::cout << "2. Santa Ana College" << std::endl;
				std::cout << "3. Orange Coast College" << std::endl;
				std::cout << "4. Coastline Community College" << std::endl;
				std::cout << "\nCampus number: ";
				std::cin >> campus;
				updateVotesByCampus(campus, newVotes);
	}
}
#endif