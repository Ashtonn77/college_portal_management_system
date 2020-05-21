#include <iostream>
#include "Teacher.h"

Teacher::Teacher()
{

}

void Teacher::display(Student &s){
std::cout << s.firstName << ", " << s.lastName << std::endl;
}
