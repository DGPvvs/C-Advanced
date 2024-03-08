// 01 Government Facility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <map>
#include <vector>

class myString :public std::string
{
private:
	const std::string EMPTY = "";
	const std::string NEW_LINE = "\r\n";

public:
	myString() :std::string()
	{

	}

	myString(const std::string& str) :std::string(str)
	{

	}

	myString(const std::string& str, size_t pos, size_t len = npos) :std::string(str, pos, len)
	{

	}

	myString(const char* s) :std::string(s)
	{

	}

	myString(const char* s, size_t n) :std::string(s, n)
	{

	}

	myString(size_t n, char c) :std::string(n, c)
	{

	}

	template <class InputIterator>  myString(InputIterator first, InputIterator last) : std::string(first, last)
	{

	}

	myString(std::initializer_list<char> il) :std::string(il)
	{

	}

	myString(std::string&& str) noexcept :std::string(str)
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

	std::string Join(std::string separator, std::set<int, std::greater<int>>* s)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::set<int, std::greater<int>>::iterator it = s->begin(); it != s->end(); it++)
		{
			std::string s = std::to_string(*it);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	std::string Join(std::string separator, std::set<double, std::greater<double>>* s)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::set<double, std::greater<double>>::iterator it = s->begin(); it != s->end(); it++)
		{
			std::string s = std::to_string(*it);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	static std::string Join(std::string separator, std::set<int>* s)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::set<int>::iterator it = s->begin(); it != s->end(); it++)
		{
			std::string s = std::to_string(*it);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	std::string Join(std::string separator, std::set<std::string>* s)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::set<std::string>::iterator it = s->begin(); it != s->end(); it++)
		{
			std::string s = *it;

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	std::string Join(std::string separator, std::stack<std::string>* s)
	{
		std::string result = std::string();
		std::stack<std::string> newStack = std::stack<std::string>(*s);
		bool isFirst = true;

		while (newStack.size() > 0)
		{
			std::string ss = newStack.top();
			newStack.pop();

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(ss);

		}

		return result;
	}

	std::string Join(std::string separator, std::vector<double>* v)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::vector<double>::iterator it = v->begin(); it != v->end(); it++)
		{
			std::string s = std::to_string(*it);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	std::string Join(std::string separator, std::vector<int>* v)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::vector<int>::iterator it = v->begin(); it != v->end(); it++)
		{
			std::string s = std::to_string(*it);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	static std::string Join(std::string separator, std::vector<std::string>* v)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::vector<std::string>::iterator it = v->begin(); it != v->end(); it++)
		{
			std::string s = *it;

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	std::string Join(char separator, std::queue<std::string>* q)
	{
		std::string result = std::string();

		std::queue<std::string> temp = std::queue<std::string>();

		bool isFirst = true;

		while (q->size() > 0)
		{
			std::string currentNum = q->front();
			q->pop();
			temp.push(currentNum);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(1, separator);
			}

			result.append(currentNum);
		}

		while (temp.size() > 0)
		{
			std::string currentNum = temp.front();
			temp.pop();
			q->push(currentNum);
		}

		return result;
	}


	std::string Join(char separator, std::queue<int>* q)
	{
		std::string result = std::string();

		std::queue<int> temp = std::queue<int>();

		bool isFirst = true;

		while (q->size() > 0)
		{
			int currentNum = q->front();
			q->pop();
			temp.push(currentNum);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(1, separator);
			}

			result.append(std::to_string(currentNum));
		}

		while (temp.size() > 0)
		{
			int currentNum = temp.front();
			temp.pop();
			q->push(currentNum);
		}

		return result;
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

	std::vector<double> ConvertStringToDoubleVector()
	{
		std::stringstream iss(*this);

		double number;
		std::vector<double> result = std::vector<double>();
		while (iss >> number)
		{
			result.push_back(number);
		}

		return result;
	}

	std::vector<int>* ConvertStringToIntVector(std::vector<int>* v)
	{
		std::stringstream iss(*this);

		int number;
		while (iss >> number)
		{
			v->push_back(number);
		}

		return v;
	}

	std::vector<int> ConvertStringToIntVector()
	{
		std::vector<int> result = std::vector<int>();

		std::stringstream iss(*this);

		int number;
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
		myString s = "";

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
	const std::string QUEUE_1 = "1";
	const std::string QUEUE_2 = "2";
	const std::string QUEUE_1_SUCCSES = "10";
	const std::string QUEUE_2_SUCCSES = "20";
	const std::string FROM_1_TO_2 = "12";
	const std::string FROM_2_TO_3 = "23";
	const std::string FROM_3_TO_1 = "31";
	const std::string PRINT = "99";
	const std::string END = "5";

	const std::string EMPTY = "<empty>";

	std::queue<std::string> one = std::queue<std::string>();
	std::queue<std::string> two = std::queue<std::string>();
	std::stack<std::string> three = std::stack<std::string>();

	bool isLoopExit = false;

	std::string output = std::string();

	while (!isLoopExit)
	{
		myString input;
		std::getline(std::cin, input);

		if (input == END)
		{
			isLoopExit = true;
		}
		else
		{
			if (input == QUEUE_1_SUCCSES)
			{
				if (one.size() > 0)
				{
					one.pop();
				}
			}
			else if (input == QUEUE_2_SUCCSES)
			{
				if (two.size() > 0)
				{
					two.pop();
				}
			}
			else if (input == FROM_1_TO_2)
			{
				if (one.size() > 0)
				{
					two.push(one.front());
					one.pop();
				}
			}
			else if (input == FROM_2_TO_3)
			{
				if (two.size() > 0)
				{
					three.push(two.front());
					two.pop();
				}
			}
			else if (input == FROM_3_TO_1)
			{
				if (three.size() > 0)
				{
					one.push(three.top());
					three.pop();
				}
			}
			else if (input == PRINT)
			{
				output.append("1: ").append(one.size() > 0 ? input.Join(' ', &one) : EMPTY).append(myString().NewLine());
				output.append("2: ").append(two.size() > 0 ? input.Join(' ', &two) : EMPTY).append(myString().NewLine());
				output.append("3: ").append(three.size() > 0 ? input.Join(" ", &three) : EMPTY).append(myString().NewLine());
			}
			else
			{
				std::vector<std::string> commands = input.Split(' ');

				if (commands[1] == QUEUE_1)
				{
					one.push(commands[0]);
				}
				else
				{
					two.push(commands[0]);
				}
			}
		}
	}

	std::cout << output;
}

//You're visiting one of the most weird government institutions. Thankfully, you're just a visitor, but while you wait for your friend to finish their business there, you watch some weird queues that form up on this place.
//You see two normal queues(let's call them queue 1 and 2) in front of two counters. You also see a row of chairs (let's call it 3).The row of chairs 3 is very strange : people, who sit there last, are first called!This seems very unfair to you, but that's how this administration works.
//You notice that the most lucky people just go on one queue, wait for their turn, and then get their job done on the counter and leave the facility.
//You also notice that some unlucky people, after they're called on the counter, they are sent from the counter to either the other queue, or to the row of chairs 3 to wait there to be called.
//You decide to create a program to track the status of these three lines.
//The commands can be :
//-A name(without any spaces), followed by a number(1 or 2).This means that a new person enters the facility and goes either to queue 1 or 2.
//- A number, as follows :
//o	10 means a person from queue 1 is served and happily leaves the facility, so they're not present anymore in any of the three structures.
//o	20 means a person from queue 2 is served and happily leaves the facility, so they're not present anymore in any of the three structures.
//o	12 means a person from queue 1 is served, but then they’re sent to queue 2 to wait there.
//o	23 means a person from queue 2 is sent to the row of chairs 3, to wait to be called from there.
//o	31 means a person from the row of chairs 3 is called to wait to queue 1.
//o	99 means you must print the three structures in the order how people will get called from them :
//	You print queue 1 as "1: " and then all names, separated with a single space, and then a new line.
//	You print queue 2 as "2: " and then all names, separated with a single space, and then a new line.
//	You print the row of chairs as "3: " and then all names, separated with a single space, and then a new line.
//	Note : If any of the structures above is empty, print “<empty>”(see example below)
//o	5  means "end", you're done, your program finishes.
//- There are no other commands to consider!