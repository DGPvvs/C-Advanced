// 02 Fishes.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include <tuple>

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

std::string printBag(std::stack<std::string>*, int);
void SetMap(std::stack<std::string>&, std::map<std::string, int>&);


int main()
{
	const std::string END = "END";
	const std::string THROW = "THROW";

	std::stack<std::string> bag1 = std::stack<std::string>();
	std::stack<std::string> bag2 = std::stack<std::string>();
	std::stack<std::string> bag3 = std::stack<std::string>();

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
			std::vector<std::string> task = input.Split(' ');

			int bagNum = stoi(task[0]);
			std::string fish = task[1];
			if (task.size() > 2)
			{
				fish = fish + " " + task[2];
			}

			if (fish == THROW)
			{
				switch (bagNum)
				{
				case 1:
					if (bag1.size() > 0)
					{
						bag1.pop();
					}
					break;
				case 2:
					if (bag2.size() > 0)
					{
						bag2.pop();
					}
					break;
				case 3:
					if (bag3.size() > 0)
					{
						bag3.pop();
					}
					break;
				default:
					break;
				}

			}
			else
			{
				switch (bagNum)
				{
				case 1:
					bag1.push(fish);
					break;
				case 2:
					bag2.push(fish);
					break;
				case 3:
					bag3.push(fish);
					break;
				default:
					break;
				}
			}
		}
	}

	std::string output = std::string();

	std::map<std::string, int> tottalFishes = std::map<std::string, int>();

	for (int i = 0; i < 3; i++)
	{
		switch (i + 1)
		{
		case 1:
			output.append(printBag(&bag1, i + 1));
			SetMap(bag1, tottalFishes);
			break;
		case 2:
			output.append(printBag(&bag2, i + 1));
			SetMap(bag2, tottalFishes);
			break;
		case 3:
			output.append(printBag(&bag3, i + 1));
			SetMap(bag3, tottalFishes);
			break;
		default:
			break;
		}
	}

	isLoopExit = false;

	std::map<std::string, int> restaurant = std::map<std::string, int>();

	while (!isLoopExit)
	{
		std::getline(std::cin, input);

		if (input == END)
		{
			isLoopExit = true;
		}
		else
		{
			if (tottalFishes.count(input))
			{
				restaurant[input] = tottalFishes[input];
				tottalFishes.erase(input);
			}
		}

	}

	std::string s = "Restaurant: ";

	if (restaurant.size() > 0)
	{
		s.append(input.Join(", ", ": ", restaurant)).append(input.NewLine());
	}
	else
	{
		s.append("<nothing>").append(input.NewLine());
	}

	output.append(s);
	s = "Pate: ";

	if (tottalFishes.size() > 0)
	{
		s.append(input.Join(", ", ": ", tottalFishes)).append(input.NewLine());
	}
	else
	{
		s.append("<nothing>").append(input.NewLine());
	}

	output.append(s);

	std::cout << output;
}

std::string printBag(std::stack<std::string>* bag, int num)
{
	std::string result = std::string();

	if (bag->size() > 0)
	{
		return result
			.append(std::to_string(num))
			.append(": ")
			.append(myString().Join(", ", bag))
			.append(myString().NewLine());
	}

	return result
		.append(std::to_string(num))
		.append(": <empty>")
		.append(myString().NewLine());
}

void SetMap(std::stack<std::string>& bag, std::map<std::string, int>& map)
{
	while (bag.size() > 0)
	{
		std::string fish = bag.top();
		bag.pop();

		if (!map.count(fish))
		{
			map[fish] = 0;
		}

		map[fish]++;
	}
}

//You're a fisherman! You got three fishing poles, each one catching some fish.
//You also have three bags, where you store the fish from each pole.The fish from pole 1 always goes to bag 1, the fish from pole 2 – to bag 2, and the fish from pole 3 – to bag 3. Each fish you put in a bag is put on top of all other fishes, if there are such already in the bag.If you decide to takea fish from a bag, you can only pick the topmost fish, the one you put last.
//Each time, when a fishing pole catches a fish, you will get a line in your input, which gives you the pole number(1 to 3) and the kind of the fish it caught.For example "1 Sea Bass" (please note : the name of the fish may contain space).
//Also, there're two special input rows:
//1.	The input row "END" indicates that you're done with catching fishes and you move to the second stage of your task.
//2.	If you get a row with the special fish name "THROW", it means that you must throw out a fish at the top of the corresponding bag(the bag number will come with the command).For example : an input row "2 THROW" tells you to throw away a fish from bag 2.
//If bag 2 is empty, you just ignore the command.
//Once you're done with catching and throwing fishes, you must print all contents of your bags. Although you can pick up only the top-most fish from a bag, you must print the contents of each bag in the order you added the fish to the bag! Each bag contents are printed on a single row in the following format: 
//"1: Sea Bass, Swordfish, Swordfish"
//If a bag is empty, we print "<empty>" for its contents.
//After you print out the contents, you must sort your catch and decide which fish to keep for delivery to restaurants, and which fish to deliver for "fish pâté".To make this distribution, you will get a list of fish names : each one on a separate line, the list ends with "END".
//Each fish name you get tells you that all fishes from this kind in all your bags will go for "Restaurant" delivery.
//After the list of fishes for the restaurant ends, you must put all the remaining fishes from your bags for "fish pâté".
//Then you must print both inventories, each fish inventory containing the names of the fishes in alphabetical order, and then the quantity of each fish.The first line contains all fishes for the restaurants, the second line is all fish for pâté.Here’s example printout of both inventories :
//Restaurant: <Fish Name1> : <quantity1>, <Fish Name2> : <quantity2>, <Fish Name3> : <quantity3>
//Pate : <Fish Name1> : <quantity1>, <Fish Name2> : <quantity2>, <Fish Name3> : <quantity3>
//
//If there's no delivery for the restaurant or the pate, print "<nothing>" instead of fish list, for example:
//Restaurant : <Fish Name1> : <quantity1>, <Fish Name2> : <quantity2>, <Fish Name3> : <quantity3>
//Pate : <nothing>
//Hints :
//    1.	If you manually transfer all elements from one stack to another stack, you reverse the elements from the first stack.
//    2.	If you have a line like "5 Some Text Here" in your istringstream istr, you can read the number with the >> operator, and after that you can get the rest of the contents of the current line by using the getline like that : getline(std::ws(istr), theRestOfTheTextWithoutWhitespace).In this case, the first parameter of getline "eats" the whitespace before the text.
//    Or, you can decide to handle the whitespace differently.