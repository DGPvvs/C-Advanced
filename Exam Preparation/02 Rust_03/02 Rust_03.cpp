// 02 Rust_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
#include <cmath>

//Помощен клас съдържащ координаните на клеткана
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
	const int maxRow = 10;
	const int maxCol = 10;
	const char DOT = '.';
	const char RUST = '!';

	char** matrix = new char* [maxRow];
	std::string input;

	std::queue<Point> q = std::queue<Point>();
	//Запълване на матрицата и първоначално установяване на опашката с координатите на ръждивите клетки
	for (int r = 0; r < maxRow; r++)
	{
		matrix[r] = new char[maxCol];

		std::getline(std::cin, input);

		for (int c = 0; c < maxCol; c++)
		{
			matrix[r][c] = input[c];

			if (matrix[r][c] == RUST)
			{
				Point point = Point(r, c);
				q.push(point);
			}
		}
	}

	std::getline(std::cin, input);

	int passes = stoi(input);
	
	for (int i = 0; i < passes; i++)
	{
		int currentCount = q.size(); // Текуща дължина на опашката - определя броя ръждясали полета за текущия етап

		//Цикъл, повтарящ се за всяко ново ръждясало поле от текущият етап
		while (currentCount > 0)
		{
			//Извличане на координатите (индексине) на текущо ръждясало поле от опашката
			//и премахването му от опашката
			Point point = q.front();
			q.pop();
			currentCount--;

			int row = 0;
			int col = 0;

			//Цикъл определящ четирите съседни полета, на текущото ръждясало поле
			//При наличие на поле извън границите на матрицата се взема граничната валидна стойност за текущата дименсия
			for (int directionNumber = 0; directionNumber < 4; directionNumber++)
			{
				row = point.GetRow();
				col = point.GetCol();

				switch (directionNumber)
				{
				case 0:
					row = std::max(--row, 0);
					break;

				case 1:
					row = std::min(++row, maxRow - 1);
					break;

				case 2:
					col = std::max(--col, 0);
					break;

				case 3:
					col = std::min(++col, maxCol - 1);
					break;

				default:
					break;
				}

				//Проверява се дали новата съседна позиция не е заразена.
				//Ако не е вече заразена, значи позицията е новозаразена, добавя се към опашката и
				//позицията се маркира като заразена.
				if (matrix[row][col] == DOT)
				{
					Point newPoint = Point(row, col);
					q.push(newPoint);
					matrix[row][col] = RUST;
				}
			}
		}
	}

	//Изграждане на изходният стринг
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

	//Освобождаване на динамично заделената памет
	for (int r = 0; r < maxRow; r++)
	{
		delete[] matrix[r];
	}

	delete[] matrix;

	//Отпечатване на крайният резултат
	std::cout << output;
}

//You are given a 10x10 matrix representing a metal square, which has begun to rust.There are 3 types of symbols in the matrix – a . (dot)means a healthy part of the metal, a # indicates a rust - resistant part, and a !indicates a part that has begun to rust.
//There may be 0, 1 or more parts that have begun to rust.
//The rust spreads from a rusty cell to healthy cells by "infecting" adjacent cells directly above, to the right, below and to the left of itself(no diagonals), at the same time.The rust cannot infect cells that are indicated as rust resistant.Let's define the time it takes for all cells adjacent to a rusty cell to get infected as 1 unit.
//After reading the matrix, read a single integer – the elapsed time in units(as defined above) – and print a matrix representing how the metal square will look after the rust has been acting on it for that amount of time.
