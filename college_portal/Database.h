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

protected:
};

#endif // DATABASE_H
