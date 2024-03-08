// 04 Snake Moves.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


int main()
{
	myString input;
	std::getline(std::cin, input);

	std::vector<int> dimensions = input.ConvertStringToIntVector();

	int n = dimensions[0];
	int m = dimensions[1];

	char** matrix = new char* [n];

	for (int r = 0; r < n; r++)
	{
		matrix[r] = new char[m];
	}

	std::getline(std::cin, input);

	std::queue<char> snake = std::queue<char>();
	for (int i = 0; i < input.length(); i++)
	{
		snake.push(input[i]);
	}

	if (input.length() > 0)
	{
		int r = 0;
		int c = 0;

		for (int i = 0; i < (n * m); i++)
		{
			char sh = snake.front();
			snake.pop();
			snake.push(sh);

			matrix[r][c] = sh;

			if (r % 2 == 0)
			{
				c++;
			}
			else
			{
				c--;
			}

			if (c == m)
			{
				c--;
				r++;
			}

			if (c < 0)
			{
				c++;
				r++;
			}
		}
	}

	std::string output = std::string();
	std::string temp = std::string();

	for (int r = 0; r < n; r++)
	{		
		temp.clear();
		for (int c = 0; c < m; c++)
		{
			temp.append(1, matrix[r][c]);
		}
		output.append(temp).append(myString().NewLine());
	}

	for (int r = 0; r < n; r++)
	{
		delete[] matrix[r];
	}

	delete[] matrix;

    std::cout << output;
}

//You are walking in the park and you encounter a snake! You are terrified, and you start running zig-zag, so the snake starts following you. 
//You have a task to visualize the snake’s path in a square form. A snake is represented by a string. The isle is a rectangular matrix of size NxM. A snake starts going down from the top-left corner and slithers its way down. The first cell is filled with the first symbol of the snake, the second cell is filled with the second symbol, etc. The snake is as long as it takes in order to fill the stairs completely – if you reach the end of the string representing the snake, start again at the beginning. After you fill the matrix with the snake’s path, you should print it.
//Input
//•	The input data should be read from the console. It consists of exactly two lines
//•	On the first line, you’ll receive the dimensions of the stairs in format: "N M", where N is the number of rows, and M is the number of columns. They’ll be separated by a single space
//•	On the second line you’ll receive the string representing the snake
//Output
//•	The output should be printed on the console. It should consist of N lines
//•	Each line should contain a string representing the respective row of the matrix
//Constraints
//•	The dimensions N and M of the matrix will be integers in the range [1 … 12]
//•	The snake will be a string with length in the range [1 … 20] and will not contain any whitespace characters
//Разхождате се в парка и срещате змия! Вие сте ужасени, и започвате да тичате зиг-заг, така че змията започва да ви следва.

//Имате задача да визуализирате пътя на змията в квадратна форма. Змия е представена от низ. На исляма е правоъгълна матрица с размер NxM.
//Змия започва да слиза от горния ляв ъгъл и се плъзга по пътя надолу. Първата клетка е изпълнена с първия символ на змията, втората клетка се пълни с втория символ и т.н.
//Змията е толкова дълга, колкото е необходимо, за да запълни стълбите напълно – ако стигнете до края на струната, представляваща змията, започнете отново в началото.
//След като запълните матрицата с пътя на змията, трябва да я отпечатате.

//Въвеждане
//·         Входните данни трябва да се четат от конзолата. Състои се от точно две линии

//·         На първия ред ще получите размерите на стълбите във формат: "NM", където N е броят на редовете , а M е броят на колоните. Те ще бъдат разделени с едно пространство

//·         На втория ред ще получите низът, представляващ змията

//Изход
//·         Изходът трябва да бъде отпечатан на конзолата. Тя трябва да се състои от N линии

//·         Всеки ред трябва да съдържа низ, представляващ съответния ред на матрицата

//Ограничения
//Размерите N и M на матрицата ще бъдат цяло число в диапазона [1 ... 12]
//Змията ще бъде низ с дължина в диапазона [1 ... 20] и няма да съдържа никакви знаци от whitespace

