#include <fstream>
#include <sstream>
#include "load.h"
#include "new.h"
#include "../../Model/DNA/dna_collection.h"
#include "../../Model/Read/file_reader.h"
#include "invalid_arguments.h"
#include "../utils.h"



std::string Load::execute(const std::vector<std::string>& params, bool *flag)
{
	//invalid number of arguments
	if(params.size() == 0 || params.size() > 2)
		throw InvalidArguments("invalid number of arguments");
	
	std::string name;
	
	//a name was given
	if(params.size() == 2)
	{
		
		size_t i = params[0].find(".");

		if(i == std::string::npos)
			throw InvalidArguments("invalid file name");

		name = params[1];
	}

	//one parameter was sent. need to create name out of file name
	else
	{	
		size_t i = params[0].find(".");
		//size_t counter = 0;

		if(i == std::string::npos)
			throw InvalidArguments("invalid file name");
	
		std::string tmp(params[0].begin(), params[0].begin() + i);

		//get name from file name. if name already exists - postfix name with serial number
		tmp = getNameFromFileName(tmp);
		
		name = "@" + tmp;
	}
	
	
	//reading from file
	SharedPtr<IRead> reader(new FileReader(params[0]));
	std::string seq = reader->read();

	//creating new sequence
	SharedPtr<ICommand> new_(new New);
	std:: string output;

	std::string tmp[] = {seq, name};
	std::vector<std::string> vec(tmp, tmp + sizeof(tmp)/sizeof(tmp[0]));
	
	output = new_->execute(vec, flag);

	//if seq longer than 40 need to replace some with an ellipsis
	if(seq.length() > 40)
	{
		size_t i = output.find(":");
		std::string tmp(output.begin(), output.begin() + i + 34);
		std::string last3(output.end() - 3, output.end());
		tmp += "..." + last3; 
		
		output = tmp;
	}

	return output;
}


