#pragma once
#include <string>
#include "CandidateType.h"
#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

const int MAX_NUM_CANDIDATES = 50;

class CandidateList
{
private:
	int numOfCandidates;
	CandidateType candidates[MAX_NUM_CANDIDATES];
public:
	CandidateList();
	void printAllCandidates();
	bool searchCandidate(int ssn) const;
	void printCandidateName(int ssn);
	void printCandidateCampusVotes(int ssn, int i);
	void printCandidateTotalVotes(int ssn);
	int getWinner() const;
	void printFinalResults();
	void addCandidate(const CandidateType& newCandidate);
	~CandidateList();
};
#endif