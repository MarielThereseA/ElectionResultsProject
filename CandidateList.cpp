#include <iostream>
#include "CandidateList.h"
#include "CandidateType.h"
#include "PersonType.h"

int CandidateList::counter = 0;

CandidateList::CandidateList()
{
	first = nullptr;
	last = nullptr;
	++counter;
}

void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	last = first + counter;
	
}

int CandidateList::getWinner() const
{
	if (first == nullptr)
	{
		std::cout << "=> List is empty." << std::endl;
		return 0;
	}

	int winnerSSN = 0, mostVotes = 0;

	for (int i = 0; i <= counter; ++i)
	{
		if ((first + i)->candidate.getTotalVotes() > mostVotes)
		{
			mostVotes = (first + i)->candidate.getTotalVotes();
			winnerSSN = (first + i)->candidate.getSSN();
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

	while (ssn != -999)
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

}

CandidateList::~CandidateList()
{
	destroyList();
}