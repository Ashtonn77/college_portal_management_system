#ifndef STUDENTDB_H
#define STUDENTDB_H

class StudentDb
{
private:
    /* data */
public:
    StudentDb(/* args */);
    ~StudentDb();
    int countRows();
    int tableCount();
    int openDatabase();
    int createStudentTable();
    int createStudentCourseTable();
    int createCourseTable();
};

#endif // STUDENTDB_H