#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include <iostream>
#include <fstream>
#include "iread.h"

class FileReader : public IRead
{

public:
	FileReader(const std::string& fileName);

	/*virtual*/std::string read() const;

private:
	std::string m_fileName;
};

inline FileReader::FileReader(const std::string& fileName):m_fileName(fileName)
{
}

inline std::string FileReader::read() const
{
	std::ifstream myFile(m_fileName.c_str());
	std::string line;
	std::string inputFromFile; 
	if (myFile.is_open())
 	{
   		while (getline(myFile,line))
   		{
      			inputFromFile += line;
    		}
    		myFile.close();
  	}
	else
	{
		throw std::ifstream::failure("opening file failed");
	}

	return inputFromFile;
}

#endif /*__FILE_READER_H__*/
