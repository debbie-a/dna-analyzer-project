#include "auxiliary_functions.h"
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
