#include <iostream>
#include <stdlib.h>
#include <vector>
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

//update main and helper functions

std::string columnToUpdate()
{
    //system("clear");
    std::string colName{};
    int choice = -1;

    std::cout << "Which field would you like to update? " << std::endl;

    std::cout << std::endl;
    std::cout << "1. Change first name " << std::endl;
    std::cout << "2. Change last name" << std::endl;
    std::cout << "3. Change age " << std::endl;
    std::cout << "4. Change department " << std::endl;
    std::cout << "5. Change address " << std::endl;

    std::cin >> choice;

    if (choice == 1)
        colName = "NAME";
    else if (choice == 2)
        colName = "SURNAME";
    else if (choice == 3)
        colName = "AGE";
    else if (choice == 4)
        colName = "DEPARTMENT";
    else if (choice == 5)
        colName = "ADDRESS";
    else
        colName = "Invalid";

    return colName;
}

void Admin::personUpdate(std::string dept)
{
    system("clear");
    long long id;
    displayIdPrompt(dept, "update");
    std::cin >> id;
    std::string str = "";
    std::string colName = columnToUpdate();
    while (colName == "Invalid")
    {
        system("clear");
        std::cout << "Sorry, that's an invalid entry...try again" << std::endl;
        colName = columnToUpdate();
    }
    std::cout << "To what would you like to change the current attribute?" << std::endl;
    std::getline(std::cin >> std::ws, str);
    d.updateRecordInTable(id, colName, str);
}
//end update

//student section
void Admin::addNewStudent()
{
    std::string courseName{};
    std::cout << "Enter course name applicable for student__" << std::endl;
    std::cin >> courseName;

    d.insertIntoStudentTable(idNumber, firstName, lastName, age, address, a.departmentTitle, courseName);
}
//end student section

//faculty section
void Admin::addNewFaculty()
{
    std::vector<std::string> lecturerCourses{"N/A", "N/A", "N/A"};
    int c{};
    std::cout << "How many courses/subjects does the lecturer teach?__";
    std::cin >> c;

    for (int i = 0; i < c; i++)
    {
        std::cin.clear();
        std::cout << "Please enter course/subject name__";
        std::cin >> lecturerCourses[i];
    }

    long double salary = {0.0};
    std::cout << "Enter faculty's monthly salary__";
    std::cin >> salary;

    d.insertIntoFacultyTable(idNumber, firstName, lastName, age, address, a.departmentTitle, lecturerCourses[0], lecturerCourses[1], lecturerCourses[2], salary);
}

//end faculty section

//staff section
void Admin::addNewStaff()
{

    std::string jobTitle{};
    std::cout << "Enter staff's job title__";
    std::getline(std::cin >> std::ws, jobTitle);

    long double salary = {0.0};
    std::cout << "Enter staff's monthly salary__";
    std::cin >> salary;

    d.insertIntoStaffTable(idNumber, firstName, lastName, age, address, a.departmentTitle, jobTitle, salary);
}

//end staff section

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
        std::cout << "6. Test" << std::endl;

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
            a.personUpdate(a.departmentTitle);
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
        case 6:
        {
            system("clear");
            a.getDetails(a, dept);
            a.addNewStaff();
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