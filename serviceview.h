#ifndef _SERVICEVIEW_H
#define _SERVICEVIEW_H
namespace emis {
class ServiceView {
public:
	virtual ~ServiceView (void) {}
	virtual void menu (void) = 0;
	virtual void addDept (void) = 0;
	virtual void delDept (void) = 0;
	virtual void lstDept (void) = 0;
	virtual void addEmp (void) = 0;
	virtual void delEmp (void) = 0;
	virtual void modEmp (void) = 0;
	virtual void lstEmp (void) = 0;
	virtual void lstAllEmp (void) = 0;
};
}
#endif // _SERVICEVIEW_H
