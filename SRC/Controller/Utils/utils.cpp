#include <sstream>
#include <vector>
#include <string>
#include "utils.h"
#include "../../MyLibrary/Exceptions/invalid_arguments.h"
#include "../../MyLibrary/Exceptions/invalid_dna_data.h"
#include "../../MyLibrary/graphics.h"


SharedPtr<DNAData> Utils::getDnaDataFromInput(const std::string& str)
{
	if (isId(str))
	{
		return DNACollection::getDNA(getId(str));
	}
		
	else if (isName(str))
	{
		return DNACollection::getDNA(getName(str));
	}

	else 
	{
	        throw InvalidArguments("invalid input");
        }
}

bool Utils::isId(const std::string& str)
{
        return str[0] == ID_SYMBOL;
}

bool Utils::isName(const std::string& str)
{
        return str[0] == NAME_SYMBOL;
}

std::string Utils::getName(const std::string& str)
{
        if (!isName(str))
                throw InvalidArguments("invalid syntax");

	std::string tmp(str.begin() + 1, str.end());

	return tmp;
}

size_t Utils::getId(const std::string& str)
{
        if (!isId(str))
                throw InvalidArguments("invalid syntax");

	size_t id;
	std::stringstream ss;
	std::string tmp(str.begin() + 1, str.end());
	ss <<  tmp;
	ss >> id;

	return id;
}

std::string Utils::getSuffixedName(const std::string& str, const std::string& suffix)
{
	size_t counter = 0;
	std::stringstream ss;

	while (true)
	{
		ss.str("");
		ss << counter;

		try
		{
			if(!counter)
				DNACollection::getDNA(str);

			else
				DNACollection::getDNA(str + suffix + ss.str());

		}
		catch(InvalidDNAData& e)
		{
			break;
		}
		
		counter++;

	}
	return counter ? str + suffix + ss.str() : str;
}

std::string Utils::getOutput(size_t id, const std::string& name, const std::string& seq)
{
	std:: stringstream output;
	output << "[" << id << "] " <<  name << ": " << seq;

	return output.str();
}

std::string Utils::replaceLongSeqWithEllipsis(const std::string& str)
{
	size_t i = str.find(":");
	std::string tmp(str.begin(), str.begin() + i + 34);
	std::string last3(str.end() - 3, str.end());
	tmp += "..." + last3; 
	
	return tmp;
		
}


std::string Utils::getDefaultName(size_t *counter)
{
	std::stringstream ss;
	while (true)
	{
		ss.str("");
		ss << *counter;

		try
		{
			DNACollection::getDNA("seq" + ss.str());
		}
		catch(InvalidDNAData& e)
		{
			break;
		}
		(*counter)++;
	}

	return "seq" + ss.str();
}

std::string Utils::getValidNewName(const std::string& str)
{
	std::string name = Utils::getName(str);
		
	// names must be unique. check if name already exists
	try
	{
		DNACollection::getDNA(name);

		throw InvalidArguments("invalid name. name already exists");
	}
	catch(InvalidDNAData& e)
	{
	        // do nothing... name is unique
	}

        return name;
}

std::string Utils::getManipulationName(const std::string& str)
{
        if (isValidManipulationNewName(str))
                return str.substr(1, str.length() - 4);

        throw InvalidArguments("invalid syntax");
}

bool Utils::isValidManipulationNewName(const std::string& str)
{
        return (str[0] == NAME_SYMBOL) && (str[str.length() - 2] == NAME_SYMBOL) && (str[str.length() - 1] == NAME_SYMBOL) &&  (str[str.length() - 3] == '|');
}

bool Utils::isAutoGenerateName(const std::string& str)
{
        return str == "@@";
}

std::string Utils::getSubSeq(const std::string& str)
{
	if (isId(str))
	{
		return DNACollection::getDNA(getId(str))->getDNASeq()->getSequenceAsString();
	}
	else if (isName(str))
	{
		return DNACollection::getDNA(getName(str))->getDNASeq()->getSequenceAsString();
	}
	
	return str;
}

bool Utils::confirmation(const SharedPtr<IRead>& reader, const SharedPtr<IWrite>& writer) 
{
	
	writer->write("Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.");

	while (true)
	{
		std::string input;
		writer->write(std::string(BOLDCYAN) + "\n > confirm >>> " + RESET);

		input = reader->read();

		if (input == "n" || input == "N")
		{
			return false;
		}
		if (input == "y" || input == "Y")
		{

			return true;
		}
		else
		{
			writer->write("You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.");
		}
	}
	return false;
}






