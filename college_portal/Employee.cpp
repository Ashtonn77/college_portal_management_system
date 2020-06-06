#include <iostream>
#include "Employee.h"

Employee::Employee(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Person{fName, lName, id, e, age} {}

Employee::~Employee()
{
    //dtor
}
