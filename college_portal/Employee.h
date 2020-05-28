#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <Person.h>


class Employee : public Person
{
    public:
        Employee(std::string fName = "Non-provided", std::string lName = "Non-provided"
    , long long int id = 0, std::string e = "n/a");
        ~Employee();

    protected:

    private:
};

#endif // EMPLOYEE_H
