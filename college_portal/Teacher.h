#ifndef TEACHER_H
#define TEACHER_H

#include <Person.h>


class Teacher : public Person
{
    public:
        Teacher(std::string fName = "Non-provided", std::string lName = "Non-provided",
         long long int id = 0);
        ~Teacher();
        void display();
    protected:


};

#endif // TEACHER_H
