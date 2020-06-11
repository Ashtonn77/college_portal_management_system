#include <iostream>
#include "Admin.h"
#include "Database.h"

Database d;
Admin a;
Admin::Admin(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Employee{fName, lName, id, e, age} {}

Admin::~Admin() {}

void Admin::studentInsert() { d.insertIntoTable(idNumber, firstName, lastName, age, address, a.departmentTitle); }
void Admin::studentDelete()
{
    long long id{};
    std::cout << "Enter i.d number of student you want to delete  ";
    std::cin >> id;
    d.deleteRecordFromTable(id);
}

void Admin::task()
{

    std::cout << "Which department would you like to access? " << std::endl;
    int choice = -1;

    do
    {
        std::cout << std::endl;
        std::cout << "1. Faculty" << std::endl;
        std::cout << "2. Staff" << std::endl;
        std::cout << "3. Student" << std::endl;
        std::cout << "4. Admin" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            a.getDetails(a, "faculty");
            break;
        }
        case 2:
        {
            a.getDetails(a, "staff");
            break;
        }

        case 3:
        {
            a.getDetails(a, "student");
            break;
        }
        case 4:
        {
            a.getDetails(a, "admin");
            break;
        }
        case 5:
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        default:
            std::cout << "Invalid entry :(" << std::endl;
        }

    } while (choice != 5);
}