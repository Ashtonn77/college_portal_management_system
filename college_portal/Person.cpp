#include <iostream>
#include "Person.h"
#include "ErrorHandling.h"

ErrorHandling errChk;

Person::Person(std::string fName, std::string lName, long long int id, std::string e, int age)
    : firstName{fName}, lastName{lName}, idNumber{id}, address{e}, age{age} {}

Person::~Person() {}

//use set to check if file name exists
void Person::getDetails(Person &p, std::string dept)
{
    std::string temp{};
    std::string fName{};
    std::string lName{};
    long long int id{0};
    std::string resAdd{};
    p.departmentTitle = dept;

    std::cout << "Enter " << dept << "'s first name?  ";
    std::cin >> fName;
    fName = errChk.validStringInput(fName, "Re-enter first name__");
    p.firstName = fName;

    std::cout << "Enter " << dept << "'s last name?  ";
    std::cin >> lName;
    lName = errChk.validStringInput(lName, "Re-enter last name__");
    p.lastName = lName;

    std::cout << "Enter " << dept << "'s i.d number?  ";
    std::cin >> temp;
    id = std::stoll(errChk.validIntegerInput(temp, "Re-enter i.d number__"));
    p.idNumber = id;

    std::cout << "Enter " << dept << "'s age?  ";
    std::cin >> temp;
    age = std::stoi(errChk.validIntegerInput(temp, "Re-enter age__"));
    p.age = age;

    std::cout << "Enter " << dept << "'s residential address?  ";
    std::getline(std::cin >> std::ws, resAdd);
    resAdd = errChk.validAddress(resAdd, "Re-enter address__");
    p.address = resAdd;
}

long long Person::login()
{
    std::string temp{};
    long long id{0};
    std::cout << "Please enter your i.d number to login__" << std::endl;
    std::cin >> temp;
    id = std::stoll(errChk.validIntegerInput(temp, "Re-enter age__"));
    return id;
}
