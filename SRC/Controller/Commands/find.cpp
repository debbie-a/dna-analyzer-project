#include <sstream>
#include "find.h"
#include "../Utils/utils.h"


std::string Find::execute(SharedPtr<IParams> params)
{
	std::stringstream output;
	
        // get sub-sequence to find in sequence
        size_t pos = Utils::getDnaDataFromInput(params->m_params[0])->getDNASeq()->find(Utils::getSubSeq(params->m_params[1]));
		
	output << pos;

	return pos != std::string::npos ? output.str() : "sub-sequence not found in sequence";
} 

std::string Find::getInfo()
{
	return "\nFind a SubSequences in DNA Sequences\nReturns the (0-based) index of the first appearance of a sub-sequence in a DNA sequence.\n";
}

