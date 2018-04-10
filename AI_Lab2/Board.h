#pragma once
#include "stdafx.h"

class Board
{
	int boardSize;
	deque<deque<char>> board;

	
public:
	Board(int size);
	bool BacktrackAlgorithm(int row, int column, Board *board);
	void InsertElement(int row, int column, char symbol);
	void RemoveElement(int row, int column);
	void PrintBoard();
	//bool CheckSequence(deque<char> &line);
	bool CheckRowSequence(int idx);
	bool CheckColumnSequence(int idx);
	deque<char>& GetRow(int idx);
	deque<char> GetColumn(int idx);
	bool CheckRowUniqueness();
	bool CheckColumnUniqueness();
	~Board();
};

