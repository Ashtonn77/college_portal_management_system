#include <iostream>
#include "Faculty.h"

Faculty::Faculty(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Employee{fName, lName, id, e, age} {}

Faculty::~Faculty() {}
