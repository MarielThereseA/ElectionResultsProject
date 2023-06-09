#pragma once
#include "CandidateType.h"
#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

class CandidateList
{
private:
	CandidateType candidate;
	static CandidateList* first;
	CandidateList* next;
	static CandidateList* last;
	static int counter;
public:
	CandidateList();
	CandidateList(const CandidateType& votes, CandidateList* link);
	CandidateList(const CandidateList& other);
	CandidateList& operator=(const CandidateList& other);
	CandidateList* getLink() const;
	CandidateType getCandidate() const;
	void setCandidate(const CandidateType& votes);
	void setLink(CandidateList* link);
	void addCandidate(const CandidateType& newCandidate);
	int getWinner() const;
	bool searchCandidate(int ssn) const;
	void printCandidateName(int ssn);
	void printAllCandidates();
	void printCandidateCampusVotes(int ssn, int i);
	void printCandidateTotalVotes(int ssn);
	void printFinalResults();
	void destroyList();
	~CandidateList();
};
#endif