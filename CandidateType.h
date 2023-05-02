#include <iostream>
#include <string>
#include "PersonType.h"
#pragma once
#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

const int NUM_OF_CAMPUSES = 4;

class CandidateType :public PersonType
{
private:
	int votes;
	int campusArray[NUM_OF_CAMPUSES];
public:
	CandidateType();
	void updateVotesByCampus(int campusNumber, int newVotes);
	int getTotalVotes() const;
	int getVotesByCampus(int campusNumber) const;
	void printCandidateInfo();
	void printCandidateTotalVotes();
	void printCandidateDivisionVotes(int division);
	~CandidateType();
};
#endif