#ifndef FACULTY_H
#define FACULTY_H

#include "Employee.h"

class Faculty : public Employee
{
public:
    Faculty(std::string fName = "Non-provided", std::string lName = "Non-provided", long long int id = 0, std::string e = "n/a", int age = 0);
    ~Faculty();
    void facultyTask(long long id, std::string tableName);
    void generalSchedule();
    int createStudentResult();
    int insertIntoStudentResult(long long id, std::string name, std::string surname, std::string subject, int result);
    int verifyForMarks(long long id, std::string tableName);

protected:
private:
};

#endif // FACULTY_H
