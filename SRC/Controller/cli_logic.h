#ifndef __CLI_LOGIC_H__
#define __CLI_LOGIC_H__

#include "../Model/Read/iread.h"
#include "../View/cli.h"
#include "shared_pointer.h"
#include "iview_logic.h"


class CliLogic : public IViewLogic
{

public:
	CliLogic(const SharedPtr<IView>& viewer, const SharedPtr<IRead>& reader);
	
	/*virtual*/ void executeCommands();

private:
	SharedPtr<IView> m_viewer;
	SharedPtr<IRead> m_reader;
	
};

inline CliLogic::CliLogic(const SharedPtr<IView>& viewer, const SharedPtr<IRead>& reader):m_viewer(viewer),m_reader(reader)
{
}


#endif /*__CLI_LOGIC_H__*/
