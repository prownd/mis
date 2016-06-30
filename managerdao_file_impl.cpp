#include <fstream>
using namespace std;
#include "managerdao_file_impl.h"
namespace emis {
void ManagerDaoFileImpl::load (vector<Manager>& managers) {
	ifstream ifs ("manager.dat");
	Manager m (0);
	while (ifs.read ((char*)&m, sizeof (Manager)) > 0)
		managers.push_back (m);
	ifs.close ();
}
void ManagerDaoFileImpl::save (vector<Manager>& managers) {
	ofstream ofs ("manager.dat", ios::binary);
	for (int i = 0; i < managers.size (); i++)
		ofs.write ((char*)&managers[i], sizeof (Manager));
	ofs.close ();
}
}
