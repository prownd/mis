#ifndef _MANAGERDAO_FILE_IMPL_H
#define _MANAGERDAO_FILE_IMPL_H
#include "managerdao.h"
namespace emis {
class ManagerDaoFileImpl : public ManagerDao {
public:
	void load (vector<Manager>& managers);
	void save (vector<Manager>& managers);
};
}
#endif // _MANAGERDAO_FILE_IMPL_H
