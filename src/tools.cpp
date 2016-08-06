#include <fstream>
using namespace std;
namespace emis {
int generator_id (void) {
	int id = 1000;
	ifstream ifs ("id.dat");
	ifs >> id;
	id++;
	ifs.close ();
	ofstream ofs ("id.dat");
	ofs << id;
	ofs.close ();
	return id;
}
}
