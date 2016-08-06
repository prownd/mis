#ifndef _SERVICE_IMPL_H
#define _SERVICE_IMPL_H
#include "service.h"
#include "servicedao.h"
namespace emis {
class ServiceImpl : public Service {
public:
	ServiceImpl (void);
	~ServiceImpl (void);
	bool addDept (const Department& dept);
	bool delDept (int nDeptId);
	vector<Department>& lstDept (void);
	bool addEmp (int nDeptId, const Employee& emp);
	bool delEmp (int nEmpId);
	bool modEmp (const Employee& emp);
	vector<Employee> lstEmp (int nDeptId);
	vector<Employee> lstAllEmp (void);
private:
	vector<Department> m_vecDepts;
	ServiceDao* m_pDao;
};
}
#endif // _SERVICE_IMPL_H
