#include <iostream>
#include <sqlite3.h>
#include <string>

#include "StudentDb.h"

StudentDb::StudentDb(/* args */) {}

StudentDb::~StudentDb() {}

//count callback
static int countCallback(void *count, int argc, char **argv, char **azColName)
{
    int *c = (int *)count;
    *c = atoi(argv[0]);
    return 0;
}

//count rows
int StudentDb::countRows()
{
    sqlite3 *Db;
    char *messageError;
    int count = 0;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT COUNT(*) FROM Student;";
    int r = sqlite3_exec(Db, query.c_str(), countCallback, &count, &messageError);
    return count;
}

///check if table exists
int StudentDb::tableCount()
{

    sqlite3 *Db;
    char *messageError;
    int count = 0;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT count(*) FROM sqlite_master WHERE type = 'table' AND name = 'Student'";
    int r = sqlite3_exec(Db, query.c_str(), countCallback, &count, &messageError);
    return count;
}

int StudentDb::openDatabase()
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

//create Student table
int StudentDb::createStudentTable()
{
    sqlite3 *Db;
    if (countRows() > 0)
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
                      "ADDRESS     CHAR(50)                        );";

    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (tableCount() > 0)
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

//create StudentCourse table
int StudentDb::createStudentCourseTable()
{
    sqlite3 *Db;
    if (countRows() > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE StudentCourse("
                      "ID          INT PRIMARY KEY         NOT NULL, "
                      "COURSEID    INT FOREIGN KEY         NOT NULL, "
                      "SEMESTER    INT                     NOT NULL);";

    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (tableCount() > 0)
    {
        std::cout << " ";
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating StudentCourse Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "StudentCourse Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//create Course table
int StudentDb::createCourseTable()
{
    sqlite3 *Db;
    if (countRows() > 0)
    {
        std::cout << " " << std::endl;
        return 0;
    }
    std::string sql = "CREATE TABLE Course("
                      "COURSEID          INT PRIMARY KEY        NOT NULL, "
                      "COURSENAME        TEXT                   NOT NULL );";

    int exit{0};
    exit = sqlite3_open("sqliteDb/college.db", &Db);
    char *messageError;
    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);

    if (tableCount() > 0)
    {
        std::cout << " ";
        return 0;
    }

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating Course Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Course Table created successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}