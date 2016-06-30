#include "managerservice_impl.h"
#include "managerdao_file_impl.h"
namespace emis {
ManagerServiceImpl::ManagerServiceImpl (void) {
	if (dao = new ManagerDaoFileImpl)
		dao -> load (managers);
}
ManagerServiceImpl::~ManagerServiceImpl (void) {
	if (dao) {
		dao -> save (managers);
		delete dao;
		dao = NULL;
	}
}
bool ManagerServiceImpl::addManager(const Manager& manager) {
	managers.push_back (manager);
	return true;
}
bool ManagerServiceImpl::delManager (int id) {
	for (vector<Manager>::iterator it = managers.begin (); it != managers.end (); it++)
		if (it -> getId () == id) {
			managers.erase (it);
			return true;
		}
	return false;
}
vector<Manager>& ManagerServiceImpl::listManager (void) {
	return managers;
}
}
