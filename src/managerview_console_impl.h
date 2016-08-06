#ifndef _MANAGERVIEW_CONSOLE_IMPL_H
#define _MANAGERVIEW_CONSOLE_IMPL_H
#include "managerview.h"
#include "managerservice.h"
namespace emis {
class ManagerViewConsoleImpl : public ManagerView {
public:
	ManagerViewConsoleImpl (void);
	~ManagerViewConsoleImpl (void);
	void menu (void);
	void add (void);
	void del (void);
	void list (void);
private:
	int showMenu (void);
	ManagerService* service;
};
}
#endif // _MANAGERVIEW_CONSOLE_IMPL_H
