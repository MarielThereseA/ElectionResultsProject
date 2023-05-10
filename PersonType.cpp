#include <iostream>
#include <string>
#include "PersonType.h"

PersonType::PersonType()
{
	socialSecurityNumber = 0;
}

PersonType::PersonType(std::string first, std::string last, int social)
{
	fName = first;
	lName = last;
	socialSecurityNumber = social;
}

void PersonType::setPersonInfo(std::string newFirst, std::string newLast, int newSocial)
{
	fName = newFirst;
	lName = newLast;
	socialSecurityNumber = newSocial;
}

std::string PersonType::getFirstName() const
{
	return fName;
}

std::string PersonType::getLastName() const
{
	return lName;
}

int PersonType::getSSN() const
{
	return socialSecurityNumber;
}

void PersonType::printName()
{
	std::cout << lName << ", " << fName;
}

void PersonType::printPersonInfo()
{
	printSSN();
	std::cout << " " << fName << " " << lName;
}

void PersonType::printSSN()
{
	int x = socialSecurityNumber, ssn[9] = { 0 };
	for (int i = 0; i < 9; ++i)
	{
		ssn[i] = x % 10;
		x /= 10;
	}

	std::cout << ssn[8] << ssn[7] << ssn[6] << "-" << ssn[5] << ssn[4] << "-" << ssn[3] << ssn[2] << ssn[1] << ssn[0];
}

PersonType::~PersonType(){}