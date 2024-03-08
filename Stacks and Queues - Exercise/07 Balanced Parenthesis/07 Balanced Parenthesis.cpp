// 07 Balanced Parenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::string inputText;
    std::getline(std::cin, inputText);

    std::stack<char> brackets = std::stack<char>();
    bool isBalanced = true;

    for (int i = 0; i < inputText.length() && isBalanced; i++)
    {
        char item = inputText[i];

        bool isOpenBracket = (item == '{') || (item == '[') || (item == '(');
        bool isCloseBracket = (item == '}') || (item == ']') || (item == ')');

        if (isBalanced)
        {
            if ((brackets.size() == 0) && (isOpenBracket))
            {
                brackets.push(item);
            }
            else if (isOpenBracket)
            {
                brackets.push(item);
            }
            else if ((isCloseBracket) && brackets.size() > 0)
            {
                if ((item == (brackets.top() + 1)) || (item == (brackets.top() + 2)))
                {
                    brackets.pop();
                }
                else
                {
                    isBalanced = false;
                }
            }
            else
            {
                isBalanced = false;
            }
        }
    }

    if ((isBalanced) && brackets.size() == 0)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

//Given a sequence consisting of parentheses, determine whether the expression is balanced. A sequence of parentheses is balanced if every open parenthesis can be paired uniquely with a closed parenthesis that occurs after the former. Also, the interval between them must be balanced. You will be given three types of parentheses: (, {, and[.
//{[()]}
//	-This is a balanced parenthesis.
//{[(])}
//	-This is not a balanced parenthesis.
//Input
//•	Each input consists of a single line, the sequence of parentheses.
//Output
//•	For each test case, print on a new line "YES" if the parentheses are balanced.
//Otherwise, print "NO".Do not print the quotes.
//Constraints
//•	1 ≤ lens ≤ 1000, where lens is the length of the sequence.
//•	Each character of the sequence will be one of {, }, (, ), [,].