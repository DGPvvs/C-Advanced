// 03 Glitches.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <queue>

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

int main()
{	
	const char DOT = '.';

	std::string input;
	std::getline(std::cin, input);
	int n = stoi(input);

	std::map<char, std::queue<Point>> bugs = std::map<char, std::queue<Point>>();

	char** matrix = new char* [n];

	for (int r = 0; r < n; r++)
	{
		matrix[r] = new char[n];

		std::getline(std::cin, input);

		for (int c = 0; c < n; c++)
		{
			matrix[r][c] = DOT;

			char ch = input[c];
			if (ch != DOT)
			{
				if (!bugs.count(ch))
				{
					std::queue<Point> q = std::queue<Point>();
				}

				Point p = Point(r, c);
				bugs[ch].push(p);
			}
		}
	}

	for (auto it: bugs)
	{
		int x = 0;
		int y = 0;
		char key = it.first;
		std::queue<Point> q = it.second;
		int n = q.size();

		while (q.size() > 0)
		{
			Point p = q.front();
			q.pop();

			x += p.GetRow();
			y += p.GetCol();
		}

		x = x / n;
		y = y / n;

		matrix[x][y] = key;
	}

	std::string output = std::string();

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			output
				.append(1, matrix[r][c]);
		}

		output.append("\r\n");
	}

	for (int r = 0; r < n; r++)
	{
		delete[] matrix[r];
	}

	delete[] matrix;

	std::cout << output;
}

//For this exam, the code for each task should be a single C++ file, the contents of which you copy - paste into the Judge system.
//Please be mindful of the strict input and output requirements for each task, as well as any additional requirements on running time, used memory, etc., as the tasks are evaluated automatically and not following the requirements strictly may result in your program’s output being evaluated as incorrect, even if the program’s logic is mostly correct.
//You can use C++03 and C++11 features in your code.
//3.	Glitches
//The agents in the Matrix have noticed a lot more glitches have been happening.In addition to that, each glitch seems to propagate to the adjacent cells(up, down, left, right), and then those cells propagate the glitch to their adjacent cells and so on.
//So, the glitches in the Matrix are symmetrical both horizontally and vertically and their height and width(as numbers of cells affected) are odd numbers.Another way to describe the glitches is to consider that each glitch has a center, and each glitch has a radius(in number of cells) which is an even number, and each cell that is at a Manhattan distance equal or less than the radius is part of the glitch.Manhattan distance in this case is calculated as the sum of the difference by row and by column – e.g.the Manhattan distance between cell[2][7] and cell[4][1] is(4 - 2) + (7 - 1) = 8.
//Additionally, each glitch has a different signature than the others – i.e.the cells in one glitch are differently affected than those in another glitch.
//The agents could of course write code to clear the glitches, but they suspect that Neo and his friends are causing the glitches and they think they can catch them by looking for the center of each glitch.So, they want code that clears the glitches but leaves their centers, so that they can look for Neo in those centers.
//Write a program that, when given a square matrix with glitches, clears everything in it except the centers of the glitches, and prints the resulting matrix.
//Input
//The first line of the standard input will contain a single positive integer number S – the size, i.e.the number of rows and columns in the square matrix.
//On each of the next S lines there will be exactly S characters, representing the cells in each row of the matrix.Normal(unaffected by glitches) cells will be described by the '.' (dot)symbol, and glitched cells will be described by one of the following symbols : !? @#$ % ^&*()_ + -= [] {} | :
//Output
//Exactly S lines, each containing exactly S characters representing the matrix, where each normal cell remains normal as in the input, and every glitched cell – except the centers of the glitches – is changed to a normal cell.
//Restrictions
//1 <= S <= 100.
//No two glitches will have the same symbol.
//There will be at least 1 normal cell horizontally and vertically between two glitches.
//There will be at least 1 glitch in the matrix.
//In 50 % of the tests there will be exactly 1 glitch.
//The total running time of your program should be no more than 0.1s
//The total memory allowed for use by your program is 16MB
//Hints
//Notice that the topmost affected cell of each glitch is exactly above the center, and the bottom is exactly below the center, and that the center is exactly between(the same distance from) the top and the bottom.Analogously for the leftmost and rightmost cell.
//Another way to look for the center is to consider that the center of each glitch is at the average of all of the coordinates of the glitch.