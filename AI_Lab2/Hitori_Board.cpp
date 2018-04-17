#include "stdafx.h"
#include "Hitori_Board.h"


Hitori_Board::Hitori_Board(int fieldSize)
{
	m_fieldSize = fieldSize;
	for (int idx = 0; idx < fieldSize; idx++)
		m_board.push_back(deque<Hitori_Field>());
	InitBoard();
}


// Initialize some Hitori sample 
void Hitori_Board::InitBoard()
{
	m_board.at(0).push_back(Hitori_Field(2));
	m_board.at(0).push_back(Hitori_Field(1));
	m_board.at(0).push_back(Hitori_Field(3));
	m_board.at(0).push_back(Hitori_Field(3));
	m_board.at(0).push_back(Hitori_Field(3));

	m_board.at(1).push_back(Hitori_Field(1));
	m_board.at(1).push_back(Hitori_Field(4));
	m_board.at(1).push_back(Hitori_Field(4));
	m_board.at(1).push_back(Hitori_Field(2));
	m_board.at(1).push_back(Hitori_Field(3));

	m_board.at(2).push_back(Hitori_Field(4));
	m_board.at(2).push_back(Hitori_Field(3));
	m_board.at(2).push_back(Hitori_Field(3));
	m_board.at(2).push_back(Hitori_Field(5));
	m_board.at(2).push_back(Hitori_Field(5));

	m_board.at(3).push_back(Hitori_Field(5));
	m_board.at(3).push_back(Hitori_Field(4));
	m_board.at(3).push_back(Hitori_Field(3));
	m_board.at(3).push_back(Hitori_Field(1));
	m_board.at(3).push_back(Hitori_Field(2));

	m_board.at(4).push_back(Hitori_Field(3));
	m_board.at(4).push_back(Hitori_Field(3));
	m_board.at(4).push_back(Hitori_Field(1));
	m_board.at(4).push_back(Hitori_Field(3));
	m_board.at(4).push_back(Hitori_Field(5));
}

void Hitori_Board::PrintBoard()
{
	for (int i = 0; i < m_fieldSize; i++)
	{
		for (int j = 0; j < m_fieldSize; j++)
		{
			cout << "(" << m_board.at(i).at(j).GetNumber() << ", " << m_board.at(i).at(j).GetStringState() << ") ";
		}
		cout << '\n';
	}

}

bool Hitori_Board::CheckRowUnique(int idx)
{
	vector<int> nums;
	for (unsigned int i = 0; i < m_board.at(idx).size(); i++)
	{
		for (unsigned int j = 0; j < nums.size(); j++)
		{
			if (m_board.at(idx).at(i).GetNumber() == nums.at(j) && m_board.at(idx).at(i).GetState() == State::WHITE)
				return false;
		}
		if(m_board.at(idx).at(i).GetState() == State::WHITE)
			nums.push_back(m_board.at(idx).at(i).GetNumber());
	}
	return true;
}

bool Hitori_Board::CheckColumnUnique(int idx)
{
	vector<int> nums;
	for (int i = 0; i < m_fieldSize; i++)
	{
		for (unsigned int j = 0; j < nums.size(); j++)
		{
			if (m_board.at(i).at(idx).GetNumber() == nums.at(j) && m_board.at(i).at(idx).GetState() == State::WHITE)
				return false;
		}
		if (m_board.at(i).at(idx).GetState() == State::WHITE)
			nums.push_back(m_board.at(i).at(idx).GetNumber());
	}
	return true;
}

bool Hitori_Board::CheckShadedSequence(int row, int column)
{
	if (row != 0)
		if (m_board.at(row - 1).at(column).GetState() == State::BLACK)
			return false;

	if (column != 0)
		if (m_board.at(row).at(column - 1).GetState() == State::BLACK)
			return false;

	if (row != m_fieldSize-1)
		if (m_board.at(row + 1).at(column).GetState() == State::BLACK)
			return false;

	if (column != m_fieldSize-1)
		if (m_board.at(row).at(column + 1).GetState() == State::BLACK)
			return false;

	return true;
}

void Hitori_Board::DFSUtil(int row, int column, vector<vector<bool>> &visited, int &visitedCount)
{
	visited.at(row).at(column) = true;
	visitedCount++;

	for (int i = 0; i < m_fieldSize; i++)
	{
		for (int j = 0; j < m_fieldSize; j++)
		{
			cout << visited.at(i).at(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	if (row != 0)
		if (m_board.at(row - 1).at(column).GetState() != State::BLACK && !visited.at(row - 1).at(column))
			DFSUtil(row - 1, column, visited, visitedCount);

	if (column != 0)
		if (m_board.at(row).at(column - 1).GetState() != State::BLACK && !visited.at(row).at(column - 1))
			DFSUtil(row, column - 1, visited, visitedCount);

	if (row != m_fieldSize-1)
		if (m_board.at(row + 1).at(column).GetState() != State::BLACK && !visited.at(row + 1).at(column))
			DFSUtil(row + 1, column, visited, visitedCount);

	if (column != m_fieldSize-1)
		if (m_board.at(row).at(column + 1).GetState() != State::BLACK && !visited.at(row).at(column+1))
			DFSUtil(row, column + 1, visited, visitedCount);
}


bool Hitori_Board::CheckContinuousArea(int row, int column)
{
	if (m_board.at(row).at(column).GetState() == State::BLACK)
		return false;

	vector<vector<bool>> visited;
	int whiteCount = 0;
	int visitedCount = 0;

	for (int i = 0; i < m_fieldSize; i++)
	{
		visited.push_back(vector<bool>());
		for (int j = 0; j < m_fieldSize; j++)
		{
			visited.at(i).push_back(false);
			cout << visited.at(i).at(j) << " ";
			
			if (m_board.at(i).at(j).GetState() == State::WHITE)
				whiteCount++;
		}
		cout << "\n";
	}
	cout << "\n";

	DFSUtil(row, column, visited, visitedCount);

	if (visitedCount == whiteCount)
		return true;

	return false;

}

vector<int> Hitori_Board::FindRowMultipleElements(int row)
{
	vector<int> occurenceIdx;
	for (unsigned int i = 0; i < m_board.at(row).size() - 1; i++)
		for (unsigned int j = i + 1; i < m_board.at(row).size(); j++)
			if (m_board.at(row).at(i).GetNumber() == m_board.at(row).at(j).GetNumber())
				occurenceIdx.push_back(i);

}

bool Hitori_Board::BacktrackAlgorithm(int row, int column)
{
	
}





Hitori_Board::~Hitori_Board()
{
}
