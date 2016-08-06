#ifndef _SERVICEDAO_H
#define _SERVICEDAO_H
#include <vector>
using namespace std;
#include "department.h"
namespace emis {
class ServiceDao {
public:
	virtual ~ServiceDao (void) {}
	virtual void load (vector<Department>& vecDepts) = 0;
	virtual void save (vector<Department>& vecDepts) = 0;
};
}
#endif // _SERVICEDAO_H
