#include <cstring>
#include "manager.h"
#include "tools.h"
namespace emis {
Manager::Manager (void) : id (generator_id ()) {
}
Manager::Manager (int) {
}
int Manager::getId (void) const {
	return id;
}
string Manager::getName (void) const {
	return name;
}
string Manager::getPassword (void) const {
	return password;
}
void Manager::setName (const char* name) {
	strcpy (this -> name, name);
}
void Manager::setPassword (const char* password) {
	strcpy (this -> password, password);
}
}
