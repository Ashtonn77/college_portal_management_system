#ifndef FACULTY_H
#define FACULTY_H

#include "Employee.h"

class Faculty : public Employee
{
public:
    Faculty(std::string fName = "Non-provided", std::string lName = "Non-provided", long long int id = 0, std::string e = "n/a", int age = 0);
    ~Faculty();

protected:
private:
};

#endif // FACULTY_H
