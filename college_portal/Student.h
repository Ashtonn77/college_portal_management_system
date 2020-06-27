#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person
{

public:
    Student(std::string fName = "Non-provided", std::string lName = "Non-provided", long long int id = 0, std::string e = "n/a", int age = 0);
    ~Student();
    void studentTask(long long id, std::string tableName);
    void studentRead(std::string dept, long long id);
    int readStudentCourse(long long id, std::string tableName);
    int createStudentAccountTable();
    int insertIntoStudentAccount(long long id, long double balance, std::string tableName);
    void makePayment(long long id);
    int readStudentBalance(long long id, std::string tableName);

protected:
};

#endif // STUDENT_H
