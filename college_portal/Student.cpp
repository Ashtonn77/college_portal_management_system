#include <iostream>
#include "Student.h"
#include "Database.h"
#include "ErrorHandling.h"
#include "Admin.h"

Student studentMain;
ErrorHandling studentErr;
Database studentDb;
Admin studentAdmin;

Student::Student(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Person{fName, lName, id, e, age} {}

Student::~Student() {}

void Student::studentRead(std::string dept)
{
    system("clear");
    long long id;
    studentAdmin.displayIdPrompt(dept, "read");
    std::cin >> id;
    studentDb.readRecord(idNumber, dept);
}

void Student::studentTask()
{

    int choice = -1;
    std::string temp;
    do
    {
        std::cout << "1. View personal details " << std::endl;
        std::cout << "2. View course details " << std::endl;
        std::cout << "3. Make payment " << std::endl;
        std::cout << "4. Check fees balance " << std::endl;
        std::cout << "5. Go to online site " << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cin >> temp;
        choice = std::stoi(studentErr.validIntegerInput(temp, "Re-enter choice"));

        switch (choice)
        {
        case 1:
        {
            studentRead(studentMain.departmentTitle);
            break;
        }

        case 2:
        {
            std::cout << "Feature under construction " << std::endl;
            break;
        }

        case 3:
        {
            std::cout << "Feature under construction " << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Feature under construction " << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Feature under construction " << std::endl;
            break;
        }
        case 6:
        {
            system("clear");
            std::cout << "Access another department or go back? " << std::endl;
            break;
        }
        default:
            std::cout << "Invalid input " << std::endl;
        }

    } while (choice != 6);
}