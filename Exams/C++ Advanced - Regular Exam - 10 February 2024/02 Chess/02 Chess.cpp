// 02 Chess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    const int n = 8;
	const char EMPTY = '.';
	const char a = 'a';
	const char A = 'A';
	std::string whileFigure = std::string();
	std::string blackFigure = std::string();
	std::string output = std::string();

	std::string input;
	bool isWhite = false;
	bool isBlack = false;

	for (int r = 0; r < n; r++)
	{
		std::getline(std::cin, input);

		for (int c = 0; c < n; c++)
		{
			char ch = input[c];
			if (ch != EMPTY)
			{
				if (ch < a)
				{
					whileFigure.append(1, ch);
					isWhite = true;
					ch = ch + (a - A);
				}
				else
				{
					blackFigure.append(1, ch);
					isBlack = true;
					ch = ch - (a - A);
				}
			}
			output.append(1, ch);
		}

		output.append("\r\n");
	}

	if (!isWhite)
	{		
		whileFigure.append("<no white figures>");
	}

	if (!isBlack)
	{
		blackFigure.append("<no black figures>");
	}

	blackFigure.append("\r\n");
	whileFigure.append("\r\n");	

	output.insert(0, blackFigure);
	output.insert(0, whileFigure);

    std::cout << output;
}

//You will read and analyze a chess board.
//Input
//The chess board is a 8 x 8 matrix of char.Each character represents a type of figurine, as follows :
//•	Type of the figurine :
//o	K for King
//o	Q for Queen
//o	R for Rook
//o	B for Bishop
//o	N for kNight
//o	P for Pawn
//o	. for empty space in the board
//•	Color of the figure :
//o	if it's a small letter, it's Black
//o	if it's a capital letter, it's White.In the description above the figurines are all white.
//o	For example : an input row "P.k..K.p" represents one row of the chessboard, with the following figurines :
//	on position 1 it has a white pawn;
//	then there's an empty square;
//	on position 3 there's the black King;
//	then there're two empty squares
//	then there's the white King
//	then there's an empty square
//	then there's a black pawn;
//Output
//After you read the chessboard, analyze the data and print the following :
//•	A list of all while figures on the board.If there are no white figures, print "<no white figures>"
//•	A list of all black figures on the board.If there are no black figures, print "<no black figures>"
//•	Note : if you have more than one figure, it must appear in the list twice!
//After you print these lists, change the color of all figurines to the other color(white to black and black to white), and print the chess board.
//Hints :
//    You do not need to check for the correctness of the board!It’s perfectly OK to have two white kings or no black king, but three black queens instead.