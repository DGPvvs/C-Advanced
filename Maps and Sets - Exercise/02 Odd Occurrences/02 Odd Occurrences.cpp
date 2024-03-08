// 02 Odd Occurrences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>

class myString :public std::string
{
private:
	const std::string EMPTY = "";
	const std::string NEW_LINE = "\r\n";

	myString(int l)
	{
		this->value = new char[l + 1];
		for (int i = 0; i < l; i++)
		{
			this->value[i] = '\0';
		}

		this->len = l;
	}		

	char* value;
	int len;

public:
	int getLen() const
	{
		return this->len;
	}

	const char* getString() const
	{
		return this->value;
	}

	char& operator[](int offset)
	{
		if (offset > this->len)
		{
			return this->value[this->len - 1];
		}
		else
		{
			return this->value[offset];
		}
	}

	char operator[](int offset) const
	{
		if (offset > this->len)
		{
			return this->value[this->len - 1];
		}
		else
		{
			return this->value[offset];
		}
	}

	myString(std::string cString) :std::string(cString)
	{
		this->len = cString.length();
		this->value = new char[this->len + 1];

		for (int i = 0; i < this->len; i++)
		{
			this->value[i] = cString[i];
		}

		this->value[this->len] = '\0';
	}

	myString(const char* const cString) :std::string(cString)
	{
		this->len = strlen(cString);
		this->value = new char[this->len + 1];

		for (int i = 0; i < this->len; i++)
		{
			this->value[i] = cString[i];
		}

		this->value[this->len] = '\0';
	}

	myString() :std::string()
	{
		this->value = new char[1];
		this->value[0] = '\0';
		this->len = 0;
	}

	myString(const myString& rhs)
	{
		this->len = rhs.getLen();
		this->value = new char[this->len + 1];

		for (int i = 0; i < this->len; i++)
		{
			this->value[i] = rhs[i];
		}

		this->value[this->len] = '\0';
	}

	myString& operator=(const myString& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		delete[] this->value;

		this->len = rhs.getLen();

		this->value = new char[this->len + 1];

		for (int i = 0; i < this->len; i++)
		{
			this->value[i] = rhs[i];
		}

		this->value[this->len] = '\0';

		return *this;
	}	

	std::string Empty()
	{
		return this->EMPTY;
	}
	std::string NewLine()
	{
		return this->NEW_LINE;
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

	static std::string Join(std::string separator, std::vector<myString> v)
	{
		std::string result = std::string();
		bool isFirst = true;		

		for (int i = 0; i < v.size(); i++)
		{
			std::string s = std::string(v[i]);

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
		std::string s = "";

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

		int it;
		for (it = 0; it < this->length(); it++)
		{
			this->value[it] = tolower(this->value[it]);
		}

		return this->value;
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
		delete[] this->value;

		this->len = 0;
	}
};

int main()
{
	myString input;
	std::getline(std::cin, input);
	std::vector<std::string> words = input.Split(' ');

	std::map<myString, int> wordsCount = std::map<myString, int>();

	for (std::string word : words)
	{
		myString s = myString(word);		
		s.ToLower();

		if (!wordsCount.count(s))
		{
			wordsCount[s] = 0;
		}

		wordsCount[s]++;
	}

	//delete &words;

	words = std::vector<std::string>();

	for (auto kVP : wordsCount)
	{
		if (kVP.second % 2 != 0)
		{
			words.push_back(kVP.first);
		}		
	}

	std::string output = myString::Join(", ", &words);

    std::cout << output << std::endl;
}

//Write a program that extracts from a given sequence of words all elements that appear in it an odd number of times(case-insensitive).
//•	Words are given in a single line, space - separated.
//•	Print the result elements in lowercase, in their order of appearance.
