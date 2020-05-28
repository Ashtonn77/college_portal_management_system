#include <iostream>
#include "Student.h"

Student::Student(std::string fName, std::string lName, long long int id, std::string e)
:Person{fName, lName, id, e}{}

Student::~Student()
{
    //dtor
}


