#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include <sstream>
#include "Faculty.h"
#include "Database.h"
#include "Admin.h"
#include "ErrorHandling.h"

Faculty facultyMain;
Database facultyDb;
Admin facultyAdmin;
ErrorHandling facultyErrChk;

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

std::string name;
std::string surname;
// //print marks msg
static int marksMsg(void *data, int argc, char **argv, char **azColName)
{

    std::stringstream ssName;
    std::stringstream ssSurname;
    ssName << argv[0];
    ssName >> name;
    ssSurname << argv[1];
    ssSurname >> surname;

    return 0;
}

// //read single value
int Faculty::verifyForMarks(long long id, std::string tableName)
{
    sqlite3 *Db;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT NAME, SURNAME FROM " + tableName + " WHERE ID=" + std::to_string(id);

    struct sqlite3_stmt *selectstmt;
    int result = sqlite3_prepare_v2(Db, query.c_str(), -1, &selectstmt, NULL);
    if (result == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            sqlite3_exec(Db, query.c_str(), marksMsg, NULL, NULL);
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
// //end read single value

//create studentResult table
int Faculty::createStudentResult()
{
    sqlite3 *Db;
    if (facultyDb.countRows("studentResult") > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE studentResult("
                      "ID          INT PRIMARY KEY         NOT NULL, "
                      "NAME        TEXT                    NOT NULL, "
                      "SURNAME     TEXT                    NOT NULL, "
                      "SUBJECT     TEXT                    NOT NULL, "
                      "RESULT      INT                     NOT NULL );";
    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (facultyDb.tableCount("studentResult") > 0)
    {
        std::cout << "" << std::endl;
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating studentResult Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "studentResult Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

// //insert into studentResult Table
int Faculty::insertIntoStudentResult(long long id, std::string name, std::string surname, std::string subject, int result)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);

    std::string sql = "INSERT INTO studentResult VALUES(" + std::to_string(id) + ", '" + name + "', '" + surname + "', '" + subject + "', '" + std::to_string(result) + "');";

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error inserting data into studentResult Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Data inserted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

void enterMarks()
{
    std::string temp;
    std::string subject;
    long long id;
    int mark;
    std::cout << "Enter i.d of student__" << std::endl;
    std::cin >> temp;
    id = std::stoll(facultyErrChk.validIntegerInput(temp, "Re-enter i.d"));
    system("clear");

    if (facultyMain.verifyForMarks(id, "Student") != -1)
    {
        std::cout << "For which subject?" << std::endl;
        std::cin >> subject;
        subject = facultyErrChk.validStringInput(subject, "Re-enter subject");
        system("clear");
        std::cout << "Finally...enter result for student 0-100__" << std::endl;
        temp = "";
        std::cin >> temp;
        mark = std::stoi(facultyErrChk.validIntegerInput(temp, "Re-enter mark"));
        facultyMain.insertIntoStudentResult(id, name, surname, subject, mark);
    }
}

void Faculty::facultyTask(long long id, std::string tableName)
{
    facultyMain.createStudentResult();
    int choice = -1;

    do
    {

        std::cout << "1. Display personal details " << std::endl;
        std::cout << "2. Display general schedule " << std::endl;
        std::cout << "3. Display student details " << std::endl;
        std::cout << "4. Save student results " << std::endl;
        std::cout << "5. Read students results " << std::endl;
        std::cout << "6. Back" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("clear");
            facultyDb.readRecord(id, tableName);
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
            system("clear");
            enterMarks();
            break;
        }
        case 5:
        {

            system("clear");
            facultyDb.checkTableState("studentResult");
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