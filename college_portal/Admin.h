#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"

class Admin : public Employee
{
public:
    Admin(std::string fName = "Non-provided", std::string lName = "Non-provided", long long int id = 0, std::string e = "n/a", int age = 0);
    ~Admin();
    void task();
    void addNewAdmin();
    void personDelete(std::string dept);
    void personRead(std::string dept);
    void personUpdate(std::string dept);
    void addNewStudent();
    void addNewFaculty();
    void addNewStaff();
    void displayIdPrompt(std::string d, std::string c);

protected:
};

#endif // ADMIN_H
