#include "stdafx.h"
#include "Mosaic_Board.h"


Mosaic_Board::Mosaic_Board(int size)
{
	if (size < 1)
		throw invalid_argument("size should be bigger than 1\n");

	boardSize = size;
	
	for (int idx = 0; idx < boardSize; idx++)
		board.push_back(deque<char>());

}

bool Mosaic_Board::BacktrackAlgorithm(int row, int column, Mosaic_Board *board)
{
	// If all fields are assigned, return true
	if (row == boardSize)
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
		if (CheckRowSequence(row) && CheckColumnSequence(column) && CheckRowUniqueness() /*&& CheckColumnUniqueness()*/)
		{
			int columnNext = (column == boardSize-1)? 0 : column+1;
			int rowNext = (column == boardSize-1) ? row + 1 : row;
			if (BacktrackAlgorithm(rowNext, columnNext, board))
				return true;
		}

		RemoveElement(row, column);
	}

	return false;
}


void Mosaic_Board::InsertElement(int row, int column, char symbol)
{
	if (row < 0 || row >= boardSize)
		throw invalid_argument("row index is out of range\n");
	
	if (column < 0 || column >= boardSize)
		throw invalid_argument("column index is out of range\n");

	//if (symbol != Symbols::X && symbol != Symbols::Y)
	//	throw invalid_argument("wrong symbol, should be X or Y");

	//board.at(row).at(column) = symbol;
	board.at(row).push_back(symbol);
}

void Mosaic_Board::RemoveElement(int row, int column)
{
	if (row < 0 || row >= boardSize)
		throw invalid_argument("row index is out of range\n");

	if (column < 0 || column >= boardSize)
		throw invalid_argument("column index is out of range\n");

	//board.at(row).at(column) = 0;
	board.at(row).pop_back();
}

void Mosaic_Board::PrintBoard()
{
	for (unsigned int i = 0; i < board.size(); i++)
	{
		for (unsigned int j = 0; j < board.at(i).size(); j++)
		{
			if (board.at(i).at(j) == NULL)
				cout << "0 ";
			else cout << board.at(i).at(j) << " ";
		}
			cout << '\n';
	}
	cout << '\n';
}

bool Mosaic_Board::CheckRowSequence(int idx)
{
	int xCount = 0;
	int yCount = 0;
	for (unsigned int i = 0; i < board.at(idx).size(); i++)
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

bool Mosaic_Board::CheckColumnSequence(int idx)
{
	int xCount = 0;
	int yCount = 0;
	for (int i = 0; i < boardSize; i++)
	{
		if (board.at(i).empty())
			break;

		

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

bool Mosaic_Board::CheckRowUniqueness()
{
	// Check row uniqueness

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = i + 1; j < boardSize; j++)
		{
			if (board.at(i) == board.at(j) && !board.at(i).empty() && !board.at(j).empty())
				return false;
		}
	}

	return true;
}

bool Mosaic_Board::CheckColumnUniqueness()
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


deque<char>& Mosaic_Board::GetRow(int idx)
{
	return board.at(idx);
}

deque<char> Mosaic_Board::GetColumn(int idx)
{
	deque<char> column;
	for (int i = 0; i < boardSize; i++)
		column.push_back(board.at(i).at(idx));
	return column;

}

Mosaic_Board::~Mosaic_Board()
{
}
