#ifndef __UI_H__
#define __UI_H__

#include <string>
#include "../MyLibrary/shared_pointer.h"
#include "../Controller/callback.h"
#include "input_processor.h"

class Controller;


class UI
{
public:
    	virtual ~UI(){}

	virtual void run(const Callback<Controller>&) = 0;

	virtual void show(const std::string&) const = 0;
        
	virtual std::string readInput() const = 0;

	virtual Args processInput(const std::string&) const = 0;
	
};

#endif /*__UI_H__*/
