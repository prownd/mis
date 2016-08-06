#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include "managerview_console_impl.h"
#include "managerservice_impl.h"
#include "serviceview_console_impl.h"
namespace emis {
ManagerViewConsoleImpl::ManagerViewConsoleImpl (void) {
	service = new ManagerServiceImpl;
}
ManagerViewConsoleImpl::~ManagerViewConsoleImpl (void) {
	if (service) {
		delete service;
		service = NULL;
	}
}
void ManagerViewConsoleImpl::menu (void) {
	for (;;)
		switch (showMenu ()) {
			case 1:
				add ();
				break;
			case 2:
				del ();
				break;
			case 3:
				list ();
				break;
			case 4: {
				ServiceView *pView = new ServiceViewConsoleImpl;
				pView -> menu ();
				delete pView;
				break;
			}
			case 0:
				cout << endl << "thanks , goodbye!" << endl << endl;
				return;
			default:
				cout << endl << "select error" << endl;
				break;
		}
}
void ManagerViewConsoleImpl::add (void) {
	Manager m;
	cout << endl << "please input manager username:" << flush;
	char buf[20];
	cin >> buf;
	m.setName (buf);
	cout << "input manager password:" << flush;
	cin >> buf;
	m.setPassword (buf);
	if (! service -> addManager (m))
		cout << "add manager fail!" << endl;
	else
		cout << "add manager success" << endl;
}
void ManagerViewConsoleImpl::del (void) {
	cout << endl << "please input manager id:" << flush;
	int id = -1;
	cin >> id;
	if (! service -> delManager (id)) {
		cout << "invalid manager id" << endl;
		cin.clear ();
		cin.ignore (1024, '\n');
	}
	else
		cout << "delete manager success" << endl;
}
void ManagerViewConsoleImpl::list (void) {
	vector<Manager>& managers = service -> listManager ();
	cout << endl << left << setw (11) << "manager" << setw (22) << "manager name" << "manager password" << endl;
	cout << "-------------------------------------------" << endl;
	for (vector<Manager>::iterator it = managers.begin (); it != managers.end (); it++)
		cout << setw (11) << it -> getId () << setw (22) << it -> getName () << it -> getPassword () << endl;
}
int ManagerViewConsoleImpl::showMenu (void) {
	cout << endl;
	cout << "management information system" << endl;
	cout << "----------------" << endl;
	cout << "[1] add manager" << endl;
	cout << "[2] delete manager" << endl;
	cout << "[3] list manager" << endl;
	cout << "[4] run manager" << endl;
	cout << "[0] exit" << endl;
	cout << "----------------" << endl;
	cout << "please select:" << flush;
	string strEnter;
	cin >> strEnter;
	if (strspn (strEnter.c_str (), "01234") == strEnter.length ()) {
		istringstream iss (strEnter);
		int nEnter;
		iss >> nEnter;
		return nEnter;
	}
	return -1;
}
}
