#ifndef _MANAGERVIEW_H
#define _MANAGERVIEW_H
namespace emis {
class ManagerView {
public:
	virtual ~ManagerView (void) {}
	virtual void menu (void) = 0;
	virtual void add (void) = 0;
	virtual void del (void) = 0;
	virtual void list (void) = 0;
};
}
#endif // _MANAGERVIEW_H
