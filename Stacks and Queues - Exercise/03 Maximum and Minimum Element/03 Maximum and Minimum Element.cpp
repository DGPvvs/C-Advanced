// 03 Maximum and Minimum Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <stack>
#include <queue>

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

	std::queue<int> ConvertStringToIntQueue()
	{
		std::stringstream iss(*this);

		int number;

		std::queue<int> result = std::queue<int>();
		while (iss >> number)
		{
			result.push(number);
		}

		return result;
	}

	std::queue<std::string> ConvertStringToStringQueue()
	{
		std::stringstream iss(*this);

		std::string s;

		std::queue<std::string> result = std::queue<std::string>();
		while (iss >> s)
		{
			result.push(s);
		}

		return result;
	}

	std::stack<std::string> ConvertStringToStringStack()
	{
		std::stringstream iss(*this);

		std::string s;

		std::stack<std::string> result = std::stack<std::string>();
		while (iss >> s)
		{
			result.push(s);
		}

		return result;
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

std::string minMaxElement(std::stack<int>*, bool);
int minMax(std::queue<int>*, bool);

int main()
{
	const char PUSH = '1';
	const char DELETE = '2';
	const char PRINTMAXIMUM = '3';
	const char PRINTMINIMUM = '4';

	myString input;
	std::getline(std::cin, input);

	int count = stoi(input);
	std::stack<int> listStack = std::stack<int>();
	std::string output = std::string();

	for (int i = 0; i < count; i++)
	{
		std::getline(std::cin, input);

		std::vector<std::string> commands = input.Split(' ');

		switch (commands[0][0])
		{
		case PUSH:
			listStack.push(stoi(commands[1]));
			break;

		case DELETE:
			if (listStack.size() > 0)
			{
				listStack.pop();
			}
			break;

		case PRINTMAXIMUM:
			if (listStack.size() > 0)
			{
				output.append(minMaxElement(&listStack, true)).append(myString().NewLine());
			}
			break;

		case PRINTMINIMUM:
			if (listStack.size() > 0)
			{
				output.append(minMaxElement(&listStack, false)).append(myString().NewLine());
			}
			break;
		}
	}

	bool isFirst = true;

	while (listStack.size() > 0)
	{
		int currentNum = listStack.top();
		listStack.pop();

		if (isFirst)
		{
			output.append(std::to_string(currentNum));
			isFirst = false;
		}
		else
		{
			output.append(", ").append(std::to_string(currentNum));
		}
	}

	std::cout << output << std::endl;
}

std::string minMaxElement(std::stack<int>* st, bool f)
{
	std::queue<int> tempQ = std::queue<int>();
	std::stack<int> tempStack = std::stack<int>();

	while (st->size() > 0)
	{
		tempStack.push(st->top());
		st->pop();
	}

	while (tempStack.size() > 0)
	{
		int current = tempStack.top();
		tempStack.pop();
		tempQ.push(current);
		st->push(current);
	}

	int result = minMax(&tempQ, f);

	return std::to_string(result);
}

int minMax(std::queue<int>* q, bool f)
{
	int minResult, maxResult;
	bool isFirst = true;

	while (q->size() > 0)
	{
		int currentNum = q->front();
		q->pop();

		if (isFirst)
		{
			minResult = currentNum;
			maxResult = currentNum;
			isFirst = false;
		}
		else
		{
			minResult = std::min(minResult, currentNum);
			maxResult = std::max(maxResult, currentNum);
		}
	}

	if (f)
	{
		return maxResult;
	}
	else
	{
		return minResult;
	}
}

//You have an empty sequence, and you will be given N queries. Each query is one of these three types:
//1 x – Push the element x into the stack.
//2 – Delete the element present at the top of the stack.
//3 – Print the maximum element in the stack.
//4 – Print the minimum element in the stack.
//After you go through all of the queries, print the stack in the following format:
//"{n}, {n1}, {n2} …, {nn}"
//Input
//•	The first line of input contains an integer N
//•	The next N lines each contain an above-mentioned query
//Output
//•	For each type 3 or 4 queries, print the maximum/minimum element in the stack on a new line.
//Constraints
//•	1 ≤ N ≤ 105
//•	1 ≤ x ≤ 109
//•	1 ≤ type ≤ 4
//•	If there are no elements in the stack, don't print anything on commands 3 and 4.
