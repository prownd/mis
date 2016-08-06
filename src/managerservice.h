#ifndef _MANAGERSERVICE_H
#define _MANAGERSERVICE_H
#include <vector>
using namespace std;
#include "manager.h"
namespace emis {
class ManagerService {
public:
	virtual ~ManagerService (void) {}
	virtual bool addManager (const Manager& manager) = 0;
	virtual bool delManager (int id) = 0;
	virtual vector<Manager>& listManager (void) = 0;
};
}
#endif // _MANAGERSERVICE_H
