// 06 Truck Tour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class Pump
{
private:
	int num;
	int fuel;
	int distanceToNextPump;

public:
	Pump()
	{

	}

	Pump(int newNum, int newFuel, int newDistanceToNextPump)
	{
		this->setNum(newNum);
		this->setFuel(newFuel);
		this->setDistanceToNextPump(newDistanceToNextPump);
	}

	void setNum(int newNum)
	{
		this->num = newNum;
	}

	int getNum() const
	{
		return this->num;
	}

	void setFuel(int newFuel)
	{
		this->fuel = newFuel;
	}

	int getFuel() const
	{
		return this->fuel;
	}

	void setDistanceToNextPump(int newDistanceToNextPump)
	{
		this->distanceToNextPump = newDistanceToNextPump;
	}

	int getDistanceToNextPump() const
	{
		return this->distanceToNextPump;
	}
};

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

int main()
{
	myString input;
	std::getline(std::cin, input);
	int n = stoi(input);

	std::queue<Pump*> pumps = std::queue<Pump*>();

	for (int i = 0; i < n; i++)
	{
		std::getline(std::cin, input);
		std::vector<int> pumpVec = input.ConvertStringToIntVector();

		int fuel = pumpVec[0];
		int distance = pumpVec[1];

		Pump* pump = new Pump(i, fuel, distance);
		pumps.push(pump);
	}

	int countOfPump = 0;
	int currentStartIndex = -1;
	int currentFuel = 0;
	int noPumps = 0;

	while ((countOfPump < n) && (noPumps < 2 * n))
	{
		Pump* pump = pumps.front();
		pumps.pop();
		pumps.push(pump);

		noPumps++;
		currentFuel += pump->getFuel();

		if (currentFuel >= pump->getDistanceToNextPump())
		{
			countOfPump++;
			currentFuel -= pump->getDistanceToNextPump();

			if (currentStartIndex == -1)
			{
				currentStartIndex = pump->getNum();
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

//Suppose there is a circle. There are N petrol pumps on that circle. Petrol pumps are numbered 0 to (N−1) (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.
//Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each liter of the petrol.
//Input
//•	The first line will contain the value of N
//•	The next N lines will contain a pair of integers each, i.e. the amount of petrol that petrol pump will give and the distance between that petrol pump and the next petrol pump
//Output
//•	An integer which will be the smallest index of the petrol pump from which we can start the tour
//Constraints
//•	1 ≤ N ≤ 1000001
//•	1 ≤ Amount of petrol, Distance ≤ 1000000000