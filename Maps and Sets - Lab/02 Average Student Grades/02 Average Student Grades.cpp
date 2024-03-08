// 02 Average Student Grades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>

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

std::string FormatDoubleNum(double, int);

int main()
{
	myString input;
	std::getline(std::cin, input);

	int n = stoi(input);

	std::map<std::string, std::vector<double>> grades = std::map<std::string, std::vector<double>>();
	std::vector<std::string> orders = std::vector<std::string>();

	for (size_t i = 0; i < n; i++)
	{
		std::getline(std::cin, input);
		std::vector<std::string> inputs = input.Split(' ');

		std::string name = inputs[0];
		double grade = stod(inputs[1]);

		if (!grades.count(name))
		{
			std::vector<double> newStudent = std::vector<double>();
			
			grades.insert(std::pair<std::string, std::vector<double>> { name, newStudent });
			orders.push_back(name);
		}

		grades[name].push_back(grade);
	}

	std::string output = std::string();

	for (size_t i = 0; i < orders.size(); i++)
	{
		std::string s = std::string();
		double avrGrade = .0;
		for (size_t j = 0; j < grades[orders[i]].size(); j++)
		{
			avrGrade += grades[orders[i]][j];
			s.append(FormatDoubleNum(grades[orders[i]][j], 2)).append(" ");
		}

		avrGrade = avrGrade / grades[orders[i]].size();

		output
			.append(orders[i])
			.append(" -> ")
			.append(s)
			.append("(avg: ")
			.append(FormatDoubleNum(avrGrade, 2))
			.append(")")
			.append(myString().NewLine());
	}

    std::cout << output << std::endl;
}

std::string FormatDoubleNum(double number, int precision)
{
	std::stringstream stream;

	stream.precision(precision);
	stream << std::fixed;

	stream << number;

	return stream.str();
}

//Write a program, which reads a name of a student and their grades and adds them to the student record, then prints the students' names with their grades and their average grade.