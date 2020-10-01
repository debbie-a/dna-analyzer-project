#include <sstream>
#include "new.h"
#include "../Utils/utils.h"
#include "../../Model/DNA/dna_collection.h"
#include "../../MyLibrary/Exceptions/invalid_dna_data.h"


std::string New::execute(SharedPtr<IParams> params)
{
        static size_t counter = 1;
    	std::string name;

	// a name was given
	if (params->m_params.size() == 2)
	{
                name = params->m_params[1];
	}

	// one parameter was sent. need to create default name
	else
	{
		std::stringstream ss;
		ss << counter;
		name = Utils::getDefaultName(&counter);
		counter++; 
	}

	try
	{
		SharedPtr<DNAData> dnaData(new DNAData(params->m_params[0], name));
		DNACollection::addDNA(dnaData);

		return Utils::getOutput(dnaData->getID(), name, params->m_params[0]);
	}
	catch(InvalidNucleotide& e)
	{
		// if invalid seq was given we must decrement counter because DNASeq was not created
		counter--;
		throw;
	}

        return "";
}

std::string New::getInfo()
{
	return "\nCreates New DNA Sequences\nUser enters the sequence to be created, and a new sequence is created and added to the system.\nA default name will be given to sequence if not specified otherwise.\n";
}

