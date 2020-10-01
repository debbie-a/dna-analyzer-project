#include <sstream>
#include "len.h"
#include "../Utils/utils.h"


std::string Len::execute(SharedPtr<IParams> params)
{
	std::stringstream output;

        output << Utils::getDnaDataFromInput(params->m_params[0])->getDNASeq()->getLength();

	return output.str();
}

std::string Len::getInfo()
{
	return "\nGet Length of DNA Sequences\nGet length of a sequence by referring to it by its name or ID of the sequence.\n";
}

