// 01 Gauss' Trick.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class myString :public std::string
{
private:
    const std::string EMPTY = "";
    const std::string NEW_LINE = "\r\n";

public:
    myString(const char* s) :std::string(s)
    {

    }

    myString() :std::string()
    {

    }

    std::string Empty()
    {
        return this->EMPTY;
    }
    std::string NewLine()
    {
        return this->NEW_LINE;
    }

    std::vector<std::string> Split(char ch)
    {
        std::vector<std::string> result;
        std::string s = this->EMPTY;

        std::stringstream ss(*this);

        while (getline(ss, s, ch))
        {
            result.push_back(s);
        }

        return result;
    }

    std::vector<std::string> Split(std::string separator)
    {
        const std::string REPLACE_STRING_SEPARATOR = "\n";
        const char REPLACE_CHAR_SEPARATOR = REPLACE_STRING_SEPARATOR[0];

        std::vector<std::string> result;
        std::string s = std::string(*this);

        int idx = s.find(separator);

        while (idx > -1)
        {
            s.replace(idx, separator.length(), REPLACE_STRING_SEPARATOR);
            idx = s.find(separator);
        }

        std::stringstream ss(s);

        while (getline(ss, s, REPLACE_CHAR_SEPARATOR))
        {
            result.push_back(s);
        }

        return result;
    }

    bool Contains(std::string f)
    {
        int idx = this->find(f);
        return idx > -1;
    }

    std::string ToLower()
    {
        std::string s = std::string("");

        std::string::iterator it;
        for (it = this->begin(); it != this->end(); it++)
        {
            s.append(1, tolower(*it));
        }

        return s;
    }

    std::string ToUpper()
    {
        std::string s = std::string("");

        std::string::iterator it;
        for (it = this->begin(); it != this->end(); it++)
        {
            s.append(1, toupper(*it));
        }

        return s;
    }

    ~myString()
    {

    }
};


int main()
{
    myString text;
    std::getline(std::cin, text);

    std::vector<std::string> stringVec = text.Split(' ');

    std::vector<int> resultVec = std::vector<int>();

    for (std::vector<std::string>::iterator it = stringVec.begin(); it != stringVec.end(); it++)
    {
        resultVec.push_back(stoi(*it));
    }

    std::string output = std::string();

    bool isFirst = true;
    bool isSizeOdd = resultVec.size() % 2 != 0;
    for (int i = 0; i < (resultVec.size() / 2) + isSizeOdd; i++)
    {
        int sum = resultVec[i] + resultVec[resultVec.size() - 1 - i];
        if (i == resultVec.size() - 1 - i)
        {
            sum /= 2;
        }

        if (isFirst)
        {
            output.append(std::to_string(sum));
            isFirst = false;
        }
        else
        {
            output.append(" ").append(std::to_string(sum));
        }
    }

    std::cout << output << std::endl;
}

//Write a program that sums all of the numbers in a list in the following order :
//first + last, first + 1 + last - 1, first + 2 + last - 2, … first + n, last - n.