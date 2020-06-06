#include <iostream>
#include "Staff.h"

Staff::Staff(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Employee{fName, lName, id, e, age} {}

Staff::~Staff() {}
