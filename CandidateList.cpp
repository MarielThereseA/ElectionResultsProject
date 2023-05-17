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
	candidate = votes;
	next = link;
	if (first == nullptr)
		first = this;
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
	if (first == nullptr)
		first->setCandidate(newCandidate);
	candidate = newCandidate;
	next = nullptr;
}

int CandidateList::getWinner() const
{
	if (first == nullptr)
	{
		std::cout << "=> List is empty." << std::endl;
		return 0;
	}

	int winnerSSN = 0, mostVotes = 0;

	if (first->candidate.getTotalVotes() > mostVotes)
	{
		winnerSSN = first->candidate.getSSN();
		mostVotes = first->candidate.getTotalVotes();
	}

	CandidateList* current = next;
	while (current != nullptr)
	{
		if (current->candidate.getTotalVotes() > mostVotes)
		{
			winnerSSN = next->candidate.getSSN();
			mostVotes = next->candidate.getTotalVotes();
			current = this->next;
		}
	}

	return winnerSSN;
}

bool CandidateList::searchCandidate(int ssn) const
{
	if (first == nullptr)
	{
		std::cout << "=> List is empty." << std::endl;
		return false;
	}

	if (first->candidate.getSSN() == ssn)
		return true;

	CandidateList* current = next;
	while (current != nullptr)
	{
		if (current->candidate.getSSN() == ssn)
			return true;
		current = this->next;
	}
	std::cout << "=> SSN not in the list." << std::endl;
	return false;
}

void CandidateList::printCandidateName(int ssn)
{
	if (first == nullptr)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	if (first->candidate.getSSN() == ssn)
	{
		candidate.printName();
		return;
	}

	CandidateList* current = next;
	while (current != nullptr)
	{
		if (current->candidate.getSSN() == ssn)
		{
			candidate.printName();
			return;
		}
		current = this->next;
	}
	std::cout << "SSN not in the list." << std::endl;
}

void CandidateList::printAllCandidates()
{
	if (first == nullptr)
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