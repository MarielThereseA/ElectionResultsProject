#include <iostream>
#include <string>
#include "PersonType.h"
#include "CandidateType.h"

CandidateType::CandidateType()
{
	votes = 0;
	campusArray[NUM_OF_CAMPUSES] = { 0 };
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
	printName();
	std::cout << "\tTotal Votes (all campuses): " << votes << std::endl;
}

void CandidateType::printCandidateDivisionVotes(int division)
{
	printName();
	std::cout << "\tCampus " << division << " total votes: " << campusArray[division] << std::endl;
}

CandidateType::~CandidateType(){}