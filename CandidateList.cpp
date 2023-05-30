#include <iostream>
#include "CandidateList.h"
#include "CandidateType.h"
#include "PersonType.h"

int CandidateList::counter = 0;
CandidateList* CandidateList::first = nullptr;
CandidateList* CandidateList::last = nullptr;

CandidateList::CandidateList()
{
	next = nullptr;
}

CandidateList::CandidateList(const CandidateType& votes, CandidateList* link)
{
	candidate = votes;
	next = link;
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
	CandidateList* node = new CandidateList(newCandidate, nullptr);
	if (counter == 0)
	{
		first = node;
		last = node;
		++counter;
		return;
	}

	last->next = node;
	last = node;
	++counter;
}

int CandidateList::getWinner() const
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return 0;
	}

	int winnerSSN = 0, mostVotes = 0;
	CandidateList* current = first;

	while (current != nullptr)
	{
		if (current->candidate.getTotalVotes() > mostVotes)
		{
			winnerSSN = current->candidate.getSSN();
			mostVotes = current->candidate.getTotalVotes();
		}
		current = current->next;
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

	CandidateList* current = first;
	while (current != nullptr)
	{
		if (current->candidate.getSSN() == ssn)
			return true;
		current = current->next;
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

	CandidateList* current = first;
	while (current != nullptr)
	{
		if (current->candidate.getSSN() == ssn)
		{
			current->candidate.printName();
			return;
		}
		current = current->next;
	}
	std::cout << "=> SSN not in the list." << std::endl;
}

void CandidateList::printAllCandidates()
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	CandidateList* current = first;

	while (current != nullptr)
	{
		current->candidate.printCandidateInfo();
		std::cout << std::endl;
		current = current->next;
	}
}

void CandidateList::printCandidateCampusVotes(int ssn, int i)
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	CandidateList* current = first;

	while (current != nullptr)
	{
		if (current->candidate.getSSN() == ssn)
		{
			current->candidate.printCandidateDivisionVotes(i);
			return;
		}
		current = current->next;
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

	CandidateList* current = first;
	while (current != nullptr)
	{
		if (current->candidate.getSSN() == ssn)
		{
			current->candidate.printCandidateTotalVotes();
			return;
		}
		current = current->next;
	}
	std::cout << "SSN not in the list." << std::endl;
}

void CandidateList::printFinalResults()
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	CandidateList* current = first;

	while (current != nullptr)
	{
		std::cout << current->candidate.getFirstName() << " " << current->candidate.getLastName() << ": " << current->candidate.getTotalVotes() << std::endl;
		current = current->next;
	}
}

void CandidateList::destroyList()
{
	if (counter == 0)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}


	while (first != nullptr)
	{
		CandidateList* current = first;
		first = first->next;
		delete current;
		--counter;
	}
	last = nullptr;
}

CandidateList::CandidateList(const CandidateList& other)
{
	counter = 0;
	first = nullptr;
	last = nullptr;

	CandidateList* current = other.first;
	while (current != nullptr)
	{
		addCandidate(current->candidate);
		current = current->next;
	}
}

CandidateList& CandidateList::operator=(const CandidateList& other)
{
	if (this == &other)
		return *this;

	destroyList();

	CandidateList* current = other.first;
	while (current != nullptr)
	{
		addCandidate(current->candidate);
		current = current->next;
	}

	return *this;
}

CandidateList::~CandidateList()
{
	destroyList();
}