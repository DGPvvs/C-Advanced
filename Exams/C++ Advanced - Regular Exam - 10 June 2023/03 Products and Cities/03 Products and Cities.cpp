// 03 Products and Cities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input);
    int num = stoi(input);

    std::map<std::string, double> result = std::map<std::string, double>();

    bool isLoopExit = false;

    while (!isLoopExit)
    {
        if (result.size() == num)
        {
            isLoopExit = true;
        }
        else
        {
            std::string name;
            double price;
            int quolity;

            std::getline(std::cin, name);

            std::getline(std::cin, input);
            price = stod(input);

            std::getline(std::cin, input);
            quolity = stoi(input);

            if (!result.count(name))
            {
                result[name] = 0;
            }

            result[name] += price * quolity;
        }
    }

    for (int i = 0; i < num; i++)
    {
        
    }

    for (auto it:result)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
}

//By given a number of Cities, price per product and quantity of products, write a program that calculates the Total price(product* pricePerProduct).The first number is the number of cities we want to input.The second is the CITY.The third is the price per product.The fourth is the quantity of products.
//Input
//On the first line you will receive the number of cities.
//On the next lines you will receive the cities, followed by the price per product and quantity of products.
//Output
//Print the City followed by the result number.
