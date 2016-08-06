#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;
namespace emis {
class Employee {
public:
	Employee (void);
	Employee (int);
	friend istream& operator>> (istream& is, Employee& emp);
	friend ostream& operator<< (ostream& os, const Employee& emp);
	int m_nId;
	string m_strName;
	bool m_bGender;
	int m_nAge;
};
}
#endif // _EMPLOYEE_H
