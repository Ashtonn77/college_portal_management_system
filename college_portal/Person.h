#ifndef PERSON_H
#define PERSON_H
#include <set>

class Person
{

public:
    Person(std::string fName = "Non-provided", std::string lName = "Non-provided", long long int id = 0, std::string e = "n/a", int age = 0);
    Person(const Person &source) : Person{source.firstName, source.lastName, source.idNumber, source.address, source.age} {}
    ~Person();
    void getDetails(Person &p);
    std::string userTitle{};

protected:
    std::string firstName{};
    std::string lastName{};
    long long int idNumber{};
    std::string address{};
    int age{};
};

#endif // PERSON_H
