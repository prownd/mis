#ifndef _MANAGER_H
#define _MANAGER_H
#include <string>
using namespace std;
namespace emis {
class Manager {
public:
	Manager (void);
	Manager (int);
	int getId (void) const;
	string getName (void) const;
	string getPassword (void) const;
	void setName (const char* name);
	void setPassword (const char* password);
private:
	int id;
	char name[20];
	char password[20];
};
}
#endif // _MANAGER_H
