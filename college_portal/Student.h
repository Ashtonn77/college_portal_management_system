#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Database.h"

class Student : public Person
{
    Database d;

public:
    Student(std::string fName = "Non-provided", std::string lName = "Non-provided", long long int id = 0, std::string e = "n/a", int age = 0);
    ~Student();
    void studentInsert() { d.insertIntoTable(idNumber, firstName, lastName, age, address); }

protected:
};

#endif // STUDENT_H
