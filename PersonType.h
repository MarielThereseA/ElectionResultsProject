#pragma once
#include <string>
#ifndef PERSONTYPE_H
#define PERSONTYPE_H

class PersonType
{
private:
	std::string fName;
	std::string lName;
	int socialSecurityNumber;
public:
	PersonType();
	PersonType(std::string first, std::string last, int social);
	void setPersonInfo(std::string newFirst, std::string newLast, int newSocial);
	std::string getFirstName() const;
	std::string getLastName() const;
	int getSSN() const;
	void printName();
	void printPersonInfo();
	void printSSN();
	~PersonType();
};

#endif