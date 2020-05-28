#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"


int main()
{

    std::cout << "Hello, there! How would you like to proceed?" << std::endl;
    int choice{0};

    do
    {

        std::cout << std::endl;
        std::cout << "1. Administrator" << std::endl;
        std::cout << "2. Faculty" << std::endl;
        std::cout << "3. Staff" << std::endl;
        std::cout << "4. Student" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << std::endl;
        std::cin >> choice;

        switch(choice)
        {

        case 1:
            std::cout << "Welcome admin "<< std::endl;
            {
            Student p;
            p.getDetails(p);
           // p.displayDetails(p); //inherited from person class
            break;
            }

        case 2:
            std::cout << "Welcome faculty "<< std::endl;
            break;

        case 3:
            std::cout << "Welcome staff "<< std::endl;
            break;

        case 4:
            std::cout << "Welcome student "<< std::endl;
            break;

        case 5:
            std::cout << "Goodbye "<< std::endl;
            break;

        default:
            std::cout << "Invalid entry "<< std::endl;

        }

    }
    while(choice != 5);


    return 0;
}
