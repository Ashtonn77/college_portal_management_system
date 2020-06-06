#include <iostream>
#include "Person.h"

Person::Person(std::string fName, std::string lName, long long int id, std::string e, int age)
    : firstName{fName}, lastName{lName}, idNumber{id}, address{e}, age{age} {}

Person::~Person() {}

//use set to check if file name exists
void Person::getDetails(Person &p)
{

    std::string fName{};
    std::string lName{};
    long long int id{0};
    std::string resAdd{};

    std::cout << "What is your first name?  ";
    std::cin >> fName;
    p.firstName = fName;

    std::cout << "What is your last name?  ";
    std::cin >> lName;
    p.lastName = lName;

    std::cout << "What is your i.d number?  ";
    std::cin >> id;
    p.idNumber = id;

    std::cout << "What is your age?  ";
    std::cin >> age;
    p.age = age;

    std::cout << "What is your residential address?  ";
    std::cin >> resAdd;
    p.address = resAdd;
}
