#include <iostream>
#include "CandidateList.h"
#include "CandidateType.h"
#include "PersonType.h"

int CandidateList::counter = 0;
CandidateList* CandidateList::first = nullptr;

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
	if (first == nullptr)
	{
		first = node;
		++counter;
		return;
	}

	CandidateList* current = first;

	while (current != nullptr)
	{
		if (current->next == nullptr)
		{
			current->next = node;
			++counter;
			return;
		}
		current = current->next;
	}
}

int CandidateList::getWinner() const
{
	if (first == nullptr)
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
	if (first == nullptr)
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
	if (first == nullptr)
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
	if (first == nullptr)
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
	if (first == nullptr)
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
	if (first == nullptr)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	CandidateList* current = first;

	while (current != nullptr)
	{
		current->candidate.printName();
		std::cout << ": " << current->candidate.getTotalVotes() << std::endl;
		current = current->next;
	}
}

void CandidateList::destroyList()
{
	if (first == nullptr)
	{
		std::cout << "=> List is empty." << std::endl;
		return;
	}

	CandidateList* current = first;

	while (counter > 0)
	{
		current = first;

		while (current->next != nullptr)
			current = current->next;

		current->candidate.~CandidateType();
		--counter;
		current = nullptr;
	}
}

CandidateList::~CandidateList()
{
	destroyList();
}