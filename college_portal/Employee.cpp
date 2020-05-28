#include <iostream>
#include "Employee.h"

Employee::Employee(std::string fName, std::string lName, long long int id, std::string e)
:Person{fName, lName, id, e}{}

Employee::~Employee()
{
    //dtor
}
