// 04 Fast Food.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

	std::string Join(char separator, std::queue<int>* q)
	{
		std::string result = std::string();

		bool isFirst = true;

		while (q->size() > 0)
		{
			int currentNum = q->front();
			q->pop();

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

int minMax(std::queue<int>*, bool);

int main()
{
	myString input;
	std::getline(std::cin, input);
	int quantityFood = stoi(input);

	std::getline(std::cin, input);
	std::queue<int> orders = input.ConvertStringToIntQueue();

	std::string output = std::string().append(std::to_string(minMax(&orders, true))).append(myString().NewLine());

	bool isExitLoop = false;

	while (!isExitLoop)
	{
		if (orders.size() > 0)
		{
			int currentOrder = orders.front();
			if (quantityFood - currentOrder >= 0)
			{
				quantityFood -= currentOrder;
				orders.pop();
			}
			else
			{
				isExitLoop = true;
			}
		}
		else
		{
			isExitLoop = true;
		}
	}

	if (orders.size() > 0)
	{
		output.append("Orders left: ").append(input.Join(' ', &orders));
	}
	else
	{
		output.append("Orders complete");
	}

    std::cout << output << std::endl;
}

int minMax(std::queue<int>* q, bool f)
{
	int minResult, maxResult;
	bool isFirst = true;
	std::queue<int> temp = std::queue<int>();

	while (q->size() > 0)
	{
		int currentNum = q->front();
		q->pop();
		temp.push(currentNum);

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

	while (temp.size() > 0)
	{
		int currentNum = temp.front();
		temp.pop();
		q->push(currentNum);
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

//You have a fast food restaurant and most of the food that you're offering is previously prepared. You need to know if you will have enough food to serve lunch to all of your customers. Write a program that checks the orders’ quantity. You also want to know the client with the biggest order for the day, because you want to give him a discount the next time he comes. 
//First, you will be given the quantity of the food that you have for the day (an integer number).  Next, you will be given a sequence of integers, each representing the quantity of an order. Keep the orders in a queue. Find the biggest order and print it. You will begin servicing your clients from the first one that came. Before each order, check if you have enough food left to complete it. If you have, remove the order from the queue and reduce the amount of food you have. If you succeeded in servicing all of your clients, print: 
//"Orders complete".
// If not, print:
//"Orders left: {order1} {order2} .... {orderN}".
//Input
//•	On the first line you will be given the quantity of your food - an integer in the range [0, 1000]
//•	On the second line you will receive a sequence of integers, representing each order, separated by a single space
//Output
//•	Print the quantity of biggest order
//•	Print "Orders complete" if the orders are complete
//•	If there are orders left, print them in the format given above
//Constraints
//•	The input will always be valid