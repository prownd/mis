#include "employee.h"
#include "tools.h"
namespace emis {
Employee::Employee (void) : m_nId (generator_id ()) {
}
Employee::Employee (int) {
}
istream& operator>> (istream& is, Employee& emp) {
	return is >> emp.m_nId >> emp.m_strName >> emp.m_bGender >> emp.m_nAge;
}
ostream& operator<< (ostream& os, const Employee& emp) {
	return os << emp.m_nId << ' ' << emp.m_strName << ' ' << emp.m_bGender << ' ' << emp.m_nAge;
}
}
