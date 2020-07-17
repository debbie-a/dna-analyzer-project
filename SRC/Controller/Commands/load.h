#ifndef __LOAD_H__
#define __LOAD_H__

#include <fstream>
#include <sstream>
#include "new.h"
#include "../../Model/DNA/dna_collection.h"
#include "../../Model/Read/file_reader.h"


class Load : public ICommand
{

public:
	/*virtual*/std::string execute(const std::vector<std::string>& params, bool *flag);
};


inline std::string Load::execute(const std::vector<std::string>& params, bool *flag)
{
	//invalid number of arguments
	if(params.size() == 0 || params.size() > 2)
		throw std::runtime_error("invalid number of arguments");
	
	std::string name;
	
	//a name was given
	if(params.size() == 2)
	{
		name = params[1];
	}

	//one parameter was sent. need to create name out of file name
	else
	{	
		size_t i = params[0].find(".");

		if(i == std::string::npos)
			throw std::runtime_error("invalid file name");
	
		std::string tmp(params[0].begin(), params[0].begin() + i);
		name = "@" + tmp;
	}
	
	
	//reading from file
	SharedPtr<IRead> reader(new FileReader(params[0]));
	std::string seq = reader->read();

	//taking care of sequences longer than 40
	bool seqLongerThan40 = false;
	
	if(seq.length() > 40)
	{
		seqLongerThan40 = true;
		std::string first32(seq.begin(), seq.begin() + 35);
		std::string last3(seq.end() - 3, seq.end());
		first32 += "AAA" + last3; // just a placeholder soon will be changed to an ellipsis....
		
		seq = first32;
	}
	
	//creating new sequence
	SharedPtr<ICommand> new_(new New);
	std:: string output;
	std::vector<std::string> vec = {seq, name};
	output = new_->execute(vec, flag);

	//changing the "AAA" placeholder with an ellipsis
	if(seqLongerThan40)
	{
		output[output.length() - 4] = '.';
		output[output.length() - 5] = '.';
		output[output.length() - 6] = '.';
		
	}

	return output;
}


#endif /*__LOAD_H__*/
