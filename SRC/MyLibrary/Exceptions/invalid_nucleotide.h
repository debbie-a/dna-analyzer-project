#ifndef __INVALID_NUCLEOTIDE_H__
#define __INVALID_NUCLEOTIDE_H__
#include <stdexcept>


class InvalidNucleotide: public std::runtime_error
{
public:
	InvalidNucleotide();
	/*virtual*/ const char* what() const throw();
   
};

inline InvalidNucleotide::InvalidNucleotide():std::runtime_error("")
{
}

inline const char* InvalidNucleotide::what() const throw()
{
        return "invalid DNA sequence";
}

#endif /*__INVALID_NUCLEOTIDE_H__*/
