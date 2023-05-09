#pragma once
#include <fstream>
#include <string>
#include "CandidateList.h"
#include "CandidateType.h"
#include "PersonType.h"

void createCandidateList(ifstream& infile, CandidateList& candidateList)
{
	int ssn = 0;
	int allVotes[NUM_OF_CAMPUSES] = { 0 };
	string fName, lName;
	infile >> ssn;
	while (ssn != -999)
	{
		CandidateType newCandidate;
		infile >> fName;
		infile >> lName;
		newCandidate.setPersonInfo(fName, lName, ssn);
		for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
		{
			infile >> allVotes[i];
			newCandidate.updateVotesByCampus(i, allVotes[i]);
		}
		candidateList.addCandidate(newCandidate);
		infile >> ssn;
	}
}
void readCandidateData(CandidateList& candidateList)
{
	ifstream infile;
	infile.open("candidate_data.txt");
	if (!infile)
	{
		cerr << "Input file does not exist." << endl;
		exit(1);
	}
	createCandidateList(infile, candidateList);
	infile.close();
}