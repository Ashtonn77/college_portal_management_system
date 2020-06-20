#ifndef DATABASE_H
#define DATABASE_H

class Database
{
public:
    Database();
    ~Database();

    int openDatabase();
    int createPersonTable();
    void checkTableState(std::string tableName);
    int insertIntoTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept);
    int deleteRecordFromTable(long long id);
    int countRows(std::string tableName);
    void readRecord(long long id);
    int updateRecordInTable(long long id, std::string column, std::string attribute);
    int tableCount();
    int createStudentTable();
    int insertIntoStudentTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string courseName);
    int createFacultyTable();
    int insertIntoFacultyTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string courseOne, std::string courseTwo, std::string courseThree, long double salary);
    int createStaffTable();
    int insertIntoStaffTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept, std::string jobTitle, long double salary);

protected:
};

#endif // DATABASE_H
