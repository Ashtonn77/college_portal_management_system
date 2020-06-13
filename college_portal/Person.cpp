#include <iostream>
#include <regex>
#include "Person.h"

Person::Person(std::string fName, std::string lName, long long int id, std::string e, int age)
    : firstName{fName}, lastName{lName}, idNumber{id}, address{e}, age{age} {}

Person::~Person() {}

//use set to check if file name exists
void Person::getDetails(Person &p, std::string dept)
{

    std::string fName{};
    std::string lName{};
    long long int id{0};
    std::string resAdd{};
    p.departmentTitle = dept;

    std::cout << "Enter " << dept << "'s first name?  ";
    std::cin >> fName;
    p.firstName = fName;

    std::cout << "Enter " << dept << "'s last name?  ";
    std::cin >> lName;
    p.lastName = lName;

    std::cout << "Enter " << dept << "'s i.d number?  ";
    std::cin >> id;
    p.idNumber = id;

    std::cout << "Enter " << dept << "'s age?  ";
    std::cin >> age;
    p.age = age;

    std::cout << "Enter " << dept << "'s residential address?  ";
    std::getline(std::cin >> std::ws, resAdd);
    p.address = resAdd;
}
