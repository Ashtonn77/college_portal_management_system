#include <iostream>
#include <sqlite3.h>
#include <sstream>
#include <stdlib.h>
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

void firstYearBsc()
{
    std::cout << "+--------------+-------------------+--------------+----------------+-------------------------+" << std::endl;
    std::cout << "|------------------------------------FIRST YEAR BSC------------------------------------------|" << std::endl;
    std::cout << "+--------------+-------------------+--------------+----------------+-------------------------+" << std::endl;
    std::cout << "|   Maths 511  |  Programming 511  |  WebTech 511 |  Networks 511  | Information Systems 511 |" << std::endl;
    std::cout << "+--------------+-------------------+--------------+----------------+-------------------------+" << std::endl;
    std::cout << std::endl;
}

void secondYearBsc()
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

void thirdYearBsc()
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

void firstYearBcom()
{
    std::cout << "+----------------------------+------------------+-----------------+---------------------------+-------------------------+" << std::endl;
    std::cout << "|-------------------------------------------------FIRST YEAR BCOM-------------------------------------------------------|" << std::endl;
    std::cout << "+----------------------------+------------------+-----------------+---------------------------+-------------------------+" << std::endl;
    std::cout << "|   Business Management 511  |  Economics  511  |  Accounting 511 |  Business Statistics 511  | Information Systems 511 |" << std::endl;
    std::cout << "+----------------------------+------------------+-----------------+---------------------------+-------------------------+" << std::endl;
    std::cout << std::endl;
}

void secondYearBcom()
{
    std::cout << "+----------------------------+------------------+-----------------+---------------------------+" << std::endl;
    std::cout << "|---------------------------------------SECOND YEAR BCOM--------------------------------------|" << std::endl;
    std::cout << "+----------------------------+------------------+-----------------+---------------------------+" << std::endl;
    std::cout << "|   Business Management 612  |  Economics  612  |  Accounting 612 |  Business Statistics 612  |" << std::endl;
    std::cout << "+----------------------------+------------------+-----------------+---------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "+------------------+-------------------------+----------------------+" << std::endl;
    std::cout << "|-------------------SECOND YEAR BCOM ELECTIVES----------------------|" << std::endl;
    std::cout << "+------------------+-------------------------+----------------------+" << std::endl;
    std::cout << "|  Commercial Law  |   Stakeholder Relations |  Business Accounting |" << std::endl;
    std::cout << "+------------------+-------------------------+----------------------+" << std::endl;
    std::cout << std::endl;
}

void thirdYearBcom()
{
    std::cout << "+-----------------------------+-----------------------+-----------------+---------------------------------+" << std::endl;
    std::cout << "|------------------------------------------THIRD YEAR BCOM------------------------------------------------|" << std::endl;
    std::cout << "+-----------------------------+-----------------------+-----------------+---------------------------------+" << std::endl;
    std::cout << "|   Strategic Management 731  |  Market Research 700  |  Accounting 731 |  Human Resource Management 731  |" << std::endl;
    std::cout << "+-----------------------------+-----------------------+-----------------+---------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "+------------------+------------------------+-----------------------+" << std::endl;
    std::cout << "|--------------------THIRD YEAR BCOM ELECTIVES----------------------|" << std::endl;
    std::cout << "+------------------+-------------------------+----------------------+" << std::endl;
    std::cout << "|  Commercial Law  |   Stakeholder Relations |  Business Accounting |" << std::endl;
    std::cout << "+------------------+-------------------------+----------------------+" << std::endl;
    std::cout << std::endl;
}

//print course details msg
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
            system("clear");
            firstYearBsc();
            secondYearBsc();
            thirdYearBsc();
        }
        else if (s == "Bcom")
        {
            system("clear");
            firstYearBcom();
            secondYearBcom();
            thirdYearBcom();
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

//create StudentAccount table
int Student::createStudentAccountTable()
{
    sqlite3 *Db;
    if (studentDb.countRows("StudentAccount") > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE StudentAccount("
                      "ID          INT PRIMARY KEY         NOT NULL, "
                      "BALANCE     FLOAT                   NOT NULL );";
    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (studentDb.tableCount("StudentAccount") > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating StudentAccount Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "StudentAccount Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//insert into StudentAccount Table
int Student::insertIntoStudentAccount(long long id, long double balance, std::string tableName)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);

    if (studentDb.checkId(tableName, id) > 0)
    {
        std::cout << "" << std::endl;
        return 0;
    }

    std::string sql = "INSERT INTO StudentAccount VALUES(" + std::to_string(id) + ", " + std::to_string(balance) + ");";

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error inserting data into StudentAccount Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Data inserted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//student read
void Student::studentRead(std::string dept, long long id)
{
    studentDb.readRecord(id, dept);
}

//print account balance
static int checkBalance(void *data, int argc, char **argv, char **azColName)
{
    system("clear");
    int i;

    for (i = 0; i < argc; i++)
    {
        std::string s;
        std::stringstream ss;
        ss << argv[i];
        ss >> s;

        std::cout << "You have an outstanding balance of R" << s << std::endl;
    }
}

//read account balance
int Student::readStudentBalance(long long id, std::string tableName)
{
    sqlite3 *Db;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT BALANCE FROM " + tableName + " WHERE ID=" + std::to_string(id);

    struct sqlite3_stmt *selectstmt;
    int result = sqlite3_prepare_v2(Db, query.c_str(), -1, &selectstmt, NULL);
    if (result == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            sqlite3_exec(Db, query.c_str(), checkBalance, NULL, NULL);
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

// void Student::makePayment(long long id)
// {

//     long double newBalance{0.0};
//     std::cout << "How much would you like to pay? " << std::endl;

//     studentDb.updateRecordInTable(id, "BALANCE", "", "StudentAccount")
// }

void Student::studentTask(long long id, std::string tableName)
{
    studentMain.createStudentAccountTable();
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
            //insert into student acc table
            studentMain.insertIntoStudentAccount(id, 30000.00, "StudentAccount");

            break;
        }
        case 4:
        {
            studentMain.readStudentBalance(id, "StudentAccount");
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
