#ifndef _MANAGERSERVICE_IMPL_H
#define _MANAGERSERVICE_IMPL_H
#include "managerservice.h"
#include "managerdao.h"
namespace emis {
class ManagerServiceImpl : public ManagerService {
public:
	ManagerServiceImpl (void);
	~ManagerServiceImpl (void);
	bool addManager (const Manager& manager);
	bool delManager (int id);
	vector<Manager>& listManager (void);
private:
	vector<Manager> managers;
	ManagerDao* dao;
};
}
#endif // _MANAGERSERVICE_IMPL_H
