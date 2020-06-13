#ifndef DATABASE_H
#define DATABASE_H

class Database
{
public:
    Database();
    ~Database();

    int openDatabase();
    int createPersonTable();
    void checkTableState();
    int insertIntoTable(long long id, std::string name, std::string surname, int age, std::string address, std::string dept);
    int deleteRecordFromTable(long long id);
    int countRows();
    void readRecord(long long id);
    int updateRecordInTable(long long id, std::string column, std::string attribute);

protected:
};

#endif // DATABASE_H
