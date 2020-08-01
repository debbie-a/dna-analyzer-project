#ifndef __IVIEW_LOGIC_H__
#define __IVIEW_LOGIC_H__

class IViewLogic
{

public:
	virtual ~IViewLogic(){}

	virtual void executeCommands() = 0;
};

#endif /*__IVIEW_LOGIC_H__*/
