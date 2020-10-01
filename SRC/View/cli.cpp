#include <iostream>
#include "cli.h"
#include "cache.h"
#include "../MyLibrary/Exceptions/invalid_command.h"
#include "../MyLibrary/Exceptions/invalid_arguments.h"
#include "../MyLibrary/Exceptions/invalid_dna_data.h"
#include "../MyLibrary/Exceptions/invalid_nucleotide.h"
#include "../MyLibrary/graphics.h"


void CLI::run(const Callback<Controller> &callBack)
{
	printWelcome();

	while (true)
	{
		try
		{
			std::string input, output;

			printCursor();

			input = readInput();

			if (!input.empty())
			{
                                Args args = processInput(input);

				output = callBack(args.command, args.params);
	
				if (!output.empty())
				{
				        if (shouldQuit(args.command))
					{
						printGoodbye(output);
						break;
					}

                                        updateCache(output);
                                	showOutput(output);
				}
			}
		}
		catch(const InvalidCommand& e)
		{
			showOutput(e.what());
		}
		catch(const InvalidArguments& e)
		{
			showOutput(e.what());
		}
                catch(const InvalidDNAData& e)
	        {
		        showOutput(e.what());
	        }
                catch(const InvalidNucleotide& e)
	        {
		        showOutput(e.what());
	        }
		catch(const std::runtime_error& e)
		{
		        showOutput(e.what());
		}

	}
}

void CLI::printWelcome() const
{
	m_writer->write(clear()); 
	m_writer->write(BOLDYELLOW);
    	m_writer->write("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
   	m_writer->write("\n         Welcome to Dnanalyzer System\n");         
	m_writer->write("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n"); 

}

void CLI::printCursor() const
{
        m_writer->write(BOLDCYAN);
	m_writer->write(" > cmd >>> ");
	m_writer->write(RESET);
}

std::string CLI::readInput() const
{
        return m_reader->read();
}

Args CLI::processInput(const std::string &str) const
{
        return m_inputProcessor.processInput(str);
}

void CLI::show(const std::string &str) const
{
	m_writer->write(str + "\n\n");
}

void CLI::showOutput(const std::string &str) const
{
	show(std::string(BOLDGREEN) + str);
}

void CLI::updateCache(const std::string &str) const
{
        if (str[0] == '[' && str[2] == ']')
        {
                std::stringstream ss;
                ss << str[1];
                size_t id;
                ss >> id;
                Cache::updateSequenceIdentifier(id);
        }

        if (str.find("Deleted: ") == 0)
        {
                size_t index = str.find("[");
                std::stringstream ss;
                ss << str[index + 1];
                size_t id;
                ss >> id;
                Cache::removeSequenceIdentifier(id);
        }
}

void CLI::printGoodbye(const std::string &str) const
{
	show(std::string(BOLDYELLOW) + str);
}

bool CLI::shouldQuit(const std::string &str) const
{
        return str == "quit";
}

