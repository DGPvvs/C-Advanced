// 3 Simple Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <stack>

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

	std::stack<int> ConvertStringToIntStack()
	{
		std::stringstream iss(*this);

		int number;

		std::stack<int> result = std::stack<int>();
		while (iss >> number)
		{
			result.push(number);
		}

		return result;
	}

	std::vector<int> ConvertStringToIntVector()
	{
		std::stringstream iss(*this);

		int number;
		std::vector<int> result = std::vector<int>();
		while (iss >> number)
		{
			result.push_back(number);
		}

		return result;
	}

	bool TryParseInt(int& num)
	{
		try
		{
			num = stoi(*this);
		}
		catch (...)
		{
			return false;
		}

		return true;
	}

	bool TryParseDouble(double& num)
	{
		try
		{
			num = stod(*this);
		}
		catch (...)
		{
			return false;
		}

		return true;
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

	bool Contains(char ch)
	{
		std::string s = std::string(1, ch);
		return this->Contains(s);
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
	myString input;
	std::getline(std::cin, input);

	std::vector<std::string> list = input.Split(' ');
	std::stack<myString> expresionStack = std::stack<myString>();

	for (int i = list.size() - 1; i >= 0; i--)
	{
		myString s = myString();
		s.append(list[i]);
		expresionStack.push(s);
	}

	while (expresionStack.size() > 1)
	{
		int operand1, operand2;
		myString action = myString();

		expresionStack.top().TryParseInt(operand1);
		expresionStack.pop();

		action.append(expresionStack.top());
		expresionStack.pop();

		expresionStack.top().TryParseInt(operand2);
		expresionStack.pop();


		if (action == "+")
		{
			operand1 = operand2 + operand1;
			myString s = myString();
			s.append(std::to_string(operand1));
			expresionStack.push(s);
		}
		else if (action == "-")
		{
			operand1 = operand1 - operand2;
			myString s = myString();
			s.append(std::to_string(operand1));
			expresionStack.push(s);
		}
	}

	std::cout << expresionStack.top() << std::endl;
}

//Write a program that:
//•	Reads an input string (expression) containing: numbers, + and -
//•	Evaluate the expression with only addition (+) and subtraction (-)
//•	Print the result
//Note: There will not be any parentheses.