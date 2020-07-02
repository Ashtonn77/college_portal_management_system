#include <iostream>
#include <stdlib.h>
#include "Faculty.h"
#include "Database.h"
#include "Admin.h"

Faculty facultyMain;
Database facultyDb;
Admin facultyAdmin;

Faculty::Faculty(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Employee{fName, lName, id, e, age} {}

Faculty::~Faculty() {}

void Faculty::generalSchedule()
{

    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|                 |     Monday     |     Tuesday    |    Wednesday   |    Thursday    |     Friday     |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|  08:15 - 09:15  |       Math     |     Cloud      |      free      |      free      |      Math      |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|  09:15 - 10:15  |  Programming   |     Tuesday    |      Math      |    WebTech     |      free      |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|                         ******************** TEA BREAK ********************                          |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|  10:30 - 11:30  |     Cloud      |      Math      |   Programming  |    Thursday    |     WebTech    |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|  11:30 - 12:30  |     Monday     |   Programming  |    WebTech     |      Math      |     free       |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|                    ******************** LUNCH BREAK ********************                             |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|  13:30 - 14:30  |      Math      |   Programming  |     Cloud      |    Thursday    |     WebTech    |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << "|  14:30 - 15:30  |      free      |      Math      |    Wednesday   |   Programming  |     WebTech    |" << std::endl;
    std::cout << "+-----------------+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    std::cout << std::endl;
}

// //print welcome msg
// static int welcomeCallback(void *data, int argc, char **argv, char **azColName)
// {
//     system("clear");
//     int i;

//     for (i = 0; i < argc; i++)
//     {
//         std::cout << "You signed in as, " << argv[i] << std::endl;
//     }
//     std::cout << std::endl;
//     std::cout << std::endl;
//     return 0;
// }
// //print welcome msg

// //read single value
// int Database::readSingleRecord(long long id, std::string tableName)
// {
//     sqlite3 *Db;
//     int exit = sqlite3_open("sqliteDb/college.db", &Db);
//     std::string query = "SELECT NAME FROM " + tableName + " WHERE ID=" + std::to_string(id);

//     struct sqlite3_stmt *selectstmt;
//     int result = sqlite3_prepare_v2(Db, query.c_str(), -1, &selectstmt, NULL);
//     if (result == SQLITE_OK)
//     {
//         if (sqlite3_step(selectstmt) == SQLITE_ROW)
//         {
//             sqlite3_exec(Db, query.c_str(), welcomeCallback, NULL, NULL);
//         }
//         else
//         {
//             system("clear");
//             std::cout << "Sorry, we don\'t seem to have a record with that i.d number in our system." << std::endl;
//             return -1;
//         }
//     }
//     sqlite3_finalize(selectstmt);
// }
// //end read single value

// //create Staff table
// int Database::createStaffTable()
// {
//     sqlite3 *Db;
//     if (countRows("Staff") > 0)
//     {
//         std::cout << " " << std::endl;
//         return 0;
//     }
//     std::string sql = "CREATE TABLE Staff("
//                       "ID          INT PRIMARY KEY         NOT NULL, "
//                       "NAME        TEXT                    NOT NULL, "
//                       "SURNAME     TEXT                    NOT NULL, "
//                       "AGE         INT                     NOT NULL, "
//                       "DEPARTMENT     CHAR(50)             NOT NULL, "
//                       "ADDRESS        CHAR(50)             NOT NULL, "
//                       "JOBTITLE       TEXT                 NOT NULL, "
//                       "SALARY      FLOAT                    NOT NULL );";
//     int exit{0};
//     exit = sqlite3_open("sqliteDb/college.db", &Db);
//     char *messageError;
//     exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

//     if (tableCount("Staff") > 0)
//     {
//         std::cout << " ";
//         return 0;
//     }

//     if (exit != SQLITE_OK)
//     {
//         std::cout << "Error creating Staff Table" << std::endl;
//         sqlite3_free(messageError);
//     }
//     else
//         std::cout << "Staff Table created successfully" << std::endl;

//     sqlite3_close(Db);
//     return 0;
// }

// //insert into Staff Table
// int Database::insertIntoStaffTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string jobTitle, long double salary)
// {
//     sqlite3 *Db;
//     char *messageError;
//     int exit = sqlite3_open("sqliteDb/college.db", &Db);

//     std::string sql = "INSERT INTO Staff VALUES(" + std::to_string(id) + ", '" + name + "', '" + surname + "'," + std::to_string(age) + ", '" + dept + "', '" + address + "', '" + jobTitle + "', '" + std::to_string(salary) + "');";

//     exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
//     if (exit != SQLITE_OK)
//     {
//         std::cout << "Error inserting data into Staff Table" << std::endl;
//         sqlite3_free(messageError);
//     }
//     else
//         std::cout << "Data inserted successfully" << std::endl;

//     sqlite3_close(Db);
//     return 0;
// }

void Faculty::facultyTask(long long id, std::string tableName)
{

    int choice = -1;

    do
    {

        std::cout << "1. Display personal details " << std::endl;
        std::cout << "2. Display general schedule " << std::endl;
        std::cout << "3. Display student details " << std::endl;
        std::cout << "4. Save student results " << std::endl;
        std::cout << "5. Read student results " << std::endl;
        std::cout << "6. Back" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("clear");
            facultyDb.readRecord(id, tableName);
            std::cout << "Feature pending" << std::endl;
            break;
        }
        case 2:
        {
            system("clear");
            facultyMain.generalSchedule();
            break;
        }
        case 3:
        {
            system("clear");
            facultyAdmin.personRead("Student");
            break;
        }
        case 4:
        {
            std::cout << "Feature pending" << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Feature pending" << std::endl;
            break;
        }
        case 6:
        {
            system("clear");
            std::cout << "Access another department or go back? " << std::endl;
            break;
        }
        default:
            system("clear");
            std::cout << "Invalid entry :(" << std::endl;
        }
    } while (choice != 6);
}