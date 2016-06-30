#include <fstream>
using namespace std;
#include "servicedao_file_impl.h"
namespace emis {
void ServiceDaoFileImpl::load (vector<Department>& vecDepts) {
	ifstream ifs ("service.dat");
	if (ifs) {
		for (Department dept (0); ifs >> dept; vecDepts.push_back (dept));
		ifs.close ();
	}
}
void ServiceDaoFileImpl::save (vector<Department>& vecDepts) {
	ofstream ofs ("service.dat");
	for (vector<Department>::iterator it = vecDepts.begin (); it != vecDepts.end (); it++)
		ofs << *it;
	ofs.close ();
}
}
