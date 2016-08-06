#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "serviceview_console_impl.h"
#include "service_impl.h"
namespace emis {
ServiceViewConsoleImpl::ServiceViewConsoleImpl (void) : m_pService (new ServiceImpl) {
}
ServiceViewConsoleImpl::~ServiceViewConsoleImpl (void) {
	if (m_pService) {
		delete m_pService;
		m_pService = NULL;
	}
}
void ServiceViewConsoleImpl::menu (void) {
	for (;;)
		switch (showMenu ()) {
			case 1:
				addDept ();
				break;
			case 2:
				delDept ();
				break;
			case 3:
				lstDept ();
				break;
			case 4:
				addEmp ();
				break;
			case 5:
				delEmp ();
				break;
			case 6:
				modEmp ();
				break;
			case 7:
				lstEmp ();
				break;
			case 8:
				lstAllEmp ();
				break;
			case 0:
				return;
			default:
				cout << endl << "select error!" << endl;
				break;
		}
}
void ServiceViewConsoleImpl::addDept (void) {
	Department dept;
	cout << endl << "please input department name:" << flush;
	cin >> dept.m_strName;
	if (! m_pService -> addDept (dept))
		cout << "add department fail!" << endl;
	else
		cout << "add department success!" << endl;
}
void ServiceViewConsoleImpl::delDept (void) {
	cout << endl << "please input department id£º" << flush;
	int nDeptId = -1;
	cin >> nDeptId;
	if (! m_pService -> delDept (nDeptId)) {
		cout << "invalid departmentID!" << endl;
		cin.clear ();
		cin.ignore (1024, '\n');
	}
	else
		cout << "delete department success!" << endl;
}
void ServiceViewConsoleImpl::lstDept (void) {
	vector<Department>& vecDepts = m_pService -> lstDept ();
	cout << endl << left << setw (11) << "department ID" << setw (22) << "department name" << "employees" << endl;
	cout << "-----------------------------------------" << endl;
	for (vector<Department>::iterator it = vecDepts.begin (); it != vecDepts.end (); it++)
		cout << setw (11) << it -> m_nId << setw (22) << it -> m_strName << it -> m_vecEmps.size () << endl;
}
void ServiceViewConsoleImpl::addEmp (void) {
	Employee emp;
	cout << endl << "please input employee name£º" << flush;
	cin >> emp.m_strName;
	cout << "please input employee gender£º" << flush;
	cin >> emp.m_bGender;
	cout << "please input employee age£º" << flush;
	cin >> emp.m_nAge;
	cout << "please input department ID£º" << flush;
	int nDeptId = -1;
	cin >> nDeptId;
	if (! m_pService -> addEmp (nDeptId, emp)) {
		cout << "invalid departmentID!" << endl;
		cin.clear ();
		cin.ignore (1024, '\n');
	}
	else
		cout << "add employee success!" << endl;
}
void ServiceViewConsoleImpl::delEmp (void) {
	cout << endl << "please input employee ID£º" << flush;
	int nEmpId = -1;
	cin >> nEmpId;
	if (! m_pService -> delEmp (nEmpId)) {
		cout << "invalid employee ID!" << endl;
		cin.clear ();
		cin.ignore (1024, '\n');
	}
	else
		cout << "delete employee success!" << endl;
}
void ServiceViewConsoleImpl::modEmp (void) {
	Employee emp (0);
	cout << endl << "please input employee ID:" << flush;
	cin >> emp.m_nId;
	cout << "please input employee name:" << flush;
	cin >> emp.m_strName;
	cout << "please input employee gender:" << flush;
	cin >> emp.m_bGender;
	cout << "please input employee age:" << flush;
	cin >> emp.m_nAge;
	if (! m_pService -> modEmp (emp)) {
		cout << "invalid employee ID!" << endl;
		cin.clear ();
		cin.ignore (1024, '\n');
	}
	else
		cout << "modify employee information success!" << endl;
}
void ServiceViewConsoleImpl::lstEmp (void) {
	cout << endl << "please input department ID£º" << flush;
	int nDeptId = -1;
	cin >> nDeptId;
	try {
		vector<Employee> vecEmps = m_pService -> lstEmp (nDeptId);
		cout << endl << left << setw (11) << "employee ID" << setw (22) << "name" << setw (9) << "gender" << "age" << endl;
		cout << "----------------------------------------------" << endl;
		for (vector<Employee>::iterator it = vecEmps.begin (); it != vecEmps.end (); it++)
			cout << setw (11) << it -> m_nId << setw (22) << it -> m_strName << setw (9) << (it -> m_bGender ? "male" : "female") << it -> m_nAge << endl;
	}
	catch (int ex) {
		cout << "invalid department ID!" << endl;
		cin.clear ();
		cin.ignore (1024, '\n');
	}
}
void ServiceViewConsoleImpl::lstAllEmp (void) {
	vector<Employee> vecEmps = m_pService -> lstAllEmp ();
	cout << endl << left << setw (11) << "employee ID" << setw (22) << "name" << setw (9) << "gender" << "age" << endl;
	cout << "----------------------------------------------" << endl;
	for (vector<Employee>::iterator it = vecEmps.begin (); it != vecEmps.end (); it++)
		cout << setw (11) << it -> m_nId << setw (22) << it -> m_strName << setw (9) << (it -> m_bGender ? "male" : "female") << it -> m_nAge << endl;
}
int ServiceViewConsoleImpl::showMenu (void) {
	cout << endl;
	cout << "operation management subsystem" << endl;
	cout << "----------------" << endl;
	cout << "[1] add department " << endl;
	cout << "[2] delete department" << endl;
	cout << "[3] list department" << endl;
	cout << "[4] add employee " << endl;
	cout << "[5] delete employee " << endl;
	cout << "[6] modify employee information " << endl;
	cout << "[7] list department employee " << endl;
	cout << "[8] list all employee " << endl;
	cout << "[0] return" << endl;
	cout << "----------------" << endl;
	cout << "please select:" << flush;
	cin.clear ();
	string strEnter;
	cin >> strEnter;
	if (strspn (strEnter.c_str (), "012345678") == strEnter.length ()) {
		istringstream iss (strEnter);
		int nEnter = -1;
		iss >> nEnter;
		return nEnter;
	}
	return -1;
}
}
