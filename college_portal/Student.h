#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"


class Student : public Person
{
    public:
        Student(std::string fName = "Non-provided", std::string lName = "Non-provided"
    , long long int id = 0, std::string e = "n/a");
        ~Student();

    protected:

    private:
};

#endif // STUDENT_H
