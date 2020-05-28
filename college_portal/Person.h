#ifndef PERSON_H
#define PERSON_H


class Person
{

    public:
    Person(std::string fName = "Non-provided", std::string lName = "Non-provided"
    , long long int id = 0, std::string e = "n/a");
    Person(const Person &source):Person{source.firstName, source.lastName, source.idNumber, source.email}{}
    ~Person();
    void getDetails(Person &p);
    void displayDetails(Person &p);

    protected:
    std::string firstName{};
    std::string lastName{};
    long long int idNumber{};
    std::string email{};


};

#endif // PERSON_H
