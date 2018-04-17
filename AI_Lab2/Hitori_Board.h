#pragma once
#include "Hitori_Field.h"
#include "stdafx.h" 

class Hitori_Board
{
	int m_fieldSize;
	deque<deque<Hitori_Field>> m_board;

public:
	Hitori_Board(int fieldSize);
	void InitBoard();
	void PrintBoard();
	bool CheckRowUnique(int idx);
	bool CheckColumnUnique(int idx);
	bool CheckShadedSequence(int row, int column);
	bool CheckContinuousArea(int row, int column);
	void DFSUtil(int row, int column, vector<vector<bool>> &visited, int &visitedCount);
	bool BacktrackAlgorithm(int row, int column);
	vector<int> FindRowMultipleElements(int row);
	~Hitori_Board();
};

