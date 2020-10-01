#ifndef __GUI_H__
#define __GUI_H__

#include "ui.h"

//TODO implement a gui

class GUI : public UI
{
public:

	/*virtual*/ void run(const Callback<Controller>&);

	/*virtual*/ void show(const std::string&) const;

        /*virtual*/ std::string readInput() const;

        /*virtual*/ Args processInput(const std::string&) const;
};

#endif /*__GUI_H__*/
