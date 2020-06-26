#include <iostream>
#include <sqlite3.h>
#include <stdlib.h>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "Admin.h"
#include "Database.h"
#include "ErrorHandling.h"

void welcomeMsg()
{

    std::cout << "+---------------------------------------------+" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|         WELCOME TO GOTHAM COLLEGE           |" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "+---------------------------------------------+" << std::endl;
    std::cout << std::endl
              << std::endl;
}

int main(int argc, char **argv)
{
    Database s;

    s.openDatabase();
    s.createAdminTable();
    s.createStudentTable();
    s.createFacultyTable();
    s.createStaffTable();
    std::cout << std::endl;

    welcomeMsg();

    std::cout << "How would you like to proceed?" << std::endl;
    int choice{0};

    do
    {

        std::cout << std::endl;
        std::cout << "1. Administrator" << std::endl;
        std::cout << "2. Faculty" << std::endl;
        std::cout << "3. Staff" << std::endl;
        std::cout << "4. Student" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "6. Db state" << std::endl;
        std::cout << "7. misc" << std::endl;
        std::cout << "0. Test" << std::endl;
        std::cout << std::endl;
        std::cin >> choice;

        switch (choice)
        {

        case 1:
            system("clear");
            std::cout << "Welcome admin " << std::endl;
            {
                Admin admin;
                admin.userTitle = "Admin";
                if (s.readSingleRecord(admin.login(), admin.userTitle) != -1)
                {
                    admin.task();
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << "How would you like to proceed?" << std::endl;
                }
                break;
            }

        case 2:
            system("clear");
            std::cout << "Welcome faculty " << std::endl;
            {
                Faculty faculty;
                faculty.userTitle = "Faculty";
                if (s.readSingleRecord(faculty.login(), faculty.userTitle) != -1)
                {
                    std::cout << "Everything seems to be in order" << std::endl;
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << "How would you like to proceed?" << std::endl;
                }

                break;
            }

        case 3:
            system("clear");
            std::cout << "Welcome staff " << std::endl;
            {
                Staff staff;
                staff.userTitle = "Staff";
                if (s.readSingleRecord(staff.login(), staff.userTitle) != -1)
                {
                    std::cout << "Everything seems to be in order" << std::endl;
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << "How would you like to proceed?" << std::endl;
                }

                break;
            }

        case 4:
            system("clear");
            std::cout << "Welcome student " << std::endl;
            {
                Student student;
                int i = 0;
                student.userTitle = "Student";
                if (s.readSingleRecord(i = student.login(), student.userTitle) != -1)
                {
                    student.studentTask(i, student.userTitle);
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << "How would you like to proceed?" << std::endl;
                }
                break;
            }

        case 5:
            std::cout << "Goodbye " << std::endl;
            break;
        case 6:
        {
            system("clear");
            s.checkTableState("Student");

            break;
        }
        case 7:
        {
            //s.readSingleRecord(120, "Admin");
            break;
        }

        case 0:
        {

            //d.openDatabase();
            //d.createPersonTable();
            //d.insertIntoTable();
            //d.deleteRecordFromTable();
            break;
        }
        default:
            system("clear");
            std::cout << "Invalid entry " << std::endl;
        }

    } while (choice != 5);

    return 0;
}
