#ifndef DATABASE_H
#define DATABASE_H

class Database
{
public:
    Database();
    ~Database();

    int openDatabase();
    int createAdminTable();
    void checkTableState(std::string tableName);
    int insertIntoAdminTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, long double salary);
    int deleteRecordFromTable(long long id, std::string tableName);
    int countRows(std::string tableName);
    void readRecord(long long id, std::string tableName);
    int updateRecordInTable(long long id, std::string column, std::string attribute, std::string tableName);
    int tableCount(std::string tableName);
    int createStudentTable();
    int insertIntoStudentTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string courseName);
    int createFacultyTable();
    int insertIntoFacultyTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string courseOne, std::string courseTwo, std::string courseThree, long double salary);
    int createStaffTable();
    int insertIntoStaffTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string jobTitle, long double salary);
    int readSingleRecord(long long id, std::string tableName);
    int checkId(std::string tableName, long long id);

protected:
};

#endif // DATABASE_H
