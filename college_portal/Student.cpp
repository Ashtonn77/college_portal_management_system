#include <iostream>
#include <sqlite3.h>
#include <sstream>
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

void firstYear()
{
    std::cout << "+--------------+-------------------+--------------+----------------+-------------------------+" << std::endl;
    std::cout << "|------------------------------------FIRST YEAR BSC------------------------------------------|" << std::endl;
    std::cout << "+--------------+-------------------+--------------+----------------+-------------------------+" << std::endl;
    std::cout << "|   Maths 511  |  Programming 511  |  WebTech 511 |  Networks 511  | Information Systems 511 |" << std::endl;
    std::cout << "+--------------+-------------------+--------------+----------------+-------------------------+" << std::endl;
    std::cout << std::endl;
}

void secondYear()
{
    std::cout << "+--------------+-------------------+-----------------+-------------------------+" << std::endl;
    std::cout << "|--------------------------------SECOND YEAR BSC-------------------------------|" << std::endl;
    std::cout << "+--------------+-------------------+-----------------+-------------------------+" << std::endl;
    std::cout << "|   Cloud 612  |  Programming 612  |  Databases 612  | Information Systems 612 |" << std::endl;
    std::cout << "+--------------+-------------------+-----------------+-------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "+-------------------+-------------------------+--------------------+" << std::endl;
    std::cout << "|-------------------SECOND YEAR BSC ELECTIVES----------------------|" << std::endl;
    std::cout << "+-------------------+-------------------------+--------------------+" << std::endl;
    std::cout << "|   Systems Design  |   Software Engineering  |  Business Analysis |" << std::endl;
    std::cout << "+-------------------+-------------------------+--------------------+" << std::endl;
    std::cout << std::endl;
}

void thirdYear()
{
    std::cout << "+-------------------------------+------------------------------+-------------------+-------------------------+" << std::endl;
    std::cout << "|----------------------------------------------THIRD YEAR BSC------------------------------------------------|" << std::endl;
    std::cout << "+-------------------------------+------------------------------+-------------------+-------------------------+" << std::endl;
    std::cout << "|   Artificial Inteligence 713  |  Mobile App Development 713  |  Programming 713  | Information Systems 512 |" << std::endl;
    std::cout << "+-------------------------------+------------------------------+-------------------+-------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "+-------------------+-------------------------+--------------------+" << std::endl;
    ;
    std::cout << "|--------------------THIRD YEAR BSC ELECTIVES----------------------|" << std::endl;
    std::cout << "+-------------------+-------------------------+--------------------+" << std::endl;
    std::cout << "|   Systems Design  |   Software Engineering  |  Business Analysis |" << std::endl;
    std::cout << "+-------------------+-------------------------+--------------------+" << std::endl;
    std::cout << std::endl;
}

//print welcome msg
static int courseDisplayCallBack(void *data, int argc, char **argv, char **azColName)
{
    system("clear");
    int i;

    for (i = 0; i < argc; i++)
    {
        std::string s;
        std::stringstream ss;
        ss << argv[i];
        ss >> s;

        if (s == "Bsc")
        {
            firstYear();
            secondYear();
            thirdYear();
        }
        else if (argv[i] == "Bcom")
        {
            std::cout << "Feature pending" << std::endl;
        }
        else
        {
            std::cout << "This course is currently being updated" << std::endl;
            std::cout << "Check back in a few days" << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
//print welcome msg

//read course values
int Student::readStudentCourse(long long id, std::string tableName)
{
    sqlite3 *Db;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT COURSENAME FROM " + tableName + " WHERE ID=" + std::to_string(id);

    struct sqlite3_stmt *selectstmt;
    int result = sqlite3_prepare_v2(Db, query.c_str(), -1, &selectstmt, NULL);
    if (result == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            sqlite3_exec(Db, query.c_str(), courseDisplayCallBack, NULL, NULL);
        }
        else
        {
            system("clear");
            std::cout << "Sorry, we don\'t seem to have a record with that i.d number in our system." << std::endl;
            return -1;
        }
    }
    sqlite3_finalize(selectstmt);
}
//end read course values

void Student::studentRead(std::string dept, long long id)
{
    studentDb.readRecord(id, dept);
}

void Student::studentTask(long long id, std::string tableName)
{
    studentMain.departmentTitle = "Student";
    int choice = -1;
    std::string temp;
    do
    {
        std::cout << "1. View personal details " << std::endl;
        std::cout << "2. View course details " << std::endl;
        std::cout << "3. Make payment " << std::endl;
        std::cout << "4. Check fees balance " << std::endl;
        std::cout << "5. Go to online site " << std::endl;
        std::cout << "6. Back" << std::endl;

        std::cin >> temp;
        choice = std::stoi(studentErr.validIntegerInput(temp, "Re-enter choice"));

        switch (choice)
        {
        case 1:
        {
            studentMain.studentRead(studentMain.departmentTitle, id);
            break;
        }

        case 2:
        {
            readStudentCourse(id, tableName);
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
