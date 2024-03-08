// 1 Reverse String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string input;
	std::getline(std::cin, input);

	std::stack<char> result = std::stack<char>();

	for (auto& it : input)
	{
		result.push(it);
	}

	while (result.size() > 0)
	{
		std::cout << result.top();
		result.pop();
	}

	std::cout << std::endl;
}

//Write a program that :
//●	Reads an input string
//●	Prints the input string in a reversed order
//Note : The words are reverted and the letters inside each word are reverted as well.
