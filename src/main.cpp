#include "managerview_console_impl.h"
using namespace emis;
int main (void) {
	ManagerView* pView = new ManagerViewConsoleImpl;
	pView -> menu ();
	delete pView;
	return 0;
}
