#ifndef _SERVICEVIEW_CONSOLE_IMPL_H
#define _SERVICEVIEW_CONSOLE_IMPL_H
#include "serviceview.h"
#include "service.h"
namespace emis {
class ServiceViewConsoleImpl : public ServiceView {
public:
	ServiceViewConsoleImpl (void);
	~ServiceViewConsoleImpl (void);
	void menu (void);
	void addDept (void);
	void delDept (void);
	void lstDept (void);
	void addEmp (void);
	void delEmp (void);
	void modEmp (void);
	void lstEmp (void);
	void lstAllEmp (void);
private:
	int showMenu (void);
	Service* m_pService;
};
}
#endif // _SERVICEVIEW_CONSOLE_IMPL_H
