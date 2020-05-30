#include <iostream>
#include <fstream>
#include <set>
#include "Person.h"

Person::Person(std::string fName, std::string lName, long long int id, std::string e)
    :firstName{fName}, lastName{lName}, idNumber{id}, email{e} {}

Person::~Person() {}

//copy file names to text file to load to set to check for duplicates
void Person::database(std::string str)
{
    std::ofstream myFile;
    std::string fileName{"collegeDatabase/textFiles/" + userTitle + "Db.txt"};

    myFile.open(fileName, std::ios_base::app);

    if(myFile.is_open())
    {
        myFile << str << "\n";
    }

}

//load files into set to check for duplicates
void Person::countFiles(std::set<std::string> &arr)
{
    std::string line;
    std::ifstream personFile ("collegeDatabase/textFiles/" + userTitle + "Db.txt");
    if(personFile.is_open())
    {
        while(std::getline(personFile, line))
        {
            arr.insert(line);
        }
        personFile.close();
    }

}


//use set to check if file name exists
void Person::getDetails(Person &p)
{
    std::set<std::string> fileNames;
    countFiles(fileNames);
    std::set<std::string> oldFileNames;
    oldFileNames = fileNames;
    std::string fName{};
    std::string lName{};
    long long int id{0};
    std::string eMail{};

    std::cout << "What is your first name?  ";
    std::cin >> fName;
    p.firstName = fName;

    std::cout << "What is your last name?  ";
    std::cin >> lName;
    p.lastName = lName;

    std::cout << "What is your i.d number?  ";
    std::cin >> id;
    p.idNumber = id;

    std::cout << "What is your email address?  ";
    std::cin >> eMail;
    p.email = eMail;

    std::ofstream personFile;

    std::string fileName{"collegeDatabase/" + userTitle + "Details/" + std::to_string(id) + ".txt"};
    fileNames.insert(fileName);
    if(fileNames.size() == oldFileNames.size())//if name already exists sets will be same
    {
        std::cout << "I'm sorry, we already have this i.d number on file" << std::endl;
        exit (EXIT_FAILURE);
    }
    else
    {
        database(fileName);
        personFile.open(fileName);
        if(personFile.is_open())
        {
            personFile << fName << "\n";
            personFile << lName << "\n";
            personFile << id << "\n";
            personFile << eMail << "\n";
            personFile.close();
            std::cout << "success" << std::endl;
        }
        else
        {
            std::cout << "system error...unable to save details." << std::endl;
            exit (EXIT_FAILURE);
        }

    }

}



//display - change test name and read functionality
void test(std::string str, auto data)
{
    std::cout << "Your " << str << " is " << data << std::endl;
}

void Person::displayDetails(Person &p)
{
    std::cout << std::endl;
    std::string arr[4] {"First name", "Last name", "I.d number", "Email address"};
    int i{0};
    std::string line;
    std::ifstream personFile ("collegeDatabase/" + userTitle + "Details/" + std::to_string(p.idNumber) + ".txt");
    if(personFile.is_open())
    {
        while(std::getline(personFile, line))
        {
            test(arr[i], line);
            i++;
        }
        personFile.close();
    }
    else
    {
        std::cout << "system error...unable to get data" << std::endl;
    }

}
