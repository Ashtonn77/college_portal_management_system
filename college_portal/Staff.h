#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"


class Staff : public Employee
{
    public:
        Staff(std::string fName = "Non-provided", std::string lName = "Non-provided"
    , long long int id = 0, std::string e = "n/a");
        ~Staff();

    protected:

    private:
};

#endif // STAFF_H
