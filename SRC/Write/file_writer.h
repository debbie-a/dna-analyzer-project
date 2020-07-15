#ifndef __FILE_WRITER_H__
#define __FILE_WRITER_H__

#include <iostream>
#include <fstream>
#include "iwrite.h"

class FileWriter : public IWrite
{

public:
	FileWriter(const std::string& fileName);

	/*virtual*/void write(const std::string& str);

private:
	std::string m_fileName;
};

inline FileWriter::FileWriter(const std::string& fileName):m_fileName(fileName)
{
}

inline void FileWriter::write(const std::string& str)
{
	std::ofstream myfile;
  	myfile.open(m_fileName.c_str());
	if (myfile.is_open()) 
  	{
		myfile << str;
 		myfile.close();
	}
	else
	{
		throw std::ifstream::failure("opening file failed");
	}
    	
}

#endif /*__FILE_WRITER_H__*/
