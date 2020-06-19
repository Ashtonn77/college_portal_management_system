#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

class ErrorHandling
{
protected:
    /* data */
public:
    ErrorHandling(/* args */);
    ~ErrorHandling();
    bool checkIfAllLetters(std::string str);
    bool checkIfInteger(std::string num);
    bool matchChars(std::string chars);
    std::string validStringInput(std::string &str, std::string question);
    std::string validIntegerInput(std::string &str, std::string question);
    std::string validAddress(std::string &str, std::string question);
};

#endif //ERRORHANDLING_H