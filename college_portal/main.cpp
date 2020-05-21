#include <iostream>
#include "Student.h"
#include "Teacher.h"

/*void displayDetails(Student s){
std::cout << "Name : " << s.firstName << std::endl;
std::cout << "Surname : " << s.lastName << std::endl;
}*/

int main()
{
    Student one("Ashton", "Naidoo");
    Student two{one};
    Teacher test;
    test.display(two);
    return 0;
}
