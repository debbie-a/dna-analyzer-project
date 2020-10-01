#ifndef __DNA_SEQUENCE_H__
#define __DNA_SEQUENCE_H__
#include <string>
#include <cstring>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include "../../MyLibrary/Exceptions/invalid_nucleotide.h"


static bool isValidNucleotide(char type)
{
	const std::string nucleotide = "AGCTagct";
	return nucleotide.find(type) == std::string::npos ? false:true;
}

class DNASequence
{

private:
	class NucleotideType 
	{
	public:
		NucleotideType(char type);
		NucleotideType();
		NucleotideType& operator=(char);
		char getType() const;
		char getNucleotidePair() const;
		operator char();
		
	private:
		char m_type;
		
	};
	NucleotideType *m_sequence;
	size_t m_length;
	friend std::ostream& operator<<(std::ostream& cout, const DNASequence::NucleotideType& nucleotide);

public:
	DNASequence(const std::string &);
	DNASequence(const char*);
	DNASequence(std::fstream&);
	DNASequence(const DNASequence &);
	DNASequence& operator=(const DNASequence &);
	~DNASequence();

	std::string getSequenceAsString() const;
	size_t getLength() const;
	const NucleotideType& operator[](size_t) const;
	NucleotideType& operator[](size_t);
	void writeToFile(const std::string&);
	DNASequence slice(long int, long int);
	DNASequence pair();
	size_t find(const std::string&, size_t) const;
	size_t count(const std::string&) const;
	std::list<size_t> findAll(const std::string&) const;
	std::list<DNASequence> findConsensusSequences() const;

	
};

inline DNASequence::DNASequence(const std::string &sequence):m_sequence(new NucleotideType[sequence.length()]),m_length(sequence.length())
{
	try
	{
		for (size_t i = 0; i < sequence.length(); i++)
			m_sequence[i] = sequence.c_str()[i];
	}
	catch (InvalidNucleotide& e)
	{
		delete[] m_sequence;
		m_sequence = NULL;
		throw;
	}
}

inline DNASequence::DNASequence(const char *sequence):m_sequence(sequence != NULL? new NucleotideType[strlen(sequence)]:throw std::logic_error("null not valid")),m_length(strlen(sequence))
{	
	try
	{
		for(size_t i = 0; i < strlen(sequence); i++)
			m_sequence[i] = sequence[i];
	}
	catch(InvalidNucleotide& e)
	{
		delete[] m_sequence;
		m_sequence = NULL;
		throw;
	}
}

inline DNASequence::DNASequence(std::fstream& myfile):m_sequence(NULL),m_length(0)
{	
	std::string line;
	std::string sequenceFromFile;
	if (myfile.is_open())
 	{
   		while (getline(myfile,line))
   		{
      			sequenceFromFile += line;
    		}
    		myfile.close();
  	}
	else
	{
		throw std::ifstream::failure("opening file failed");
	}
	m_sequence =  new NucleotideType[sequenceFromFile.length()];
	m_length = sequenceFromFile.length();
	try
	{
		for(size_t i = 0; i < sequenceFromFile.length(); i++)
			m_sequence[i] = sequenceFromFile[i];
	}
	catch(InvalidNucleotide& e)
	{
		delete[] m_sequence;
		m_sequence = NULL;
		throw;
	}
}

inline DNASequence::DNASequence(const DNASequence& other):m_sequence(new NucleotideType[other.getLength()]),m_length(other.getLength())
{
	for(size_t i=0; i < other.getLength(); i++)
		m_sequence[i] = other.getSequenceAsString().c_str()[i];
}

inline DNASequence& DNASequence::operator=(const DNASequence &other)
{	
	if(this != &other)
	{
		NucleotideType *tmp = m_sequence;
		m_sequence = new NucleotideType[other.getLength()];
		delete[] tmp;
		for(size_t i=0; i < other.getLength(); i++)
			m_sequence[i] = NucleotideType(other.getSequenceAsString().c_str()[i]);;
	}

	return *this;
}

inline DNASequence::~DNASequence()
{
	delete[] m_sequence;
	m_sequence = NULL;
}

inline std::string DNASequence::getSequenceAsString() const
{
	std::string sequence;
	for(size_t i=0; i< getLength(); i++)
		sequence += (*this)[i].getType();

	return sequence;
}

inline size_t DNASequence::getLength() const
{
	return m_length;
}

inline const DNASequence::NucleotideType& DNASequence::operator[](size_t index) const
{
	if(index >= getLength())
	{
		throw std::out_of_range("bad index error");
	}

	return m_sequence[index];
}

inline DNASequence::NucleotideType& DNASequence::operator[](size_t index)
{
	if(index >= getLength())
	{
		throw std::out_of_range("bad index error");
	}

	return m_sequence[index];
}

inline void DNASequence::writeToFile(const std::string &fileName)
{
	std::ofstream myfile;
  	myfile.open(fileName.c_str());
	if (myfile.is_open()) 
  	{
		myfile << getSequenceAsString();
 		myfile.close();
	}
	else
	{
		throw std::ifstream::failure("opening file failed");
	}
}

inline DNASequence DNASequence::slice(long int start, long int end)
{
	if (start < 0)
		start = getLength() + start;

	if (end < 0)
		end = getLength() + end;

	if (((size_t)end > getLength()) || ((size_t)start >= getLength()) || (start > end))
		throw std::out_of_range("bad index error");

	std::string slicedSequence;
	for (size_t i = start; i < (size_t)end; i++)
		slicedSequence += m_sequence[i]; 
       
	return DNASequence(slicedSequence);		
		
}

inline DNASequence DNASequence::pair()
{
	std::string pairedSequence;
	for(size_t i = getLength(); i > 0; i--)
		pairedSequence += m_sequence[i - 1].getNucleotidePair(); 

	return DNASequence(pairedSequence);
}

inline size_t DNASequence::find(const std::string& subSequence, size_t startIndex = 0) const
{
	if (subSequence.length() > getSequenceAsString().length())
		return std::string::npos;

	for(size_t i = startIndex; i < getLength()- subSequence.length() + 1; i++)
	{
		DNASequence tmp = getSequenceAsString();
		if (tmp.slice(i, i + subSequence.length()).getSequenceAsString() == subSequence)
			return i;
	}

	return std::string::npos;
}

inline size_t DNASequence::count(const std::string& subSequence) const
{
	return findAll(subSequence).size();
}

inline DNASequence::NucleotideType::NucleotideType(char type):m_type(type)
{
	if (isValidNucleotide(type) == false)
	{
		throw InvalidNucleotide();
	}
}

inline DNASequence::NucleotideType::NucleotideType():m_type('\0')
{
}

inline DNASequence::NucleotideType& DNASequence::NucleotideType::operator=(char type)
{
	if (isValidNucleotide(type) == false)
	{
		throw InvalidNucleotide();
	}
	m_type = type;

	return *this;
}

inline char DNASequence::NucleotideType::getType() const
{
	return m_type;
}

inline char DNASequence::NucleotideType::getNucleotidePair() const
{
	static std::map<char, char> mapPairs;
	mapPairs['A'] = 'T';
	mapPairs['T'] = 'A';
	mapPairs['G'] = 'C';
	mapPairs['C'] = 'G';
	mapPairs['a'] = 't';
	mapPairs['t'] = 'a';
	mapPairs['g'] = 'c';
	mapPairs['c'] = 'g';
	

    return mapPairs[this->getType()];
}

inline DNASequence::NucleotideType::operator char()
{
	return m_type;
}

inline std::ostream& operator<<(std::ostream& cout, const DNASequence::NucleotideType& nucleotide)
{
	cout << nucleotide.getType();

	return cout;
}

inline std::ostream& operator<<(std::ostream& cout, const DNASequence& sequence)
{
	cout << sequence.getSequenceAsString();

    return cout;
}

inline bool operator==(const DNASequence& sequence1, const DNASequence& sequence2)
{
	return sequence1.getSequenceAsString() == sequence2.getSequenceAsString()? true:false;
}

inline bool operator!=(const DNASequence& sequence1, const DNASequence& sequence2)
{
    return !(sequence1 == sequence2);
}

#endif /*__DNA_SEQUENCE_H__*/
