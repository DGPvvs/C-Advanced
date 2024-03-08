// 08 Even Times.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    std::cin >> n;

    set<int> numbers;
    set<int> evenNumbers;

    int currentNumber;

    for (int i = 0; i < n; ++i)
    {
        cin >> currentNumber;

        bool isContainsInNumbers = numbers.count(currentNumber);
        bool isContainsInEvenNumbers = evenNumbers.count(currentNumber);

        if (isContainsInNumbers)
        {
            if (isContainsInEvenNumbers)
            {
                evenNumbers.erase(currentNumber);
            }
            else
            {
                evenNumbers.insert(currentNumber);
            }
        }

        numbers.insert(currentNumber);
    }

    for (auto& number : evenNumbers) {
        cout << number << std::endl;
    }

    return 0;
}

//Write a program that prints a number from a collection, which appears an even number of times in it.On the first line, you will be given n – the count of integers you will receive.On the next n lines, you will be receiving the numbers.It is guaranteed that only one of them appears an even number of times.Your task is to find that number and print it in the end.