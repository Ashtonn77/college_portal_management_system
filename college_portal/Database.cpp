#include <iostream>
#include <stdlib.h>
#include <sqlite3.h>
#include <string>
#include "Database.h"

Database::Database() {}

Database::~Database() {}

//count callback
static int countCallback(void *count, int argc, char **argv, char **azColName)
{
    int *c = (int *)count;
    *c = atoi(argv[0]);
    return 0;
}

//count rows;
int Database::countRows(std::string tableName)
{
    sqlite3 *Db;
    char *messageError;
    int count = 0;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT COUNT(*) FROM " + tableName;
    int r = sqlite3_exec(Db, query.c_str(), countCallback, &count, &messageError);
    return count;
}

///check if table exists
int Database::tableCount(std::string tableName)
{

    sqlite3 *Db;
    char *messageError;
    int count = 0;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT count(*) FROM sqlite_master WHERE type = 'table' AND name = '" + tableName + "'";
    int r = sqlite3_exec(Db, query.c_str(), countCallback, &count, &messageError);
    return count;
}

//check if value exits;
int Database::checkId(std::string tableName, long long id)
{
    sqlite3 *Db;
    char *messageError;
    int count = 0;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT COUNT(*) FROM " + tableName + " WHERE ID=" + std::to_string(id);
    int r = sqlite3_exec(Db, query.c_str(), countCallback, &count, &messageError);
    return count;
}

int Database::openDatabase()
{
    sqlite3 *Db;
    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);

    if (exit)
    {
        std::cout << "There was an error connecting to the database" << sqlite3_errmsg(Db) << std::endl;
    }
    else
        std::cout << "Connection to the database successful" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//create table
int Database::createAdminTable()
{
    sqlite3 *Db;
    if (countRows("Admin") > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE Admin("
                      "ID          INT PRIMARY KEY         NOT NULL, "
                      "NAME        TEXT                    NOT NULL, "
                      "SURNAME     TEXT                    NOT NULL, "
                      "AGE         INT                     NOT NULL, "
                      "DEPARTMENT     CHAR(50)             NOT NULL, "
                      "ADDRESS     CHAR(50)                NOT NULL, "
                      "SALARY      FLOAT                    NOT NULL);";

    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (tableCount("Admin") > 0)
    {
        std::cout << " ";
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating Admin Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Admin Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//print table state
static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    //fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
//end print table state

//check values in table
void Database::checkTableState(std::string tableName)
{
    sqlite3 *Db;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT * FROM " + tableName;
    sqlite3_exec(Db, query.c_str(), callback, NULL, NULL);
    if (countRows(tableName) < 1)
        std::cout << "There are no records in table" << std::endl;
    else
    {
        if (countRows(tableName) == 1)
            std::cout << "There is " << countRows(tableName) << " record currently in table" << std::endl;
        else
        {
            std::cout << "There are " << countRows(tableName) << " records currently in table" << std::endl;
        }
    }
}

//insert
int Database::insertIntoAdminTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, long double salary)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);

    std::string sql = "INSERT INTO Admin VALUES(" + std::to_string(id) + ", '" + name + "', '" + surname + "'," + std::to_string(age) + ", '" + dept + "', '" + address + "', '" + std::to_string(salary) + "');";

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error inserting data into Admin Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Data inserted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//delete
int Database::deleteRecordFromTable(long long id, std::string tableName)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string sql = "DELETE FROM " + tableName + " WHERE id = " + std::to_string(id);

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error deleting record" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Record deleted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//read
void Database::readRecord(long long id, std::string tableName)
{
    sqlite3 *Db;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT * FROM " + tableName + " WHERE ID=" + std::to_string(id);

    struct sqlite3_stmt *selectstmt;
    int result = sqlite3_prepare_v2(Db, query.c_str(), -1, &selectstmt, NULL);
    if (result == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            system("clear");
            sqlite3_exec(Db, query.c_str(), callback, NULL, NULL);
        }
        else
        {
            system("clear");
            std::cout << "No record with that i.d number in our system...try another" << std::endl;
        }
    }
    sqlite3_finalize(selectstmt);
}

//update
int Database::updateRecordInTable(long long id, std::string column, std::string attribute, std::string tableName)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string sql = "UPDATE " + tableName + " SET '" + column + "'='" + attribute + "' WHERE id = " + std::to_string(id);

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cout << "Error updating record" << std::endl;
        sqlite3_free(messageError);
        return -1;
    }
    else
        std::cout << "Record updated successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//student section

//create Student table
int Database::createStudentTable()
{
    sqlite3 *Db;
    if (countRows("Student") > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE Student("
                      "ID          INT PRIMARY KEY         NOT NULL, "
                      "NAME        TEXT                    NOT NULL, "
                      "SURNAME     TEXT                    NOT NULL, "
                      "AGE         INT                     NOT NULL, "
                      "DEPARTMENT     CHAR(50)             NOT NULL, "
                      "ADDRESS        CHAR(50)             NOT NULL, "
                      "COURSENAME     TEXT                 NOT NULL );";
    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (tableCount("Student") > 0)
    {
        std::cout << " ";
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating Student Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Student Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//insert into student Table
int Database::insertIntoStudentTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string courseName)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);

    std::string sql = "INSERT INTO Student VALUES(" + std::to_string(id) + ", '" + name + "', '" + surname + "'," + std::to_string(age) + ", '" + dept + "', '" + address + "', '" + courseName + "');";

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error inserting data into Student Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Data inserted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//end Student section

//create Faculty table
int Database::createFacultyTable()
{
    sqlite3 *Db;
    if (countRows("Faculty") > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE Faculty("
                      "ID          INT PRIMARY KEY         NOT NULL, "
                      "NAME        TEXT                    NOT NULL, "
                      "SURNAME     TEXT                    NOT NULL, "
                      "AGE         INT                     NOT NULL, "
                      "DEPARTMENT     CHAR(50)             NOT NULL, "
                      "ADDRESS        CHAR(50)             NOT NULL, "
                      "COURSETEACHINGONE     TEXT          NOT NULL, "
                      "COURSETEACHINGTWO     TEXT          NOT NULL, "
                      "COURSETEACHINGTHREE   TEXT          NOT NULL, "
                      "SALARY      FLOAT                     NOT NULL );";
    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (tableCount("Faculty") > 0)
    {
        std::cout << " ";
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating Faculty Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Faculty Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//insert into Faculty Table
int Database::insertIntoFacultyTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string courseOne, std::string courseTwo, std::string courseThree, long double salary)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);

    std::string sql = "INSERT INTO Faculty VALUES(" + std::to_string(id) + ", '" + name + "', '" + surname + "'," + std::to_string(age) + ", '" + dept + "', '" + address + "', '" + courseOne + "', '" + courseTwo + "', '" + courseThree + "', '" + std::to_string(salary) + "');";

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error inserting data into Faculty Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Data inserted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//end Faculty section

//create Staff table
int Database::createStaffTable()
{
    sqlite3 *Db;
    if (countRows("Staff") > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE Staff("
                      "ID          INT PRIMARY KEY         NOT NULL, "
                      "NAME        TEXT                    NOT NULL, "
                      "SURNAME     TEXT                    NOT NULL, "
                      "AGE         INT                     NOT NULL, "
                      "DEPARTMENT     CHAR(50)             NOT NULL, "
                      "ADDRESS        CHAR(50)             NOT NULL, "
                      "JOBTITLE       TEXT                 NOT NULL, "
                      "SALARY      FLOAT                    NOT NULL );";
    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (tableCount("Staff") > 0)
    {
        std::cout << " ";
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating Staff Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Staff Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//insert into Staff Table
int Database::insertIntoStaffTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string jobTitle, long double salary)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);

    std::string sql = "INSERT INTO Staff VALUES(" + std::to_string(id) + ", '" + name + "', '" + surname + "'," + std::to_string(age) + ", '" + dept + "', '" + address + "', '" + jobTitle + "', '" + std::to_string(salary) + "');";

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error inserting data into Staff Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Data inserted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//end Staff section

//print welcome msg
static int welcomeCallback(void *data, int argc, char **argv, char **azColName)
{
    system("clear");
    int i;

    for (i = 0; i < argc; i++)
    {
        std::cout << "You signed in as, " << argv[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
//print welcome msg

//read single value
int Database::readSingleRecord(long long id, std::string tableName)
{
    sqlite3 *Db;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT NAME FROM " + tableName + " WHERE ID=" + std::to_string(id);

    struct sqlite3_stmt *selectstmt;
    int result = sqlite3_prepare_v2(Db, query.c_str(), -1, &selectstmt, NULL);
    if (result == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            sqlite3_exec(Db, query.c_str(), welcomeCallback, NULL, NULL);
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
//end read single value
