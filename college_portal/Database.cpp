#include <iostream>
#include <sqlite3.h>
#include <string>
#include "Database.h"

Database::Database() {}

Database::~Database() {}

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

int Database::createPersonTable()
{
    sqlite3 *Db;
    //select count(type) from sqlite_master where type='table' and name='TABLE_NAME_TO_CHECK';
    std::string sql = "CREATE TABLE Person("
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

    if (exit != SQLITE_OK)
    {
        std::cout << "Error creating Person Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Person Table created successfully" << std::endl;

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

void Database::checkTableState()
{
    sqlite3 *Db;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT * FROM Person";
    sqlite3_exec(Db, query.c_str(), callback, NULL, NULL);
    if (countRows() < 1)
        std::cout << "There are no records in table" << std::endl;
}

//insert
int Database::insertIntoTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);

    std::string sql = "INSERT INTO Person VALUES(" + std::to_string(id) + ", '" + name + "', '" + surname + "'," + std::to_string(age) + ", '" + dept + "', '" + address + "');";

    exit = sqlite3_exec(Db, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        std::cout << "Error inserting data into Person Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Data inserted successfully" << std::endl;

    sqlite3_close(Db);
    return 0;
}

//delete
int Database::deleteRecordFromTable(long long id)
{
    sqlite3 *Db;
    char *messageError;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string sql = "DELETE FROM Person WHERE id = " + std::to_string(id);

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

//count callback
static int countCallback(void *count, int argc, char **argv, char **azColName)
{
    int *c = (int *)count;
    *c = atoi(argv[0]);
    return 0;
}

int Database::countRows()
{
    sqlite3 *Db;
    char *messageError;
    int count = 0;
    int exit = sqlite3_open("sqliteDb/college.db", &Db);
    std::string query = "SELECT COUNT(*) FROM Person;";
    int r = sqlite3_exec(Db, query.c_str(), countCallback, &count, &messageError);
    return count;
}