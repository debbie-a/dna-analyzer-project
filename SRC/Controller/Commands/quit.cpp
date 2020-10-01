#include "quit.h"
#include "../Utils/utils.h"


std::string Quit::execute(SharedPtr<IParams> params)
{
        return Utils::confirmation(m_reader, m_writer) ? "Thank you for using Dnanalyzer.\nGoodbye!" : "";
}

std::string Quit::getInfo()
{
	return "\nQuits the Dnanalyzer System\nAsks if he is sure he wants to quit, user must confirm with a 'y'/'Y' to quit or 'n'/'N' to cancel quitting.\n";
}

