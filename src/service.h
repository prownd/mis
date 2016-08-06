#ifndef _SERVICE_H
#define _SERVICE_H
#include <vector>
using namespace std;
#include "department.h"
#include "employee.h"
namespace emis {
class Service {
public:
	virtual ~Service (void) {}
	virtual bool addDept (const Department& dept) = 0;
	virtual bool delDept (int nDeptId) = 0;
	virtual vector<Department>& lstDept (void) = 0;
	virtual bool addEmp (int nDeptId, const Employee& emp) = 0;
	virtual bool delEmp (int nEmpId) = 0;
	virtual bool modEmp (const Employee& emp) = 0;
	virtual vector<Employee> lstEmp (int nDeptId) = 0;
	virtual vector<Employee> lstAllEmp (void) = 0;
};
}
#endif // _SERVICE_H
