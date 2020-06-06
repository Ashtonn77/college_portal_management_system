#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

class Admin : public Employee
{
public:
    Admin(std::string fName = "Non-provided", std::string lName = "Non-provided", long long int id = 0, std::string e = "n/a", int age = 0);
    ~Admin();

protected:
private:
};

#endif // ADMIN_H
