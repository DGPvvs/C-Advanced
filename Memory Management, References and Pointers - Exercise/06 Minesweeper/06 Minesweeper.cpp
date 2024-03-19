// 06 Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

class Point
{
private:
	const int EQUAL = 0;
	const int LESS = -1;
	const int GREAT = 1;

	int row, col;


public:
	Point()
	{
		this->row = 0;
		this->col = 0;
	}

	Point(int r, int c)
	{
		this->SetRow(r);
		this->SetCol(c);
	}

	Point(const Point& point)
	{
		this->SetRow(point.GetRow());
		this->SetCol(point.GetCol());
	}

	Point& operator=(const Point& that)
	{
		if (this != &that)
		{
			this->SetRow(that.GetRow());
			this->SetCol(that.GetCol());
		}

		return *this;
	}

	~Point()
	{

	}

	int GetRow() const
	{
		return this->row;
	}

	void SetRow(int r)
	{
		this->row = r;
	}

	int GetCol() const
	{
		return this->col;
	}

	void SetCol(int c)
	{
		this->col = c;
	}

	int CompareTo(Point other) const
	{
		int comp = this->GetRow() - other.GetRow();

		if (comp == 0)
		{
			comp = this->GetCol() - other.GetCol();
		}

		int result = comp == 0 ? EQUAL : comp > 0 ? GREAT : LESS;

		return result;
	}
};

bool IsValidIndexses(int, int, int, int);

int main()
{
	const char MINE = '!';
	myString input;
	std::getline(std::cin, input);

	std::vector<int> dimensions = input.ConvertStringToIntVector();

	int n = dimensions[0];
	int m = dimensions[1];

	int** matrix = new int* [n];

	auto q = std::queue<Point>();

	for (int r = 0; r < n; r++)
	{
		std::getline(std::cin, input);

		matrix[r] = new int[m];

		for (int c = 0; c < m; c++)
		{
			matrix[r][c] = 0;
			if (input[c] == MINE)
			{
				Point point = Point(r, c);
				q.push(point);
			}
		}
	}

	while (q.size() > 0)
	{
		Point point = q.front();
		q.pop();

		int row = point.GetRow();
		int col = point.GetCol();

		for (int r = row - 1; r <= row + 1; r++)
		{
			for (int c = col - 1; c <= col + 1; c++)
			{
				if (IsValidIndexses(n, m, r, c))
				{
					matrix[r][c] += 1;
				}
			}
		}
	}

	std::string output = std::string();

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			output
				.append(std::to_string(matrix[r][c]));
		}

		output.append(myString().NewLine());
	}

	for (int r = 0; r < n; r++)
	{
		delete[] matrix[r];
	}

	delete[] matrix;

	std::cout << output;
}

bool IsValidIndexses(int maxRow, int maxCol, int r, int c)
{
	bool result = r >= 0 && r < maxRow;
	result = result && c >= 0 && c < maxCol;

	return result;
}

//You are given an N by M matrix(N and M are two integers entered on the console), in which the cells contain single characters – either a . (dot) or a !(exclamation mark) – representing "empty" or "mined" positions.
//Write a program that prints an N by M matrix, where each cell contains a number, representing how many adjacent cells, including itself, are "mined".
//Each cell in a matrix has at most 8 adjacent cells – the cells directly above, below, to the left, to the right, as those diagonally – to the left and above, to the right and above, to the right and below and to the left and below.