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
        int insertIntoTable();
    protected:


};

#endif // DATABASE_H
