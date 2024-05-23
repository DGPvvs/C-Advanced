// 06. Truck Tour_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include <utility>
#include <tuple>

/// <summary>
/// myString наследява класа string 
/// и добавя функционалности
/// </summary>
class myString :public std::string
{
private:
	const std::string EMPTY = "";
	const std::string NEW_LINE = "\r\n";

public:
	/// <summary>
	/// празев конструктор
	/// </summary>
	myString() :std::string()
	{

	}

	/// <summary>
	/// конструктор копие
	/// </summary>
	/// <param name="str"></param>
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

	/// <summary>
	/// метод връщащ празен стринг
	/// </summary>
	/// <returns></returns>
	static std::string Empty()
	{
		return "";
	}

	/// <summary>
	/// метод връщащ нов ред
	/// </summary>
	/// <returns></returns>
	static std::string NewLine()
	{
		return "\r\n";
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
			std::string s = (*it);

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

	static std::string Join(char separator, const std::queue<int>& q)
	{
		std::string result = std::string();

		std::queue<int> temp = std::queue<int>(q);

		bool isFirst = true;

		while (!temp.empty())
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

	static std::string Join(std::string separator, const std::stack<int>& st)
	{
		std::string result = std::string();

		std::stack<int> temp = std::stack<int>(st);

		bool isFirst = true;

		while (!temp.empty())
		{
			int currentNum = temp.top();
			temp.pop();

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(std::to_string(currentNum));
		}

		return result;
	}

	/// <summary>
	/// метод връщащ опашка от елементите на 
	/// текущата инстанция на myString
	/// </summary>
	/// <typeparam name="T">тип на елементите</typeparam>
	/// <returns></returns>
	template <class T>
	std::queue<T> ConvertStringToQueue()
	{
		std::stringstream iss(*this);

		T s;

		std::queue<T> result = std::queue<T>();
		while (iss >> s)
		{
			result.push(s);
		}

		return result;
	}

	/// <summary>
	/// метод връщащ стек от елементите на 
	/// текущата инстанция на myString
	/// </summary>
	/// <typeparam name="T">тип на елементите</typeparam>
	/// <returns></returns>
	template <class T>
	std::stack<T> ConvertStringToStack()
	{
		std::stringstream iss(*this);

		T number;

		std::stack<T> result = std::stack<T>();
		while (iss >> number)
		{
			result.push(number);
		}

		return result;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	template <class T>
	std::vector<T>& ConvertStringToVector(std::vector<T>& v)
	{
		std::stringstream iss(*this);

		T number;
		while (iss >> number)
		{
			v.push_back(number);
		}

		return v;
	}

	template <class T>
	std::vector<T> ConvertStringToVector()
	{
		std::vector<T> result = std::vector<T>();

		std::stringstream iss(*this);

		T number;
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
	myString input;
	std::getline(std::cin, input);
	int n = stoi(input);

	std::queue<std::pair<int, std::tuple<int, int>>> pumps = std::queue<std::pair<int, std::tuple<int, int>>>();

	for (int i = 0; i < n; i++)
	{
		std::getline(std::cin, input);
		std::vector<int> pumpVec = input.ConvertStringToVector<int>();

		int fuel = pumpVec[0];
		int distance = pumpVec[1];

		std::tuple<int, int> pump(fuel, distance);
		std::pair<int, std::tuple<int, int>> pumpWithIndex(i, pump);
		pumps.push(pumpWithIndex);
	}

	int countOfPump = 0;
	int currentStartIndex = -1;
	int currentFuel = 0;
	int noPumps = 0;

	while ((countOfPump < n) && (noPumps < 2 * n))
	{
		auto pump = pumps.front();
		pumps.pop();
		pumps.push(pump);

		noPumps++;
		currentFuel += std::get<0>(pump.second);

		if (currentFuel >= std::get<1>(pump.second))
		{
			countOfPump++;
			currentFuel -= std::get<1>(pump.second);

			if (currentStartIndex == -1)
			{
				currentStartIndex = pump.first;
			}
		}
		else
		{
			countOfPump = 0;
			currentFuel = 0;
			currentStartIndex = -1;
		}
	}

	std::string output = std::string();

	if (noPumps < 2 * n)
	{
		output.append(std::to_string(currentStartIndex));
	}
	else
	{
		output.append("No");
	}

	std::cout << output << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
