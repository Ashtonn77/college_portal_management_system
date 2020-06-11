#include <iostream>
#include <stdlib.h>
#include "Admin.h"
#include "Database.h"

Database d;
Admin a;
Admin::Admin(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Employee{fName, lName, id, e, age} {}

Admin::~Admin() {}

void displayIdPrompt(std::string d, std::string c)
{
    std::cout << "Enter i.d number of " << d << " you want to " << c << "___";
}

void Admin::personInsert() { d.insertIntoTable(idNumber, firstName, lastName, age, address, a.departmentTitle); }
void Admin::personDelete(std::string dept)
{
    system("clear");
    long long id{};
    displayIdPrompt(dept, "delete");
    std::cin >> id;
    d.deleteRecordFromTable(id);
}
void Admin::personRead(std::string dept)
{
    system("clear");
    long long id;
    displayIdPrompt(dept, "read");
    std::cin >> id;
    d.readRecord(id);
}

//action for db
void dbAction(std::string dept)
{
    std::cout << "What action would you like to perform? " << std::endl;
    int choice = -1;

    do
    {

        std::cout << std::endl;
        std::cout << "1. Insert new " << dept << std::endl;
        std::cout << "2. Update existing record" << std::endl;
        std::cout << "3. Delete " << dept << std::endl;
        std::cout << "4. Read record of " << dept << std::endl;
        std::cout << "5. Back" << std::endl;

        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("clear");
            a.getDetails(a, dept);
            a.personInsert();
            break;
        }
        case 2:
        {
            system("clear");
            //update record function
            break;
        }

        case 3:
        {
            system("clear");
            a.personDelete(a.departmentTitle);
            break;
        }
        case 4:
        {
            system("clear");
            a.personRead(a.departmentTitle);
            break;
        }
        case 5:
        {
            system("clear");
            std::cout << "Access another department or go back? " << std::endl;
            break;
        }
        default:
            system("clear");
            std::cout << "Invalid entry :(" << std::endl;
        }

    } while (choice != 5);
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
        std::cout << "5. Back" << std::endl;

        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("clear");
            dbAction(a.departmentTitle = "faculty");
            break;
        }
        case 2:
        {
            system("clear");
            dbAction(a.departmentTitle = "staff");
            break;
        }

        case 3:
        {
            system("clear");
            dbAction(a.departmentTitle = "student");
            break;
        }
        case 4:
        {
            system("clear");
            dbAction(a.departmentTitle = "admin");
            break;
        }
        case 5:
        {
            system("clear");
            std::cout << "Hello, again! How would you like to proceed?" << std::endl;
            break;
        }
        default:
            system("clear");
            std::cout << "Invalid entry :(" << std::endl;
        }

    } while (choice != 5);
}