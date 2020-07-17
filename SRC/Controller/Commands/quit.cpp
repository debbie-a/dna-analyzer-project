#include <cstdio>
#include <iostream>
#include "quit.h"

std::string Quit::execute(const std::vector<std::string>& params, bool *flag)
{
	std::cout << "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'." << std::endl;
	while(true)
	{
		std::string input;
		std::cout << " > confirm >>> " ;
		getline(std::cin, input);
		if(input == "n" || input == "N")
		{
			return "";
		}
		if(input == "y" || input == "Y")
		{
			*flag = false;
			return "Thank you for using Dnalanyzer.\nGoodbye!";
		}
		else
		{
			std::cout << "You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'." << std::endl;
		}
	}
	
}

