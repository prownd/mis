#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "employee.h"
namespace emis {
class Department {
public:
	Department (void);
	Department (int);
	bool delEmp (int nEmpId);
	void lstEmp (vector<Employee>& vecEmps);
	bool modEmp (const Employee& emp);
	friend istream& operator>> (istream& is, Department& dept);
	friend ostream& operator<< (ostream& os, const Department& dept);
	int m_nId;
	string m_strName;
	vector<Employee> m_vecEmps;
};
}
#endif // _DEPARTMENT_H
