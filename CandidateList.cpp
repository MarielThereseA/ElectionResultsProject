#include <iostream>
#include "CandidateList.h"
#include "CandidateType.h"

CandidateList::CandidateList()
{
	for (int i = 0; i < 31; ++i)
	{
		candidates[i] = CandidateType();
	}
}

void CandidateList::printAllCandidates()
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		candidates[i].printCandidateInfo();
	}
}

bool CandidateList::searchCandidate(int ssn) const
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (candidates[i].getSSN() == ssn)
			return true;
	}

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
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (candidates[i].getSSN() == ssn)
			candidates[i].printCandidateDivisionVotes(i);
	}
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
	int ssnWinner;
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
		candidates[i].printCandidateTotalVotes();
	}
}

void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	for (int i = 0; i < numOfCandidates; ++i)
	{
		if (!searchCandidate(candidates[i].getSSN()))
		{
			candidates[i] = newCandidate;
			break;
		}
	}
}

CandidateType::~CandidateType(){}