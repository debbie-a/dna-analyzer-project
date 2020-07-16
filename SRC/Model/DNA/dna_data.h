#ifndef __DNA_DATA_H__
#define __DNA_DATA_H__

#include <string>
#include "dna_sequence.h"
#include "../shared_pointer.h"


class DNAData
{
public:
	DNAData(std::string sequence, std::string name);
	DNAData(std::fstream& fileName, std::string name);

	SharedPtr<DNASequence> getDNASeq() const;
	std::string getName() const;
	size_t getID() const;

private:
	SharedPtr<DNASequence> m_dnaSeq;
	std::string m_name;
	size_t m_id;
	static size_t idCounter;
};

inline DNAData::DNAData(std::string sequence, std::string name):m_dnaSeq(new DNASequence(sequence)),m_name(name),m_id(idCounter)
{
	idCounter++;
}

inline DNAData::DNAData(std::fstream& fileName, std::string name):m_dnaSeq(new DNASequence(fileName)),m_name(name),m_id(idCounter)
{
	idCounter++;
}

inline SharedPtr<DNASequence> DNAData::getDNASeq() const
{
	return m_dnaSeq;
}

inline std::string DNAData::getName() const
{
	return m_name;
}

inline size_t DNAData::getID() const
{
	return m_id;
}


#endif /*__DNA_DATA_H__*/


