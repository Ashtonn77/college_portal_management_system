#include <iostream>
#include <sqlite3.h>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "Staff.h"
#include "Faculty.h"
#include "Admin.h"
#include "Database.h"

int main(int argc, char **argv)
{
    Database s;
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
        std::cout << "6. Db state" << std::endl;
        std::cout << "7. misc" << std::endl;
        std::cout << "0. Test" << std::endl;
        std::cout << std::endl;
        std::cin >> choice;

        switch (choice)
        {

        case 1:
            std::cout << "Welcome admin " << std::endl;
            {
                Admin a;
                a.userTitle = "Admin";
                break;
            }

        case 2:
            std::cout << "Welcome faculty " << std::endl;
            {
                Faculty f;
                f.userTitle = "Faculty";
                f.getDetails(f);

                break;
            }

        case 3:
            std::cout << "Welcome staff " << std::endl;
            {
                Staff d;
                d.userTitle = "Staff";
                d.getDetails(d);

                break;
            }

        case 4:
            std::cout << "Welcome student " << std::endl;
            {
                Student p;
                p.userTitle = "Student";
                p.getDetails(p);
                //p.studentInsert();
                p.studentDelete();
                break;
            }

        case 5:
            std::cout << "Goodbye " << std::endl;
            break;
        case 6:
        {

            s.checkTableState();
            break;
        }
        case 7:
        {

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
            std::cout << "Invalid entry " << std::endl;
        }

    } while (choice != 5);

    return 0;
}
