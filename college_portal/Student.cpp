#include <iostream>
#include "Student.h"
#include "Database.h"

Student::Student(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Person{fName, lName, id, e, age} {}

Student::~Student() {}
