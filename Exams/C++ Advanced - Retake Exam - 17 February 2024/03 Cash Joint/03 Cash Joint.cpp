// 03 Cash Joint.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

	std::string Join(std::string elementSeparator, std::string separator, std::map<std::string, int>& map)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (auto kVP : map)
		{
			std::string s = std::string().append(kVP.first).append(separator).append(std::to_string(kVP.second));

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(elementSeparator);
			}

			result.append(s);
		}

		return result;

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
				result.insert(0, separator);
			}

			result.insert(0, ss);

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

std::string FormatDoubleNum(double, int);

int main()
{
	const std::string END = "END";
	const std::string ADD = "+";
	const std::string SUB = "-";
	const std::string EXCHANGE = "X";
	const std::string PRINT = "P";

	std::vector<std::string> order = std::vector<std::string>();
	std::map<std::string, double> accounds = std::map<std::string, double>();

	myString input;
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
			auto task = input.Split(' ');

			auto ticker = task[0];
			auto amount = stod(task[1]);

			if (!accounds.count(ticker))
			{
				accounds[ticker] = 0;
				order.push_back(ticker);
			}

			accounds[ticker] += amount;
		}
	}

	std::string output = std::string();
	isLoopExit = false;

	while (!isLoopExit)
	{
		std::getline(std::cin, input);

		if (input == END)
		{
			isLoopExit = true;
		}
		else
		{
			auto task = input.Split(' ');

			auto command = task[0];

			if (command != PRINT)
			{
				auto ticker = task[1];
				auto amount = stod(task[2]);

				if (command == ADD)
				{
					if (accounds.count(ticker))
					{
						accounds[ticker] += amount;
					}					
				}
				else if (command == SUB)
				{
					if (accounds.count(ticker))
					{
						accounds[ticker] -= amount;
					}
				}
				else if (command == EXCHANGE)
				{
					auto account = task[3];
					auto rate = stod(task[4]);

					if (accounds.count(ticker) && accounds.count(account))
					{
						accounds[ticker] -= amount;
						accounds[account] += amount * rate;
					}
				}

			}
			else
			{
				for (auto o:order)
				{
					output.append(o).append(": ").append(FormatDoubleNum(accounds[o], 2)).append(input.NewLine());
				}
			}
		}
	}

    std::cout << output;
}

std::string FormatDoubleNum(double number, int precision)
{
	std::stringstream stream;

	stream.precision(precision);
	stream << std::fixed;

	stream << number;

	return stream.str();
}


//You're tasked to create the software for exchange office. Your software must have the following functionalities:
//1.	Support a number of currencies
//2.	Support the following commands :
//3.1.Adding currency ballance to an account
//3.2.Subtract currency ballance from an account
//3.3.Exchange currency ballance between accounts
//3.4.Print all balances
//3.5.Quit
//Input
//The first part of the input is your data initialization.You will currency balance initialization commands, each on a separate row.The commands will have the following format :
//CURRENCY_TICKER CURRENCY_AMOUNT
//Where :
//•	CURRENCY_TICKER is a three - letter abbreviation(e.g., the "ticker") of the currency, for example "USD", "BGN", "EUR" or "GBP"
//•	CURRENCY_AMOUNT is a double value, which instructs the program to initialize the respective "currency drawer" with this amount.
//o	If CURRENCY_TICKER is END, this means that all initial amounts are loaded, so now follows the second part of the initialization.
//The second part of the input are your "commands".Each command comes in a separate row.The list of the commands is as follows :
//Limitations:
//1.	You will always get correct input and output.
//2.	In the operations part, you’ll never get a currency, which was not initialized
//3.	It’s OK the amounts to become negative, do not add verification if you have enough money in the source currency when you exchange or subtract.