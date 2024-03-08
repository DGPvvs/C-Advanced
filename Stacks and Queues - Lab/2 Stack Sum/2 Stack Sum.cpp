// 2 Stack Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

	const std::string END = "end";
	const std::string ADD = "add";
	const std::string REMOVE = "remove";

	myString input;
	std::getline(std::cin, input);

	std::stack<int> resultStack = input.ConvertStringToIntStack();

	std::vector<std::string> commands = std::vector<std::string>();

	bool isLoopExit = false;

	while (!isLoopExit)
	{
		std::getline(std::cin, input);
		std::vector<std::string> commands = input.Split(' ');

		if (commands[0] == ADD)
		{
			resultStack.push(stoi(commands[1]));
			resultStack.push(stoi(commands[2]));
		}
		else if (commands[0] == REMOVE)
		{
			if (resultStack.size() >= stoi(commands[1]))
			{
				for (int i = 0; i < stoi(commands[1]); i++)
				{
					resultStack.pop();
				}
			}
		}
		else if (commands[0] == END)
		{
			isLoopExit = true;
		}
	}

	int sum = 0;

	while (resultStack.size() > 0)
	{
		sum += resultStack.top();
		resultStack.pop();
	}

	std::cout << sum << std::endl;
}

//Write a program that :
//•	Reads an input of integer numbers and adds them to a stack
//•	Reads commands until "end" is received
//•	Prints the sum of the remaining elements of the stack
//Input
//•	On the first line, you will receive an array of integers.
//•	On the next lines, until the "end" command is given, you will receive commands – a single command and one or two numbers after the command, depending on what command you are given.
//•	If the command is "add", you will always receive exactly two numbers after the command which you need to add to the stack.
//•	If the command is "remove", you will always receive exactly one number after the command which represents the count of the numbers you need to remove from the stack.If there are not enough elements skip the command.
//Output
//•	When the command "end" is received, you need to print the sum of the remaining elements in the stack.
