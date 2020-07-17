#include <sstream>
#include "new.h"
#include "../../Model/DNA/dna_collection.h"
#include "auxiliary_functions.h"



std::string New::execute(const std::vector<std::string>& params, bool *flag)
{
	//invalid number of arguments
	if(params.size() == 0 || params.size() > 2) 
		throw std::runtime_error("invalid number of arguments");

    	static size_t counter = 1;
    	std::string name;

	//a name was given
	if(params.size() == 2)
	{
		name = getName(params[1]);
	}
	//one parameter was sent. need to create default name
	else
	{
		std::stringstream ss;
		ss << counter;
		name = "seq" + ss.str();
		counter++; 
	}

	try
	{
		SharedPtr<DNAData> dnaData(new DNAData(params[0], name));
		DNACollection::addDNA(dnaData);

		std:: string output;
		output = getOutput(dnaData->getID(), name, params[0]);

		return output;
	}
	catch(InvalidNucleotide& e)
	{
		//if invalid seq was given we must decrement counter because DNASeq was not created!
		counter--;
		throw;
	}
	
}

