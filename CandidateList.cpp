#include <iostream>
#include "CandidateList.h"
#include "CandidateType.h"
#include "PersonType.h"

CandidateList::CandidateList()
{
	numOfCandidates = 0;
	for (int i = 0; i < MAX_NUM_CANDIDATES; ++i)
	{
		candidates[i] = CandidateType();
	}
}

void CandidateList::printAllCandidates()
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (i == numOfCandidates - 1)
			candidates[i].printCandidateInfo();
		else
		{
			candidates[i].printCandidateInfo();
			std::cout << std::endl;
		}
	}
}

bool CandidateList::searchCandidate(int ssn) const
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (candidates[i].getSSN() == ssn)
			return true;
	}
	std::cout << "Candidate does not exist.";
	return false;
}

void CandidateList::printCandidateName(int ssn)
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (candidates[i].getSSN() == ssn)
			candidates[i].printName();
	}
}

void CandidateList::printCandidateCampusVotes(int ssn, int i)
{
	int candidate = -1;
	for (int x = 0; x < numOfCandidates; ++x)
	{
		if (searchCandidate(candidates[x].getSSN()))
		{
			candidate = x;
			break;
		}
	}

	if (candidate == -1)
	{
		return;
	}

	candidates[candidate].printCandidateDivisionVotes(i);
}

void CandidateList::printCandidateTotalVotes(int ssn)
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (candidates[i].getSSN() == ssn)
			candidates[i].printCandidateTotalVotes();
	}
}

int CandidateList::getWinner() const
{
	int mostVotes = 0;
	int ssnWinner = 0;
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (candidates[i].getTotalVotes() > mostVotes)
		{
			mostVotes = candidates[i].getTotalVotes();
			ssnWinner = candidates[i].getSSN();
		}
	}

	return ssnWinner;
}

void CandidateList::printFinalResults()
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		candidates[i].printName();
		std::cout << ": " << candidates[i].getTotalVotes() << std::endl;
	}
}

void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	if (numOfCandidates < MAX_NUM_CANDIDATES)
	{
		candidates[numOfCandidates] = newCandidate;
		++numOfCandidates;
	}
}

CandidateList::~CandidateList(){}