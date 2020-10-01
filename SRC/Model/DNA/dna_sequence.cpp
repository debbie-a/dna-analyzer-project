#include "dna_sequence.h"


std::list<size_t> DNASequence::findAll(const std::string& subSequence) const
{
	std::list<size_t> indices;
	size_t index = 0;
	while ((index = find(subSequence,index)) != std::string::npos)
	{
		indices.push_back(index);
		index += 1;
	}
	return indices;
}


std::list<DNASequence> DNASequence::findConsensusSequences() const
{
	std::list<DNASequence> listConsensusSequences;
	std::list<size_t> listATG = findAll("ATG");
	std::list<size_t> listTAG = findAll("TAG");
	std::list<size_t> listTAA = findAll("TAA");
	std::list<size_t> listTGA = findAll("TGA");
	std::list<size_t>::iterator it1, it2;

	DNASequence tmp = getSequenceAsString();

	for (it1 = listATG.begin(); it1 != listATG.end(); ++it1)
	{	
		for (it2 = listTAG.begin(); it2 != listTAG.end(); ++it2)
		{
			if (((*it2 - *it1) % 3 == 0) && (*it2 > *it1))
				listConsensusSequences.push_back(DNASequence(tmp.slice(*it1, *it2 + 3)));
		}
	}
	for (it1 = listATG.begin(); it1 != listATG.end(); ++it1)
	{	
		for (it2 = listTAA.begin(); it2 != listTAA.end(); ++it2)
		{
			if (((*it2 - *it1) % 3 == 0) && (*it2 > *it1))
				listConsensusSequences.push_back(DNASequence(tmp.slice(*it1, *it2 + 3)));
		}
	}
	for (it1 = listATG.begin(); it1 != listATG.end(); ++it1)
	{	
		for (it2 = listTGA.begin(); it2 != listTGA.end(); ++it2)
		{
			if (((*it2 - *it1) % 3 == 0) && (*it2 > *it1))
				listConsensusSequences.push_back(DNASequence(tmp.slice(*it1, *it2 + 3)));
		}
	}

	return listConsensusSequences;		
}
