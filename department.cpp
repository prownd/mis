#include "department.h"
#include "tools.h"
namespace emis {
Department::Department (void) : m_nId (generator_id ()) {
}
Department::Department (int) {
}
bool Department::delEmp (int nEmpId) {
	for (vector<Employee>::iterator it = m_vecEmps.begin (); it != m_vecEmps.end (); it++)
		if (it -> m_nId == nEmpId) {
			m_vecEmps.erase (it);
			return true;
		}
	return false;
}
void Department::lstEmp (vector<Employee>& vecEmps) {
	for (vector<Employee>::iterator it = m_vecEmps.begin (); it != m_vecEmps.end (); it++)
		vecEmps.push_back (*it);
}
bool Department::modEmp (const Employee& emp) {
	for (vector<Employee>::iterator it = m_vecEmps.begin (); it != m_vecEmps.end (); it++)
		if (it -> m_nId == emp.m_nId) {
			it -> m_strName = emp.m_strName;
			it -> m_bGender = emp.m_bGender;
			it -> m_nAge = emp.m_nAge;
			return true;
		}
	return false;
}
istream& operator>> (istream& is, Department& dept) {
	size_t uEmps = 0;
	is >> dept.m_nId >> dept.m_strName >> uEmps;
	dept.m_vecEmps.clear ();
	for (size_t i = 0; i < uEmps; i++) {
		Employee emp (0);
		is >> emp;
		dept.m_vecEmps.push_back (emp);
	}
	return is;
}
ostream& operator<< (ostream& os, const Department& dept) {
	os << dept.m_nId << ' ' << dept.m_strName << ' ' << dept.m_vecEmps.size () << endl;
	for (vector<Employee>::const_iterator it = dept.m_vecEmps.begin (); it != dept.m_vecEmps.end (); it++)
		os << *it << endl;
	return os;
}
}
