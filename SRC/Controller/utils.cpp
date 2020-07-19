#include "utils.h"
#include <stdexcept>
#include <sstream>


std::string getName(std::string str)
{
	if(str[0] != '@')
			throw std::runtime_error("invalid name");

	std::string tmp(str.begin() + 1, str.end());
	return tmp;
}

std::string getOutput(size_t id, std::string name, std::string seq)
{
	std:: stringstream output;
	output << "[" << id << "] " <<  name << ": " << seq;

	return output.str();
}

std::vector<std::string> parseString(const std::string& s)
{
	std::vector<std::string> vec;
	std::istringstream ss(s); 
    	while (ss)
	{ 
        	std::string word; 
        	ss >> word;
		vec.push_back(word);
	}

	return vec;
   
}
