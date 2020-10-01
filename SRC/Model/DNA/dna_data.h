#ifndef __DNA_DATA_H__
#define __DNA_DATA_H__

#include <string>
#include <vector>
#include "dna_sequence.h"
#include "../../MyLibrary/shared_pointer.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"

class DNAData
{
public:
	DNAData(const std::string&, const std::string&);
        DNAData(const std::string&, const std::string&, size_t);

	SharedPtr<DNASequence> getDNASeq() const;
	std::string getName() const;
	size_t getID() const;

private:
	SharedPtr<DNASequence> m_dnaSeq;
	std::string m_name;
	size_t m_id;
	static size_t idCounter;
        static std::vector<bool> idsTaken;
};


inline DNAData::DNAData(const std::string& sequence, const std::string& name):m_dnaSeq(new DNASequence(sequence)),m_name(name)
{
        while (idsTaken[idCounter] == true)
        {
                idCounter++;
               
        }
        m_id = idCounter;
        idsTaken[idCounter] = true;
	idCounter++;
}

inline DNAData::DNAData(const std::string& sequence, const std::string& name, size_t id):m_dnaSeq(new DNASequence(sequence)),m_name(name),m_id(idsTaken[id] == true ? id : throw InvalidArguments("invalid id. id already exists"))
{
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


