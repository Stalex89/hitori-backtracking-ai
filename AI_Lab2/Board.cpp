#include "stdafx.h"
#include "Board.h"


Board::Board(int size)
{
	if (size < 1)
		throw invalid_argument("size should be bigger than 1\n");

	boardSize = size;
	
	for (int idx = 0; idx < boardSize; idx++)
		board.push_back(deque<char>(boardSize));

}

bool Board::BacktrackAlgorithm(int row, int column, Board *board)
{
	// If all fields are assigned, return true
	if (row == boardSize && column == boardSize)
		return true;

	for (int i = 0; i < 2; i++)
	{
		char symbol;
		if (i == 0)
			symbol = 'X';
		else
			symbol = 'Y';

		InsertElement(row, column, symbol);
		PrintBoard();
		if (CheckRowSequence(row) && CheckColumnSequence(column) /*&& CheckRowUniqueness() && CheckColumnUniqueness()*/)
		{
			column++;
			int columnNext = column;
			int rowNext = row;
			if(columnNext >= boardSize)
			{
				rowNext++;
				columnNext = 0;
			}
			if (BacktrackAlgorithm(rowNext, columnNext, board))
				return true;
		}

		RemoveElement(row, column);
	}

	return false;
}


void Board::InsertElement(int row, int column, char symbol)
{
	if (row < 0 || row >= boardSize)
		throw invalid_argument("row index is out of range\n");
	
	if (column < 0 || column >= boardSize)
		throw invalid_argument("column index is out of range\n");

	//if (symbol != Symbols::X && symbol != Symbols::Y)
	//	throw invalid_argument("wrong symbol, should be X or Y");

	board.at(row).at(column) = symbol;
}

void Board::RemoveElement(int row, int column)
{
	if (row < 0 || row >= boardSize)
		throw invalid_argument("row index is out of range\n");

	if (column < 0 || column >= boardSize)
		throw invalid_argument("column index is out of range\n");

	board.at(row).at(column) = 0;
}

void Board::PrintBoard()
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.at(i).size(); j++)
		{
			if (board.at(i).at(j) == NULL)
				cout << "0 ";
			else cout << board.at(i).at(j) << " ";
		}
			cout << '\n';
	}
	cout << '\n';
}

//bool Board::CheckSequence(deque<char> &line)
//{
//	int xCount = 0;
//	int yCount = 0;
//	for (int i = 0; i < line.size(); i++)
//	{
//		if (line.at(i) == 'X')
//		{
//			xCount++;
//			yCount = 0;
//		}
//
//		if (line.at(i) == 'Y')
//		{
//			yCount++;
//			xCount = 0;
//		}
//
//		// If there is more that two same symbols in row, return false 
//		if (xCount > 2 || yCount > 2)
//			return false;
//	}
//
//	return true;
//}

bool Board::CheckRowSequence(int idx)
{
	int xCount = 0;
	int yCount = 0;
	for (int i = 0; i < boardSize; i++)
	{

		if (board.at(idx).at(i) == 'X')
		{
			xCount++;
			yCount = 0;
		}

		if (board.at(idx).at(i) == 'Y')
		{
			yCount++;
			xCount = 0;
		}

		// If there is more that two same symbols in row, return false 
		if (xCount > 2 || yCount > 2)
			return false;
	}

	return true;
}

bool Board::CheckColumnSequence(int idx)
{
	int xCount = 0;
	int yCount = 0;
	for (int i = 0; i < boardSize; i++)
	{

		if (board.at(i).at(idx) == 'X')
		{
			xCount++;
			yCount = 0;
		}

		if (board.at(i).at(idx) == 'Y')
		{
			yCount++;
			xCount = 0;
		}

		// If there is more that two same symbols in row, return false 
		if (xCount > 2 || yCount > 2)
			return false;
	}

	return true;
}

bool Board::CheckRowUniqueness()
{
	// Check row uniqueness

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = i + 1; j < boardSize; j++)
		{
			if (board.at(i) == board.at(j) )
				return false;
		}
	}

	return true;
}

bool Board::CheckColumnUniqueness()
{
	// Check column uniqueness

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = i + 1; j < boardSize; j++)
		{ 
			// create two temporary deaues to compair columns
			deque<char> column1;
			deque<char> column2;
			for (int k = 0; k < boardSize; k++)
			{
				column1.push_back(board.at(k).at(i));
				column2.push_back(board.at(k).at(j));
			}
			if (column1 == column2)
				return false;
		}	
	}

	return true;
}


deque<char>& Board::GetRow(int idx)
{
	return board.at(idx);
}

deque<char> Board::GetColumn(int idx)
{
	deque<char> column;
	for (int i = 0; i < boardSize; i++)
		column.push_back(board.at(i).at(idx));
	return column;

}

Board::~Board()
{
}
