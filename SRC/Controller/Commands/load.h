#ifndef __LOAD_H__
#define __LOAD_H__

#include <fstream>
#include <sstream>
#include "icommand.h"
#include "../../Model/DNA/dna_collection.h"

class Load : public ICommand
{

public:
	/*virtual*/std::string execute(const std::vector<std::string>& params, bool *flag);
};


inline std::string Load::execute(const std::vector<std::string>& params, bool *flag)
{
	if(params.size() == 0 || params.size() > 2)
		throw std::runtime_error("invalid number of arguments");
	
	std::string name;

	if(params.size() == 1)
	{	
		size_t i = 0;
		while(params[0] != ".")
		{	
			i++;
		}
		std::string tmp(params[0].begin(), params[1].begin() + i);
		name = tmp;
	}

	if(params.size() == 2)
	{
		if(params[1][0] != '@')
			throw std::runtime_error("invalid name");

		std::string tmp(params[1].begin() + 1, params[1].end());
		name = tmp;
	}
	
	std::fstream fileName(params[0]);
	SharedPtr<DNAData> dnaData(new DNAData(fileName, params[1]));

	std::string seq; //TODO get Sequence if longer than 49 take care...
	/*if(seq > 40)
	{
		std::string first32(seq.begin(), seq.begin() + 32);
		std::string last3(seq.end() - 3, seq.end());
		first32 += "..." + last3;
		
		seq = first32;
	}*/

	std:: stringstream output;
	output << "[" << dnaData ->getID() << "] " << name <<  ": " << seq;

	return output.str();
}


#endif /*__LOAD_H__*/
