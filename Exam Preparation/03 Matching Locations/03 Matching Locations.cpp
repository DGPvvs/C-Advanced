// 03 Matching Locations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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
	const std::string END = ".";

	myString input;

	std::map<std::string, std::string> names = std::map<std::string, std::string>();
	std::map<std::string, std::vector<std::string>> plases = std::map<std::string, std::vector<std::string>>();

	bool isLoopExit = false;

	while (!isLoopExit)
	{
		std::getline(std::cin, input);

		if (input == END)
		{
			isLoopExit = true;
		}
		else
		{
			std::vector<std::string> commands = input.Split(',');
			std::string name = commands[0];
			std::string latitude = commands[1];
			std::string longitude = commands[2];

			std::string location = latitude + " " + longitude;
			std::string nameLocation = latitude + "," + longitude;

			names[name] = nameLocation;

			if (!plases.count(location))
			{				
				plases[location] = std::vector<std::string>();
			}

			plases[location].push_back(name);
		}
	}

	isLoopExit = false;

	std::string output = std::string();

	while (!isLoopExit)
	{
		std::getline(std::cin, input);

		if (input == END)
		{
			isLoopExit = true;
		}
		else
		{
			std::vector<std::string> commands = input.Split(' ');
			myString key = commands[0];

			double num = 0;

			if (!key.TryParseDouble(num))
			{
				output
					.append(key)
					.append(",")
					.append(names[key])
					.append(myString().NewLine());
			}
			else
			{
				for (auto coord:plases[input])
				{
					output
						.append(coord)
						.append(",")
						.append(commands[0])
						.append(",")
						.append(commands[1])
						.append(myString().NewLine());
				}
			}
		}
	}

    std::cout << output;
}

//Write a program that reads names of places and their geographical coordinates in the format name, latitude, longitude(where latitude and longitude are floating - point numbers).No two locations will have the same name.Some locations may have the same coordinates.
//After all locations are entered, a single line containing the '.' (dot)character will be entered.
//After that, queries will be entered � the queries will either contain a name of a location, or latitude and longitude coordinates(entered as two floating point numbers separated by a single space).Print all locations that match the query in the same format that they were entered.
//After all queries are entered, a single line containing the '.' (dot)character will be entered.
