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
    int insertIntoTable(long long id, std::string name, std::string surname, int age, std::string address);
    int deleteRecordFromTable();
    int countRows();

protected:
};

#endif // DATABASE_H
