#ifndef __CLI_H__
#define __CLI_H__

#include "ui.h"
#include "../MyLibrary/Read/console_reader.h"
#include "../MyLibrary/Write/console_writer.h"

class CLI : public UI
{
public:
	CLI();

	/*virtual*/ void run(const Callback<Controller>&);

	/*virtual*/ void show(const std::string&) const;

        /*virtual*/ std::string readInput() const;
        
        /*virtual*/ Args processInput(const std::string&) const;
	
private:
	InputProcessor m_inputProcessor;
	SharedPtr<IRead> m_reader;
	SharedPtr<IWrite> m_writer;

	void printWelcome() const;
        void printCursor() const;
        bool shouldQuit(const std::string&) const;
        void showOutput(const std::string&) const;
        void updateCache(const std::string&) const;
        void printGoodbye(const std::string&) const;
};


inline CLI::CLI():m_reader(new ConsoleReader),m_writer(new ConsoleWriter)
{
}

#endif /*__CLI_H__*/
