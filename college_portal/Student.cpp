#include <iostream>
#include "Student.h"
#include "Database.h"

Database d;

Student::Student(std::string fName, std::string lName, long long int id, std::string e, int age)
    : Person{fName, lName, id, e, age} {}

Student::~Student() {}

void Student::studentInsert() { d.insertIntoTable(idNumber, firstName, lastName, age, address); }
void Student::studentDelete()
{
    long long id{};
    std::cout << "Enter i.d number of student you want to delete  ";
    std::cin >> id;
    d.deleteRecordFromTable(id);
}