#pragma once
#include <string>
#include "CandidateType.h"
#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

class CandidateList
{
private:
	CandidateType candidate;
	CandidateList* first;
	CandidateList* last;
	static int counter;
public:
	CandidateList();
	void addCandidate(const CandidateType& newCandidate);
	int getWinner() const;
	bool searchCandidate(int ssn) const;
	void printCandidateName(int ssn);
	void printAllCandidates();
	void printCandidateCampusVotes(int ssn, int i);
	void printCandidateTotalVotes(int ssn);
	void destroyList();
	~CandidateList();
};
#endif