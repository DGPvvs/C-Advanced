// 02 Rust.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
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

bool IsValidIndex(int, int, int, int);

int main()
{
	const int maxRow = 10;
	const int maxCol = 10;
    const char DOT = '.';
    const char RUST = '#';
    const char BEGUN = '!';

    char** matrix = new char* [maxRow];
	std::string input;

    for (int r = 0; r < maxRow; r++)
    {
        matrix[r] = new char[maxCol];
        
        std::getline(std::cin, input);

        for (int c = 0; c < maxCol; c++)
        {
            matrix[r][c] = input[c];
        }
    }

	std::getline(std::cin, input);

	int passes = stoi(input);

	for (int i = 0; i < passes; i++)
	{
		std::queue<Point> q = std::queue<Point>();

		for (int r = 0; r < maxRow; r++)
		{
			for (int c = 0; c < maxCol; c++)
			{
				if (matrix[r][c] == BEGUN)
				{
					Point point = Point(r, c);
					q.push(point);
				}
			}
		}

		while (q.size() > 0)
		{
			Point point = q.front();
			q.pop();

			int row = 0;
			int col = 0;

			for (int i = 0; i < 4; i++)
			{
				int row = point.GetRow();
				int col = point.GetCol();

				if (i == 0)
				{
					row--;
				}
				else if (i == 1)
				{
					row++;
				}
				else if (i == 2)
				{
					col--;
				}
				else
				{
					col++;
				}

				if (IsValidIndex(maxRow, maxCol, row, col) && matrix[row][col] != RUST)
				{
					matrix[row][col] = BEGUN;
				}
			}			
		}
	}

	std::string output = std::string();

	for (int r = 0; r < maxRow; r++)
	{
		for (int c = 0; c < maxCol; c++)
		{
			output
				.append(1, matrix[r][c]);
		}

		output.append("\r\n");
	}

	for (int r = 0; r < maxRow; r++)
	{
		delete[] matrix[r];
	}

	delete[] matrix;

	std::cout << output;
}

bool IsValidIndex(int maxRow, int maxCol, int row, int col)
{
	bool result = row >= 0 && row < maxRow;
	result = result && col >= 0 && col < maxCol;

	return result;
}

//You are given a 10x10 matrix representing a metal square, which has begun to rust.There are 3 types of symbols in the matrix – a . (dot)means a healthy part of the metal, a # indicates a rust - resistant part, and a !indicates a part that has begun to rust.
//There may be 0, 1 or more parts that have begun to rust.
//The rust spreads from a rusty cell to healthy cells by "infecting" adjacent cells directly above, to the right, below and to the left of itself(no diagonals), at the same time.The rust cannot infect cells that are indicated as rust resistant.Let's define the time it takes for all cells adjacent to a rusty cell to get infected as 1 unit.
//After reading the matrix, read a single integer – the elapsed time in units(as defined above) – and print a matrix representing how the metal square will look after the rust has been acting on it for that amount of time.
