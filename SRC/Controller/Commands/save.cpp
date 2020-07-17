#include <string>
#include <sstream>
#include "save.h"
#include "../../Model/DNA/dna_collection.h"
#include "../../Model/Write/file_writer.h"
#include "../../Model/DNA/invalid_dna_data.h"

std::string Save::execute(const std::vector<std::string>& params, bool *flag)
{
	//invalid number of arguments
	if(params.size() == 0 || params.size() > 2)
		throw std::runtime_error("invalid number of arguments");

	std::string fileName;
	SharedPtr<DNAData> dnaData;
	
	//a file name was given
	if(params.size() == 2)
	{
		size_t i = params[1].find(".");

		if(i == std::string::npos)
			throw std::runtime_error("invalid file name");

		fileName = params[1];
	}

	//find the dnaSeq which needs to be saved
	if(params[0][0] == '#')
	{	
		size_t id;
		std::stringstream ss;
		std::string tmp(params[0].begin() + 1, params[0].end());
		ss <<  tmp;
		ss >> id;

		try
		{
			dnaData = DNACollection::getDNA(id);
		}
		catch(InvalidDNAData& e)
		{
			return e.what();
		}

	}
	else if(params[0][0] == '@')
	{
		std::string name(params[0].begin() + 1, params[0].end());
		try
		{
			dnaData = DNACollection::getDNA(name);
		}
		catch(InvalidDNAData& e)
		{
			return e.what();
		}
	}
	else 
	{
		throw std::runtime_error("invalid input");
	}
	
	//one parameter was sent. need to create file name out of seq name
	if(params.size() == 1)
		fileName = dnaData->getName() + ".txt";
	
	//writing to file
	SharedPtr<IWrite> writer(new FileWriter(fileName));
	writer->write((dnaData->getDNASeq())->getSequenceAsString());
	
	return "";
}

