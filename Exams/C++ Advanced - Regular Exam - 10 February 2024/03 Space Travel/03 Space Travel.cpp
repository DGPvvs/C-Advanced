// 03 Space Travel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <cmath>
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

		std::queue<std::string> temp = std::queue<std::string>(*q);

		bool isFirst = true;

		while (temp.size() > 0)
		{
			std::string currentNum = temp.front();
			temp.pop();

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

		return result;
	}

	std::string Join(char separator, std::queue<int>* q)
	{
		std::string result = std::string();

		std::queue<int> temp = std::queue<int>(*q);

		bool isFirst = true;

		while (temp.size() > 0)
		{
			int currentNum = temp.front();
			temp.pop();

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

	std::string to_string(double s)
	{
		std::stringstream ss;
		ss << s;

		std::string output = std::string();
		output = ss.str();

		return output;
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
	const std::string END = "END";

	std::vector<std::string> planets = std::vector<std::string>();
	bool isLoopExit = false;
	myString input;

	while (!isLoopExit)
	{
		std::getline(std::cin, input);

		if (input == END)
		{
			isLoopExit = true;
		}
		else
		{
			planets.push_back(input);
		}
	}

	int n = planets.size();

	auto distancies = std::map<int, std::vector<std::tuple<std::string, std::string>>>();
	auto destinations = std::map<std::string, std::map<std::string, int>>();

	bool isNotFirst = false;
	int minDist = 0, maxDist = 0;

	for (int r = 0; r < n; r++)
	{
		std::getline(std::cin, input);

		std::vector<int> distRow = input.ConvertStringToIntVector();
		destinations[planets[r]] = std::map<std::string, int>();
		for (int c = 0; c < n; c++)
		{
			destinations[planets[r]][planets[c]] = distRow[c];

			if (!distancies.count(distRow[c]))
			{
				distancies[distRow[c]] = std::vector<std::tuple<std::string, std::string>>();
			}

			std::tuple<std::string, std::string> t(planets[r], planets[c]);

			distancies[distRow[c]].push_back(t);

			if (distRow[c] != 0)
			{
				if (isNotFirst)
				{
					minDist = std::min(minDist, distRow[c]);
					maxDist = std::max(maxDist, distRow[c]);
				}
				else
				{
					minDist = maxDist = distRow[c];
					isNotFirst = true;
				}
			}
		}
	}

	int i = 0;
	std::string output = std::string();

	while (i < 2)
	{
		int k = minDist;
		if (i == 1)
		{
			k = maxDist;
		}

		for (int j = 0; j < distancies[k].size(); j++)
		{
			output
				.append(std::to_string(k))
				.append(": ")
				.append(std::get<0>(distancies[k][j]))
				.append(" -> ").append(std::get<1>(distancies[k][j]))
				.append(myString().NewLine());
		}

		i++;
	}

	isLoopExit = false;
	int allSum = 0;

	while (!isLoopExit)
	{
		std::getline(std::cin, input);

		if (input == END)
		{
			isLoopExit = true;
		}
		else
		{
			std::queue<std::string> q = input.ConvertStringToStringQueue();
			int sum = 0;
			do
			{
				std::string planet1 = q.front();
				q.pop();
				std::string planet2 = q.front();

				sum += destinations[planet1][planet2];
			} while (q.size() > 1);

			allSum += sum;
			output
				.append(std::to_string(sum))
				.append(myString().NewLine());
		}
	}

	output
		.append(std::to_string(allSum))
		.append(myString().NewLine());

	std::cout << output;
}

//You're one of the science officers of a space carrier: a huge ship, which visits unknown solar systems and obtains astronomical data about them. You must write a program, which will analyze the live data of solar's system orbiting bodies and will be able to execute commands and return data results.
//Input
//Your program receives the following input data :
//1.	The names of the bodies of the system, each one on a single row.If the name equals "END", that means all the names of the solar system are received.
//a.The first name is always the name of the Star of the solar system.
//b.Names of the bodies will never contain a space.
//c.There will be no more than 20 bodies in each solar system, including the main star.
//2.	After the names, you will receive a square matrix of integers, which gives the "time to travel" between each one of the bodies(in hours).
//a.Due to specifics of the space travel, travelling from A to B may take 40 hours, but at the same time travelling from B to A may take 24 hours, e.g.the matrix is not symmetrical!
//3.	After the travel data, you will receive a number of rows with names of the bodies, each separated with space.Each row describes a path in the system, which passes around each one of the bodies.
//4.	If you read a row that says “END”.

//Output
//1.	After you read the travel time matrix(point 2 above), find out and print:
//a.The shortest time to travel between two single points in the system, e.g.from which point to which point would take the least time to travel.
//b.The longest time to travel between two single points in the system.
//c.Note : there might be more then one shortest and /or longest routes.In this case you must print all of them.
//2.	After you read each row of travel itinerary(point 3 above), calculate the total time, needed to travel for the row, and print it out on a single row
//3.	After the input finishes(after the last END), print out the sum of all travel routes.

//Hints:
	//1.	You will need to remember the order, in which your bodies come.
		//2.	You will need a square matrix of integers, in which the index of each element is the index of the body in the initial list.Remember how to find an element’s index in a vector(the input vector of all bodies), and use that index in the matrix.