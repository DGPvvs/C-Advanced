// 01 Shopping List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

struct classcomp {
    bool operator() (const double& lhs, const double& rhs) const
    {
        return lhs > rhs;
    }
};

int main()
{
    std::string input;
    std::getline(std::cin, input);

    int n = stoi(input);

    std::map<double, std::vector<std::string>, classcomp> articles = std::map<double, std::vector<std::string>, classcomp>();
    double tottalSum = .0;

    for (int i = 0; i < n; i++)
    {
        std::string name;
        std::getline(std::cin, name);

        std::getline(std::cin, input);
        double price = stod(input);

        std::getline(std::cin, input);
        int count = stoi(input);

        double cost = count * price;
        tottalSum += cost;

        if (!articles.count(cost))
        {
            articles[cost] = std::vector<std::string>();
        }

        articles[cost].push_back(name);
    }

    std::cout << "The total sum is: " << tottalSum << " lv." << std::endl;

    for (auto article:articles)
    {
        double price = article.first;

        for (int i = 0; i < article.second.size(); i++)
        {
            std::cout << article.second[i] << " " << price << std::endl;
        }
    }
}

//Help Tom go to the supermarket.He has a list of Shopping Items with a price and count of each of them.
//Input
//•	On the first line, you are given an integer number of Shopping items.
//•	On the next lines, you are given :
//o	Name of Shopping Items
//o	Price of Item
//o	Shopping Item’s Count
//Note : There can only be one item with the same name.
//Output
//•	Print the total sum of the products – "The total sum is: {total sum} lv."
//•	Sort the Shopping Items by their final price.
//•	The final price is calculated by multiplying the Shopping Item’s count by the Shopping Item’s price(finalPrice = count * price)
//Note : If there are two or more items with the same price, print them in the order of their entrance.
