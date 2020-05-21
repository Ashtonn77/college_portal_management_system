#include <iostream>
#include "Student.h"

Student::Student(std::string n, std::string l)
:firstName{n}, lastName{l}{}

Student::Student(const Student &source)
:Student(source.firstName, source.lastName){}

Student::~Student(){
std::cout << "Destructor called" << std::endl;
}

