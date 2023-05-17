#include <iostream>
#include "CandidateList.h"
#include "CandidateType.h"
#include "PersonType.h"

int CandidateList::counter = 0;

CandidateList::CandidateList()
{
	first = nullptr;
	next = nullptr;
	++counter;
}

CandidateList::CandidateList(const CandidateType& votes, CandidateList* link)
{
	if(first == nullptr)
		first = this->first;
	next = link;
	candidate = votes;
	++counter;
}

CandidateList* CandidateList::getLink() const
{
	return next;
}

CandidateType CandidateList::getCandidate() const
{
	return candidate;
}

void CandidateList::setCandidate(const CandidateType& votes)
{
	candidate = votes;
}

void CandidateList::setLink(CandidateList* link)
{
	next = link;
}

void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	if (counter == 0)
		first->setCandidate(newCandidate);
	candidate = newCandidate;
	next = nullptr;
}

int CandidateList::getWinner() const
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return 0;
	}

	int winnerSSN = 0, mostVotes = 0;

	while (next != nullptr)
	{
		if (first != nullptr)
		{
			first->
		}
	}

	return winnerSSN;
}

bool CandidateList::searchCandidate(int ssn) const
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return false;
	}

	while (next != nullptr)
	{
		for (int i = 0; i <= counter; ++i)
		{
			if ((first + i)->candidate.getSSN() == ssn)
				return true;
		}
	}
	std::cout << "=> SSN not in the list." << std::endl;
	return false;
}

void CandidateList::printCandidateName(int ssn)
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	while (next != nullptr)
	{
		for (int i = 0; i <= counter; ++i)
		{
			if ((first + i)->candidate.getSSN() == ssn)
			{
				(first+i)->candidate.printName();
				return;
			}
		}
	}
	std::cout << "SSN not in the list." << std::endl;
}

void CandidateList::printAllCandidates()
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	for (int i = 0; i <= counter; ++i)
		(first + i)->candidate.printCandidateInfo();
}

void CandidateList::printCandidateCampusVotes(int ssn, int i)
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	CandidateList* current = first;

	while (next != nullptr)
	{
		for (int j = 0; j <= counter; ++j)
		{
			if ((first + i)->candidate.getSSN() == ssn)
			{
				(first + i)->candidate.printCandidateDivisionVotes(i);
				return;
			}
		}
	}
	std::cout << "=> SSN not in the list." << std::endl;
}

void CandidateList::printCandidateTotalVotes(int ssn)
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	while (next != nullptr)
	{
		for (int i = 0; i <= counter; ++i)
		{
			if ((first + i)->candidate.getSSN() == ssn)
			{
				(first + i)->candidate.printCandidateTotalVotes();
				return;
			}
		}	
	}
	std::cout << "SSN not in the list." << std::endl;
}

void CandidateList::printFinalResults()
{
	printCandidateName(getWinner());
	std::cout << std::endl;
	printCandidateTotalVotes(getWinner());
}

void CandidateList::destroyList()
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}
}

CandidateList::~CandidateList()
{
	destroyList();
}