#include <iostream>
#include <string>
#include "PersonType.h"
#include "CandidateType.h"

CandidateType::CandidateType()
{
	votes = 0;
	for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
	{
		campusArray[i] = 0;
	}
}

void CandidateType::updateVotesByCampus(int campusNumber, int newVotes)
{
	votes += newVotes;
	campusArray[campusNumber] += newVotes;
}

int CandidateType::getTotalVotes() const
{
	return votes;
}

int CandidateType::getVotesByCampus(int campusNumber) const
{
	return campusArray[campusNumber];
}

void CandidateType::printCandidateInfo()
{
	printPersonInfo();
}

void CandidateType::printCandidateTotalVotes()
{
	std::cout << "\n\tTotal Votes (all campuses): " << votes;
}

void CandidateType::printCandidateDivisionVotes(int division)
{
	if (division == 1)
		std::cout << "\n\tCampus " << division << " total votes: " << campusArray[division - 1] << std::endl;
	else
		std::cout << "\tCampus " << division << " total votes: " << campusArray[division - 1] << std::endl;
}

CandidateType::~CandidateType(){}