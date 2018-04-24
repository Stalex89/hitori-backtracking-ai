#pragma once
#include "Hitori_Field.h"
#include "stdafx.h" 

class Hitori_Board
{
	int m_fieldSize;
	deque<deque<Hitori_Field>> m_board;

public:
	Hitori_Board(int fieldSize, int number);
	void InitBoard(int number);
	void PrintBoard();

	//bool CheckRowUnique(int idx);
	//bool CheckColumnUnique(int idx);
	bool HasShadedNeghbour(int row, int column);
	bool IsContinuousArea(int row, int column);
	void DFSUtil(int row, int column, vector<vector<bool>> &visited, int &visitedCount);
	//bool BacktrackAlgorithm(int row, int column, vector<vector<int>> &indices);
	//bool BacktrackAlgorithm(int row, int column);
	//vector<vector<int>> FindDuplicateIndices();
	//vector<int> FindRowDuplicateIndices(int row);
	~Hitori_Board();

	bool UsedInRow(int row, int num);
	bool UsedInCol(int column, int num);
	bool IsConstraintSafe(int row, int column, int num, State state);
	bool BackTracking();
	bool FindFieldWithState(int &row, int &column, State state);


	// Forward checking functions
	bool ForwardChecking();
	void PrintBoardFC();
	bool ConstraintCheckFC(int row, int column);
	bool HasShadedNeghbourFC(int row, int column);
	bool IsContinuousAreaFC(int row, int column);
	void DFSUtilFC(int row, int column, vector<vector<bool>> &visited, int &visitedCount);
	bool UsedInRowFC(int row, int num);
	bool UsedInColFC(int column, int num);
	bool IsConstraintSafeFC(int row, int column, int num, State state);
	bool FindFieldWithStateFC(int &row, int &column, State state);
	
	void CheckforPatterns();
	void CheckDoubleCorner();

};

