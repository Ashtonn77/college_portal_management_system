#include <iostream>
#include "Admin.h"

Admin::Admin(std::string fName, std::string lName, long long int id, std::string e)
:Employee{fName, lName, id, e}{}

Admin::~Admin(){}
