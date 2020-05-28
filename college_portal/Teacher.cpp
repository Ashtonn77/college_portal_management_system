#include <iostream>
#include "Teacher.h"

Teacher::Teacher(std::string fName, std::string lName, long long int id){}

Teacher::~Teacher()
{
    //dtor
}

void Teacher::display(){
        std::cout << "First Name : " << firstName << std::endl;
        std::cout << "Last Name : " << lastName << std::endl;
        std::cout << "ID Number : " << idNumber << std::endl;
        }
