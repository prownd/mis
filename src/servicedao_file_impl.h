#ifndef _SERVICEDAO_FILE_IMPL_H
#define _SERVICEDAO_FILE_IMPL_H
#include "servicedao.h"
namespace emis {
class ServiceDaoFileImpl : public ServiceDao {
public:
	void load (vector<Department>& vecDepts);
	void save (vector<Department>& vecDepts);
};
}
#endif // _SERVICEDAO_FILE_IMPL_H
