#include <iostream>
#include <stdlib.h>

#include "ErrorHandling.h"

ErrorHandling::ErrorHandling(/* args */) {}

ErrorHandling::~ErrorHandling() {}

bool ErrorHandling::checkIfAllLetters(std::string str)
{
    for (auto s : str)
    {
        if (isdigit(s))
            return false;
    }
    return true;
}

bool ErrorHandling::checkIfInteger(std::string num)
{
    for (auto n : num)
    {
        if (!isdigit(n))
            return false;
    }
    return true;
}

std::string ErrorHandling::validStringInput(std::string &str, std::string question)
{
    while ((!checkIfAllLetters(str)) || str.length() < 2)
    {
        system("clear");
        if (str.length() < 2)
            std::cout << "Invalid entry...your input must be longer than a single character" << std::endl;
        else
            std::cout << "Invalid entry...keep it letters only" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cout << std::endl
                  << question << std::endl;
        std::cin >> str;
    }
    return str;
}

int ErrorHandling::validIntegerInput(std::string &str, std::string question)
{
    while ((!checkIfInteger(str)))
    {
        system("clear");

        std::cout << "Invalid entry...keep it integers only" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cout << std::endl
                  << question << std::endl;
        std::cin >> str;
    }
    return std::stoi(str);
}

//write valid function to validate address

// std::string ErrorHandling::validAddress(std::string &str, std::string question)
// {
//     std::regex noSpecial("[a-zA-Z0-9, -.]");
//     if (std::regex_match(str, noSpecial))
//         std::cout << "STRING IS GOOD";
//     else
//         std::cout << "STRING IS NO GOOD";
// }
// bool ErrorHandling::matchChars(std::string chars)
// {
//     std::regex valid("[a-zA-Z0-9.-, ]{4,}");
//     return std::regex_match(chars, valid);
// }
