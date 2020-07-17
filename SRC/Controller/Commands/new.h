#ifndef __NEW_H__
#define __NEW_H__

#include <sstream>
#include <stdexcept>
#include "icommand.h"
#include "../../Model/DNA/dna_collection.h"

class New : public ICommand
{

public:
	/*virtual*/std::string execute(const std::vector<std::string>& params, bool *flag);
};


inline std::string New::execute(const std::vector<std::string>& params, bool *flag)
{

	if(params.size() == 0 || params.size() > 2) 
		throw std::runtime_error("invalid number of arguments");

    	static size_t counter = 1;
    	std::string name;

	if(params.size() == 2)
	{
		if(params[1][0] != '@')
			throw std::runtime_error("invalid name");

		std::string tmp(params[1].begin() + 1, params[1].end());
		name = tmp;
	}
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
		std:: stringstream output;
		output << "[" << dnaData ->getID() << "] " <<  name << ": " << params[0];

		return output.str();
	}
	catch(InvalidNucleotide& e)
	{
		counter--;
		throw;
	}
	
}


#endif /*__NEW_H__*/
