#include "service_impl.h"
#include "servicedao_file_impl.h"
namespace emis {
ServiceImpl::ServiceImpl (void) : m_pDao (new ServiceDaoFileImpl) {
	if (m_pDao)
		m_pDao -> load (m_vecDepts);
}
ServiceImpl::~ServiceImpl (void) {
	if (m_pDao) {
		m_pDao -> save (m_vecDepts);
		delete m_pDao;
		m_pDao = NULL;
	}
}
bool ServiceImpl::addDept (const Department& dept) {
	m_vecDepts.push_back (dept);
	return true;
}
bool ServiceImpl::delDept (int nDeptId) {
	for (vector<Department>::iterator it = m_vecDepts.begin (); it != m_vecDepts.end (); it++)
		if (it -> m_nId == nDeptId) {
			m_vecDepts.erase (it);
			return true;
		}
	return false;
}
vector<Department>& ServiceImpl::lstDept (void) {
	return m_vecDepts;
}
bool ServiceImpl::addEmp (int nDeptId, const Employee& emp){
	for (vector<Department>::iterator it = m_vecDepts.begin (); it != m_vecDepts.end (); it++)
		if (it -> m_nId == nDeptId) {
			it -> m_vecEmps.push_back (emp);
			return true;
		}
	return false;
}
bool ServiceImpl::delEmp (int nEmpId) {
	for (vector<Department>::iterator it = m_vecDepts.begin (); it != m_vecDepts.end (); it++)
		if (it -> delEmp (nEmpId))
			return true;
	return false;
}
bool ServiceImpl::modEmp (const Employee& emp) {
	for (vector<Department>::iterator it = m_vecDepts.begin (); it != m_vecDepts.end (); it++)
		if (it -> modEmp (emp))
			return true;
	return false;
}
vector<Employee> ServiceImpl::lstEmp (int nDeptId) {
	for (vector<Department>::iterator it = m_vecDepts.begin (); it != m_vecDepts.end (); it++)
		if (it -> m_nId == nDeptId)
			return it -> m_vecEmps;
	throw -1;
}
vector<Employee> ServiceImpl::lstAllEmp (void) {
	vector<Employee> vecEmps;
	for (vector<Department>::iterator it = m_vecDepts.begin (); it != m_vecDepts.end (); it++)
		it -> lstEmp (vecEmps);
	return vecEmps;
}
}
