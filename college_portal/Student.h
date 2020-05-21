#ifndef STUDENT_H
#define STUDENT_H

class Student
{


    private:
    friend class Teacher;
    std::string firstName;
    std::string lastName;

    public:
        Student(std::string n = "None", std::string l = "None");
        Student(const Student &source);
        ~Student();


};

#endif // STUDENT_H
