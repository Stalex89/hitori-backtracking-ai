#include "stdafx.h"
#include "Hitori_Board.h"


Hitori_Board::Hitori_Board(int fieldSize, int number)
{
	if (fieldSize < 1)
		throw invalid_argument("size should be bigger than 1\n");

	m_fieldSize = fieldSize;
	for (int idx = 0; idx < fieldSize; idx++)
		m_board.push_back(deque<Hitori_Field>());
	InitBoard(number);
}


// Initialize some Hitori sample 
void Hitori_Board::InitBoard(int number)
{
	if (m_fieldSize == 5)
	{
		if (number == 1)
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
		else if (number == 2)
		{
			m_board.at(0).push_back(Hitori_Field(2));
			m_board.at(0).push_back(Hitori_Field(2));
			m_board.at(0).push_back(Hitori_Field(5));
			m_board.at(0).push_back(Hitori_Field(5));
			m_board.at(0).push_back(Hitori_Field(4));

			m_board.at(1).push_back(Hitori_Field(4));
			m_board.at(1).push_back(Hitori_Field(3));
			m_board.at(1).push_back(Hitori_Field(3));
			m_board.at(1).push_back(Hitori_Field(1));
			m_board.at(1).push_back(Hitori_Field(5));

			m_board.at(2).push_back(Hitori_Field(4));
			m_board.at(2).push_back(Hitori_Field(4));
			m_board.at(2).push_back(Hitori_Field(1));
			m_board.at(2).push_back(Hitori_Field(2));
			m_board.at(2).push_back(Hitori_Field(1));

			m_board.at(3).push_back(Hitori_Field(2));
			m_board.at(3).push_back(Hitori_Field(5));
			m_board.at(3).push_back(Hitori_Field(5));
			m_board.at(3).push_back(Hitori_Field(3));
			m_board.at(3).push_back(Hitori_Field(1));

			m_board.at(4).push_back(Hitori_Field(1));
			m_board.at(4).push_back(Hitori_Field(5));
			m_board.at(4).push_back(Hitori_Field(4));
			m_board.at(4).push_back(Hitori_Field(5));
			m_board.at(4).push_back(Hitori_Field(1));
		}
		else cout << "Please enter correct puzzle number (1 or 2)!\n\n";
	}

	else if (m_fieldSize == 8)
	{
		m_board.at(0).push_back(Hitori_Field(7));
		m_board.at(0).push_back(Hitori_Field(5));
		m_board.at(0).push_back(Hitori_Field(8));
		m_board.at(0).push_back(Hitori_Field(1));
		m_board.at(0).push_back(Hitori_Field(5));
		m_board.at(0).push_back(Hitori_Field(4));
		m_board.at(0).push_back(Hitori_Field(6));
		m_board.at(0).push_back(Hitori_Field(8));

		m_board.at(1).push_back(Hitori_Field(4));
		m_board.at(1).push_back(Hitori_Field(4));
		m_board.at(1).push_back(Hitori_Field(3));
		m_board.at(1).push_back(Hitori_Field(2));
		m_board.at(1).push_back(Hitori_Field(8));
		m_board.at(1).push_back(Hitori_Field(5));
		m_board.at(1).push_back(Hitori_Field(3));
		m_board.at(1).push_back(Hitori_Field(1));

		m_board.at(2).push_back(Hitori_Field(7));
		m_board.at(2).push_back(Hitori_Field(2));
		m_board.at(2).push_back(Hitori_Field(4));
		m_board.at(2).push_back(Hitori_Field(1));
		m_board.at(2).push_back(Hitori_Field(7));
		m_board.at(2).push_back(Hitori_Field(7));
		m_board.at(2).push_back(Hitori_Field(3));
		m_board.at(2).push_back(Hitori_Field(5));

		m_board.at(3).push_back(Hitori_Field(8));
		m_board.at(3).push_back(Hitori_Field(2));
		m_board.at(3).push_back(Hitori_Field(6));
		m_board.at(3).push_back(Hitori_Field(7));
		m_board.at(3).push_back(Hitori_Field(1));
		m_board.at(3).push_back(Hitori_Field(2));
		m_board.at(3).push_back(Hitori_Field(6));
		m_board.at(3).push_back(Hitori_Field(4));

		m_board.at(4).push_back(Hitori_Field(6));
		m_board.at(4).push_back(Hitori_Field(4));
		m_board.at(4).push_back(Hitori_Field(5));
		m_board.at(4).push_back(Hitori_Field(3));
		m_board.at(4).push_back(Hitori_Field(6));
		m_board.at(4).push_back(Hitori_Field(1));
		m_board.at(4).push_back(Hitori_Field(2));
		m_board.at(4).push_back(Hitori_Field(7));

		m_board.at(5).push_back(Hitori_Field(4));
		m_board.at(5).push_back(Hitori_Field(3));
		m_board.at(5).push_back(Hitori_Field(1));
		m_board.at(5).push_back(Hitori_Field(7));
		m_board.at(5).push_back(Hitori_Field(6));
		m_board.at(5).push_back(Hitori_Field(8));
		m_board.at(5).push_back(Hitori_Field(6));
		m_board.at(5).push_back(Hitori_Field(2));

		m_board.at(6).push_back(Hitori_Field(2));
		m_board.at(6).push_back(Hitori_Field(3));
		m_board.at(6).push_back(Hitori_Field(7));
		m_board.at(6).push_back(Hitori_Field(4));
		m_board.at(6).push_back(Hitori_Field(2));
		m_board.at(6).push_back(Hitori_Field(3));
		m_board.at(6).push_back(Hitori_Field(8));
		m_board.at(6).push_back(Hitori_Field(8));

		m_board.at(7).push_back(Hitori_Field(3));
		m_board.at(7).push_back(Hitori_Field(1));
		m_board.at(7).push_back(Hitori_Field(2));
		m_board.at(7).push_back(Hitori_Field(6));
		m_board.at(7).push_back(Hitori_Field(5));
		m_board.at(7).push_back(Hitori_Field(3));
		m_board.at(7).push_back(Hitori_Field(4));
		m_board.at(7).push_back(Hitori_Field(8));
	}

	/*else if (m_fieldSize == 12)
	{
		m_board.at(0).push_back(Hitori_Field(9));
		m_board.at(0).push_back(Hitori_Field(9));
		m_board.at(0).push_back(Hitori_Field(10));
		m_board.at(0).push_back(Hitori_Field(12));
		m_board.at(0).push_back(Hitori_Field(5));
		m_board.at(0).push_back(Hitori_Field(12));
		m_board.at(0).push_back(Hitori_Field(6));
		m_board.at(0).push_back(Hitori_Field(7));
		m_board.at(0).push_back(Hitori_Field(7));
		m_board.at(0).push_back(Hitori_Field(11));
		m_board.at(0).push_back(Hitori_Field(9));
		m_board.at(0).push_back(Hitori_Field(1));

		m_board.at(1).push_back(Hitori_Field(7));
		m_board.at(1).push_back(Hitori_Field(7));
		m_board.at(1).push_back(Hitori_Field(11));
		m_board.at(1).push_back(Hitori_Field(2));
		m_board.at(1).push_back(Hitori_Field(4));
		m_board.at(1).push_back(Hitori_Field(3));
		m_board.at(1).push_back(Hitori_Field(3));
		m_board.at(1).push_back(Hitori_Field(9));
		m_board.at(1).push_back(Hitori_Field(1));
		m_board.at(1).push_back(Hitori_Field(8));
		m_board.at(1).push_back(Hitori_Field(6));
		m_board.at(1).push_back(Hitori_Field(10));

		m_board.at(2).push_back(Hitori_Field(8));
		m_board.at(2).push_back(Hitori_Field(4));
		m_board.at(2).push_back(Hitori_Field(2));
		m_board.at(2).push_back(Hitori_Field(8));
		m_board.at(2).push_back(Hitori_Field(9));
		m_board.at(2).push_back(Hitori_Field(2));
		m_board.at(2).push_back(Hitori_Field(5));
		m_board.at(2).push_back(Hitori_Field(4));
		m_board.at(2).push_back(Hitori_Field(6));
		m_board.at(2).push_back(Hitori_Field(9));
		m_board.at(2).push_back(Hitori_Field(1));
		m_board.at(2).push_back(Hitori_Field(8));

		m_board.at(3).push_back(Hitori_Field(12));
		m_board.at(3).push_back(Hitori_Field(2));
		m_board.at(3).push_back(Hitori_Field(10));
		m_board.at(3).push_back(Hitori_Field(1));
		m_board.at(3).push_back(Hitori_Field(10));
		m_board.at(3).push_back(Hitori_Field(9));
		m_board.at(3).push_back(Hitori_Field(4));
		m_board.at(3).push_back(Hitori_Field(11));
		m_board.at(3).push_back(Hitori_Field(7));
		m_board.at(3).push_back(Hitori_Field(6));
		m_board.at(3).push_back(Hitori_Field(5));
		m_board.at(3).push_back(Hitori_Field(12));

		m_board.at(4).push_back(Hitori_Field(4));
		m_board.at(4).push_back(Hitori_Field(12));
		m_board.at(4).push_back(Hitori_Field(8));
		m_board.at(4).push_back(Hitori_Field(5));
		m_board.at(4).push_back(Hitori_Field(12));
		m_board.at(4).push_back(Hitori_Field(6));
		m_board.at(4).push_back(Hitori_Field(5));
		m_board.at(4).push_back(Hitori_Field(10));
		m_board.at(4).push_back(Hitori_Field(7));
		m_board.at(4).push_back(Hitori_Field(1));
		m_board.at(4).push_back(Hitori_Field(2));
		m_board.at(4).push_back(Hitori_Field(3));

		m_board.at(5).push_back(Hitori_Field(6));
		m_board.at(5).push_back(Hitori_Field(12));
		m_board.at(5).push_back(Hitori_Field(1));
		m_board.at(5).push_back(Hitori_Field(1));
		m_board.at(5).push_back(Hitori_Field(8));
		m_board.at(5).push_back(Hitori_Field(12));
		m_board.at(5).push_back(Hitori_Field(9));
		m_board.at(5).push_back(Hitori_Field(8));
		m_board.at(5).push_back(Hitori_Field(3));
		m_board.at(5).push_back(Hitori_Field(5));
		m_board.at(5).push_back(Hitori_Field(1));
		m_board.at(5).push_back(Hitori_Field(11));

		m_board.at(6).push_back(Hitori_Field(12));
		m_board.at(6).push_back(Hitori_Field(5));
		m_board.at(6).push_back(Hitori_Field(5));
		m_board.at(6).push_back(Hitori_Field(8));
		m_board.at(6).push_back(Hitori_Field(7));
		m_board.at(6).push_back(Hitori_Field(9));
		m_board.at(6).push_back(Hitori_Field(11));
		m_board.at(6).push_back(Hitori_Field(12));
		m_board.at(6).push_back(Hitori_Field(6));
		m_board.at(6).push_back(Hitori_Field(9));
		m_board.at(6).push_back(Hitori_Field(10));
		m_board.at(6).push_back(Hitori_Field(8));

		m_board.at(7).push_back(Hitori_Field(10));
		m_board.at(7).push_back(Hitori_Field(6));
		m_board.at(7).push_back(Hitori_Field(9));
		m_board.at(7).push_back(Hitori_Field(11));
		m_board.at(7).push_back(Hitori_Field(1));
		m_board.at(7).push_back(Hitori_Field(5));
		m_board.at(7).push_back(Hitori_Field(6));
		m_board.at(7).push_back(Hitori_Field(3));
		m_board.at(7).push_back(Hitori_Field(4));
		m_board.at(7).push_back(Hitori_Field(7));
		m_board.at(7).push_back(Hitori_Field(8));
		m_board.at(7).push_back(Hitori_Field(2));

		m_board.at(8).push_back(Hitori_Field(8));
		m_board.at(8).push_back(Hitori_Field(11));
		m_board.at(8).push_back(Hitori_Field(6));
		m_board.at(8).push_back(Hitori_Field(5));
		m_board.at(8).push_back(Hitori_Field(2));
		m_board.at(8).push_back(Hitori_Field(3));
		m_board.at(8).push_back(Hitori_Field(12));
		m_board.at(8).push_back(Hitori_Field(2));
		m_board.at(8).push_back(Hitori_Field(9));
		m_board.at(8).push_back(Hitori_Field(12));
		m_board.at(8).push_back(Hitori_Field(7));
		m_board.at(8).push_back(Hitori_Field(2));

		m_board.at(9).push_back(Hitori_Field(3));
		m_board.at(9).push_back(Hitori_Field(11));
		m_board.at(9).push_back(Hitori_Field(4));
		m_board.at(9).push_back(Hitori_Field(12));
		m_board.at(9).push_back(Hitori_Field(12));
		m_board.at(9).push_back(Hitori_Field(2));
		m_board.at(9).push_back(Hitori_Field(8));
		m_board.at(9).push_back(Hitori_Field(5));
		m_board.at(9).push_back(Hitori_Field(1));
		m_board.at(9).push_back(Hitori_Field(10));
		m_board.at(9).push_back(Hitori_Field(4));
		m_board.at(9).push_back(Hitori_Field(6));

		m_board.at(10).push_back(Hitori_Field(2));
		m_board.at(10).push_back(Hitori_Field(3));
		m_board.at(10).push_back(Hitori_Field(4));
		m_board.at(10).push_back(Hitori_Field(6));
		m_board.at(10).push_back(Hitori_Field(11));
		m_board.at(10).push_back(Hitori_Field(5));
		m_board.at(10).push_back(Hitori_Field(1));
		m_board.at(10).push_back(Hitori_Field(3));
		m_board.at(10).push_back(Hitori_Field(10));
		m_board.at(10).push_back(Hitori_Field(12));
		m_board.at(10).push_back(Hitori_Field(5));
		m_board.at(10).push_back(Hitori_Field(9));

		m_board.at(11).push_back(Hitori_Field(2));
		m_board.at(11).push_back(Hitori_Field(8));
		m_board.at(11).push_back(Hitori_Field(7));
		m_board.at(11).push_back(Hitori_Field(4));
		m_board.at(11).push_back(Hitori_Field(12));
		m_board.at(11).push_back(Hitori_Field(10));
		m_board.at(11).push_back(Hitori_Field(3));
		m_board.at(11).push_back(Hitori_Field(6));
		m_board.at(11).push_back(Hitori_Field(5));
		m_board.at(11).push_back(Hitori_Field(11));
		m_board.at(11).push_back(Hitori_Field(9));
		m_board.at(11).push_back(Hitori_Field(3));
	}*/
	
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
	cout << '\n';
}

void Hitori_Board::PrintBoardFC()
{
	for (int i = 0; i < m_fieldSize; i++)
	{
		for (int j = 0; j < m_fieldSize; j++)
		{
			cout << "(" << m_board.at(i).at(j).GetNumber() << ", " << m_board.at(i).at(j).GetStringState() 
				<< ", <" << m_board.at(i).at(j).GetDomainValueAt(0) << ", " << m_board.at(i).at(j).GetDomainValueAt(1) << ">) ";
		}
		cout << '\n';
	}
	cout << '\n';
}

bool Hitori_Board::FindFieldWithState(int &row, int &column, State state)
{
	for (row = 0; row < m_fieldSize; row++)
		for (column = 0; column < m_fieldSize; column++)
			if (m_board.at(row).at(column).GetState() == state)
				return true;
	return false;
}

#pragma region ConstraintCheckers

// Checks if any other white field in a row has same number
bool Hitori_Board::UsedInRow(int row, int num)
{
	for (unsigned int i = 0; i < m_board.at(row).size(); i++)
		if (m_board.at(row).at(i).GetNumber() == num && m_board.at(row).at(i).GetState() == State::WHITE)
		{
			cout << "There is already white field with number " << num << " in (" << row << "," << i << ")\n\n";
			return true;
		}

	cout << "There are no white fields with number " << num << " in " << row << " row\n\n";
	return false;
}



// Checks if any other white field in a column has same number
bool Hitori_Board::UsedInCol(int column, int num)
{
	for (int i = 0; i < m_fieldSize; i++)
		if (m_board.at(i).at(column).GetNumber() == num && m_board.at(i).at(column).GetState() == State::WHITE)
		{
			cout << "There is already white field with number " << num << " in (" << i << "," << column << ")\n\n";
			return true;
		}

	cout << "There are no white fields with number " << num << " in " << column << " column\n\n";
	return false;
}


// Cheks if there is a shaded adjacent field  
bool Hitori_Board::HasShadedNeghbour(int row, int column)
{
	if (row != 0)
		if (m_board.at(row - 1).at(column).GetState() == State::BLACK)
		{
			cout << "element (" << row << "," << column << ") has shaded neighbour at top (" << row - 1 << "," << column <<")\n\n";
			return true;
		}

	if (column != 0)
		if (m_board.at(row).at(column - 1).GetState() == State::BLACK)
		{
			cout << "element (" << row << "," << column << ") has shaded neighbour at left (" << row << "," << column - 1 << ")\n\n";
			return true;
		}

	if (row != m_fieldSize-1)
		if (m_board.at(row + 1).at(column).GetState() == State::BLACK)
		{
			cout << "element (" << row << "," << column << ") has shaded neighbour at bottom (" << row + 1 << "," << column << ")\n\n";
			return true;
		}

	if (column != m_fieldSize-1)
		if (m_board.at(row).at(column + 1).GetState() == State::BLACK)
		{
			cout << "element (" << row << "," << column << ") has shaded neighbour at right (" << row << "," << column + 1 << ")\n\n";
			return true;
		}

	cout << "element (" << row << "," << column << ") has no shaded neighbours \n\n";
	return false;
}

// Depth first search utility for "islands" checking
void Hitori_Board::DFSUtil(int row, int column, vector<vector<bool>> &visited, int &visitedCount)
{
	visited.at(row).at(column) = true;
	
	// If we visited whit field, increment the visited counter
	if(m_board.at(row).at(column).GetState() == State::WHITE)
		visitedCount++;

	/*for (int i = 0; i < m_fieldSize; i++)
	{
		for (int j = 0; j < m_fieldSize; j++)
		{
			cout << visited.at(i).at(j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

	if (row != 0)
		if (m_board.at(row - 1).at(column).GetState() != State::BLACK && !visited.at(row - 1).at(column))
			DFSUtil(row - 1, column, visited, visitedCount);

	if (column != 0)
		if (m_board.at(row).at(column - 1).GetState() != State::BLACK && !visited.at(row).at(column - 1))
			DFSUtil(row, column - 1, visited, visitedCount);

	if (row != m_fieldSize - 1)
		if (m_board.at(row + 1).at(column).GetState() != State::BLACK && !visited.at(row + 1).at(column))
			DFSUtil(row + 1, column, visited, visitedCount);

	if (column != m_fieldSize - 1)
		if (m_board.at(row).at(column + 1).GetState() != State::BLACK && !visited.at(row).at(column + 1))
			DFSUtil(row, column + 1, visited, visitedCount);
}

// Checks if there is no "islands" on the board
bool Hitori_Board::IsContinuousArea(int row, int column)
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
			//cout << visited.at(i).at(j) << " ";

			if (m_board.at(i).at(j).GetState() == State::WHITE)
				whiteCount++;
		}
		//cout << "\n";
	}
	//cout << "\n";

	DFSUtil(row, column, visited, visitedCount);

	if (visitedCount == whiteCount)
	{
		cout << "Area is continuous\n\n";
		return true;
	}
	cout << "Area is not continuous\n\n";
	return false;

}

// Checks if all constraints are satisfied
bool Hitori_Board::IsConstraintSafe(int row, int column, int num, State state)
{
	// Check constraints for white field
	if (state == State::WHITE)
		return (!UsedInRow(row, num) && !UsedInCol(column, num));

	// Check constraints for black field
	else if (state == State::BLACK)
	{ 
		// find first white element on board
		int whiteRow, whiteColumn;
		if (FindFieldWithState(whiteRow, whiteColumn, State::WHITE))
			return (!HasShadedNeghbour(row, column) && IsContinuousArea(whiteRow, whiteColumn));
		else
			return (!HasShadedNeghbour(row, column));
	}
	else
		return false;
}


#pragma endregion

bool Hitori_Board::BackTracking()
{
	int row, column;

	// if There is no unassigned fields, we are done
	if (!FindFieldWithState(row, column, State::GRAY))
		return true;

	// consider states white = 0 and black = 1
	for (int i = 0; i < State::MAX_STATE; i++)
	{
		cout << "attempt to assign state = " << (State)(i) << " on field (" << row << "," << column << ")\n\n";
		// if constraints are satisfied
		if (IsConstraintSafe(row, column, m_board.at(row).at(column).GetNumber(), (State)(i)))
		{
			
			// make tentative assignment
			m_board.at(row).at(column).SetState((State)(i));

			cout << "assigned state = " << (State)(i) << " on field (" << row << "," << column << ")\n\n";

			PrintBoard();

			// return if success
			if (BackTracking())
				return true;

			// if failure, unmake and try again

			cout << "unassigned state = " << (State)(i) << " on field (" << row << "," << column << ")\n\n";
			m_board.at(row).at(column).SetState(State::GRAY);
		}
	}
	cout << "apply backtracking\n\n";
	return false; // this triggers backtracking
	
}

#pragma region ConstraintCheckersFC

// Checks if any other white field in a row has same number
bool Hitori_Board::UsedInRowFC(int row, int num)
{
	for (unsigned int i = 0; i < m_board.at(row).size(); i++)
		if (m_board.at(row).at(i).GetNumber() == num && m_board.at(row).at(i).GetState() == State::WHITE)
		{
			//cout << "There is already white field with number " << num << " in (" << row << "," << i << ")\n\n";
			return true;
		}

	//cout << "There are no white fields with number " << num << " in " << row << " row\n\n";
	return false;
}



// Checks if any other white field in a column has same number
bool Hitori_Board::UsedInColFC(int column, int num)
{
	for (int i = 0; i < m_fieldSize; i++)
		if (m_board.at(i).at(column).GetNumber() == num && m_board.at(i).at(column).GetState() == State::WHITE)
		{
			//cout << "There is already white field with number " << num << " in (" << i << "," << column << ")\n\n";
			return true;
		}

	//cout << "There are no white fields with number " << num << " in " << column << " column\n\n";
	return false;
}


// Cheks if there is a shaded adjacent field  
bool Hitori_Board::HasShadedNeghbourFC(int row, int column)
{
	if (row != 0)
		if (m_board.at(row - 1).at(column).GetState() == State::BLACK)
		{
			//cout << "element (" << row << "," << column << ") has shaded neighbour at top (" << row - 1 << "," << column << ")\n\n";
			return true;
		}

	if (column != 0)
		if (m_board.at(row).at(column - 1).GetState() == State::BLACK)
		{
			//cout << "element (" << row << "," << column << ") has shaded neighbour at left (" << row << "," << column - 1 << ")\n\n";
			return true;
		}

	if (row != m_fieldSize - 1)
		if (m_board.at(row + 1).at(column).GetState() == State::BLACK)
		{
			//cout << "element (" << row << "," << column << ") has shaded neighbour at bottom (" << row + 1 << "," << column << ")\n\n";
			return true;
		}

	if (column != m_fieldSize - 1)
		if (m_board.at(row).at(column + 1).GetState() == State::BLACK)
		{
			//cout << "element (" << row << "," << column << ") has shaded neighbour at right (" << row << "," << column + 1 << ")\n\n";
			return true;
		}

	//cout << "element (" << row << "," << column << ") has no shaded neighbours \n\n";
	return false;
}

// Depth first search utility for "islands" checking
void Hitori_Board::DFSUtilFC(int row, int column, vector<vector<bool>> &visited, int &visitedCount)
{
	visited.at(row).at(column) = true;

	// If we visited whit field, increment the visited counter
	if (m_board.at(row).at(column).GetState() == State::WHITE)
		visitedCount++;

	/*for (int i = 0; i < m_fieldSize; i++)
	{
	for (int j = 0; j < m_fieldSize; j++)
	{
	cout << visited.at(i).at(j) << " ";
	}
	cout << "\n";
	}
	cout << "\n";*/

	if (row != 0)
		if (m_board.at(row - 1).at(column).GetState() != State::BLACK && !visited.at(row - 1).at(column))
			DFSUtil(row - 1, column, visited, visitedCount);

	if (column != 0)
		if (m_board.at(row).at(column - 1).GetState() != State::BLACK && !visited.at(row).at(column - 1))
			DFSUtil(row, column - 1, visited, visitedCount);

	if (row != m_fieldSize - 1)
		if (m_board.at(row + 1).at(column).GetState() != State::BLACK && !visited.at(row + 1).at(column))
			DFSUtil(row + 1, column, visited, visitedCount);

	if (column != m_fieldSize - 1)
		if (m_board.at(row).at(column + 1).GetState() != State::BLACK && !visited.at(row).at(column + 1))
			DFSUtil(row, column + 1, visited, visitedCount);
}

// Checks if there is no "islands" on the board
bool Hitori_Board::IsContinuousAreaFC(int row, int column)
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
			//cout << visited.at(i).at(j) << " ";

			if (m_board.at(i).at(j).GetState() == State::WHITE)
				whiteCount++;
		}
		//cout << "\n";
	}
	//cout << "\n";

	DFSUtilFC(row, column, visited, visitedCount);

	if (visitedCount == whiteCount)
	{
		//cout << "Area is continuous\n\n";
		return true;
	}
	//cout << "Area is not continuous\n\n";
	return false;

}

// Checks if all constraints are satisfied
bool Hitori_Board::IsConstraintSafeFC(int row, int column, int num, State state)
{
	// Check constraints for white field
	if (state == State::WHITE)
	{
		return (!UsedInRowFC(row, num) && !UsedInColFC(column, num));
	}


	// Check constraints for black field
	else if (state == State::BLACK)
	{
		// find first white element on board
		int whiteRow, whiteColumn;
		if (FindFieldWithStateFC(whiteRow, whiteColumn, State::WHITE))
			return (!HasShadedNeghbourFC(row, column) && IsContinuousAreaFC(whiteRow, whiteColumn));
		else
			return (!HasShadedNeghbourFC(row, column));
	}
	else
		return false;
}


#pragma endregion


#pragma region ForwardChecking

bool Hitori_Board::ConstraintCheckFC(int row, int column)
{
	// For every field in board
	for (int i = 0; i < m_fieldSize; i++)
	{
		for (int j = 0; j < m_fieldSize; j++)
		{
			// Exclude the current recursion field
			if (!(i == row && j == column) && m_board.at(i).at(j).GetState() == State::GRAY)
			{
				// check constraints for 
				for (int k = 0; k < State::MAX_STATE; k++)
				{
					if (!IsConstraintSafeFC(i, j, m_board.at(i).at(j).GetNumber(), State(k)))
						m_board.at(i).at(j).SetDomainValueAt(k, 0);
				}

				// If field has no possible values, return false
				if (m_board.at(i).at(j).GetDomainValueAt(0) == 0 && m_board.at(i).at(j).GetDomainValueAt(1) == 0)
					return false;
			}
		}
	}
	return true;
}

bool Hitori_Board::FindFieldWithStateFC(int &row, int &column, State state)
{
	for (row = 0; row < m_fieldSize; row++)
		for (column = 0; column < m_fieldSize; column++)
			if ((m_board.at(row).at(column).GetDomainValueAt(0) == 1 && m_board.at(row).at(column).GetDomainValueAt(1) == 0 && m_board.at(row).at(column).GetState() == state) ||
				(m_board.at(row).at(column).GetDomainValueAt(0) == 0 && m_board.at(row).at(column).GetDomainValueAt(1) == 1 && m_board.at(row).at(column).GetState() == state))
				return true;
	return false;
}

bool Hitori_Board::ForwardChecking()
{
	int row, column;

	// if There is no unassigned fields, we are done
	if (!FindFieldWithStateFC(row, column, State::GRAY) && !FindFieldWithState(row, column, State::GRAY))
			return true;

	// consider states white = 0 and black = 1
	for (int i = 0; i < State::MAX_STATE; i++)
	{
		//if the state is vailable at domain
		if(m_board.at(row).at(column).GetDomainValueAt(i))
		{	
			
			// make tentative assignment
			m_board.at(row).at(column).SetState((State)(i));
			m_board.at(row).at(column).SetDomainValueAt(i, false);
			cout << "assigned state = " << (State)(i) << " on field (" << row << "," << column << ")\n\n";

			//make a backup copy of hitori domains to backtrack to
			deque<deque<array<bool,2>>> backDomain;
			for (int g = 0; g < m_fieldSize; g++)
			{
				backDomain.push_back(deque<array<bool,2>>());
				for (int w = 0; w < m_fieldSize; w++)
					backDomain.at(g).push_back(m_board.at(g).at(w).GetDomainArray());
			}

			PrintBoardFC();

			if (ConstraintCheckFC(row, column))
			{
				cout << "results after constraint checking\n\n";
				PrintBoardFC();
				if (ForwardChecking())
					// return if success
					return true;
			}
			// if failure, unmake and try again


			cout << "return previous domain state of the board\n\n";
			for (int z = 0; z < m_fieldSize; z++)
				for (int u = 0; u < m_fieldSize; u++)
					m_board.at(z).at(u).SetDomainArray(backDomain.at(z).at(u));

			cout << "unassigned state = " << (State)(i) << " on field (" << row << "," << column << ")\n\n";
			m_board.at(row).at(column).SetState(State::GRAY);
			m_board.at(row).at(column).SetDomainValueAt(i, true);


			cout << "results after returning previous stare\n\n";
			PrintBoardFC();
		}
	}
	cout << "apply backtracking\n\n";
	return false; // this triggers backtracking

}

#pragma endregion

#pragma region CheckPatterns

// If you have a corner with two similar numbers, you can set a white cell
void Hitori_Board::CheckDoubleCorner()
{

	if (m_board.at(0).at(0).GetNumber() == m_board.at(0).at(1).GetNumber() || 
		m_board.at(0).at(1).GetNumber() == m_board.at(1).at(1).GetNumber())
		m_board.at(1).at(0).SetState(State::WHITE);

	if (m_board.at(0).at(0).GetNumber() == m_board.at(1).at(0).GetNumber() ||
		m_board.at(1).at(0).GetNumber() == m_board.at(1).at(1).GetNumber())
		m_board.at(0).at(1).SetState(State::WHITE);

	if (m_board.at(0).at(m_fieldSize - 2).GetNumber() == m_board.at(0).at(m_fieldSize - 1).GetNumber() ||
		m_board.at(0).at(m_fieldSize - 2).GetNumber() == m_board.at(1).at(m_fieldSize - 2).GetNumber())
		m_board.at(1).at(m_fieldSize - 1).SetState(State::WHITE);
}




void Hitori_Board::CheckforPatterns()
{
	CheckDoubleCorner();
}

#pragma endregion


#pragma region Unused


//// Checks if all elements in a row has unique elements
//bool Hitori_Board::CheckRowUnique(int row)
//{
//	vector<int> nums;
//	for (unsigned int i = 0; i < m_board.at(row).size(); i++)
//	{
//		for (unsigned int j = 0; j < nums.size(); j++)
//		{
//			if (m_board.at(row).at(i).GetNumber() == nums.at(j) && m_board.at(row).at(i).GetState() == State::WHITE)
//			{
//				cout << "row " << row << "has no unique elements\n";
//				return false;
//			}
//		}
//		if(m_board.at(row).at(i).GetState() == State::WHITE)
//			nums.push_back(m_board.at(row).at(i).GetNumber());
//	}
//	cout << "row " << row << "has unique elements\n";
//	return true;
//}

//bool Hitori_Board::CheckColumnUnique(int idx)
//{
//	vector<int> nums;
//	for (int i = 0; i < m_fieldSize; i++)
//	{
//		for (unsigned int j = 0; j < nums.size(); j++)
//		{
//			if (m_board.at(i).at(idx).GetNumber() == nums.at(j) && m_board.at(i).at(idx).GetState() == State::WHITE)
//			{
//				cout << "column " << idx << "has no unique elements\n";
//				return false;
//			}
//		}
//		if (m_board.at(i).at(idx).GetState() == State::WHITE)
//			nums.push_back(m_board.at(i).at(idx).GetNumber());
//	}
//	cout << "column " << idx << "has unique elements\n";
//	return true;
//}

//vector<vector<int>> Hitori_Board::FindDuplicateIndices()
//{
//	vector<vector<bool>> occurenceIdx;
//	for (int i = 0; i < m_fieldSize; i++)
//		occurenceIdx.push_back(vector<bool>(m_fieldSize));
//
//	// first check for duplicates in rows
//	for(int k = 0; k < m_fieldSize; k++)
//		for (int i = 0; i < m_fieldSize - 1; i++)
//			for (int j = i + 1; j < m_fieldSize; j++)
//			{
//				if (m_board.at(k).at(i).GetNumber() == m_board.at(k).at(j).GetNumber())
//				{
//					occurenceIdx.at(k).at(i) = 1;
//					occurenceIdx.at(k).at(j) = 1;
//				}
//			}
//
//	// second check for duplicates in columns
//	for (int k = 0; k < m_fieldSize; k++)
//		for (int i = 0; i < m_fieldSize - 1; i++)
//			for (int j = i + 1; j < m_fieldSize; j++)
//			{
//				if (m_board.at(i).at(k).GetNumber() == m_board.at(j).at(k).GetNumber())
//				{
//					occurenceIdx.at(i).at(k) = 1;
//					occurenceIdx.at(j).at(k) = 1;
//				}
//			}
//
//
//	vector<vector<int>> indicies;
//	for (int i = 0; i < m_fieldSize; i++)
//		indicies.push_back(vector<int>());
//
//	cout << "duplicate elements are at indicies:\n";
//	for (int i = 0; i < m_fieldSize; i++)
//	{
//		for (int j = 0; j < m_fieldSize; j++)
//		{
//			if (occurenceIdx.at(i).at(j) == 1)
//			{
//				indicies.at(i).push_back(j);
//				cout << j << " ";
//			}
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//
//	return indicies;
//}



//bool Hitori_Board::BacktrackAlgorithm(int row, int column, vector<vector<int>> &indices)
//{
//	// If all fields are assigned, return true
//	if (row == m_fieldSize)
//		return true;
//
//	for(int i = column; i < m_fieldSize; i++)
//
//	m_board.at(row).at(indices.at(row).at(column)).SetState(State::BLACK);
//	PrintBoard();
//	if (/*CheckRowUnique(row) && CheckColumnUnique(column) &&*/ CheckShadedSequence(row, column) /*&& CheckContinuousArea(row, column)*/)
//	{
//		int columnNext = (column == indices.at(row).size() - 1) ? 0 : column + 1;
//		int rowNext = (column == indices.at(row).size() - 1) ? row + 1 : row;
//		if (BacktrackAlgorithm(rowNext, columnNext, indices))
//			return true;
//	}
//	m_board.at(row).at(column).SetState(State::WHITE);
//
//	return false;
//}

//bool Hitori_Board::BacktrackAlgorithm(int row, int column)
//{
//	// If all fields are assigned, return true
//	if (row == m_fieldSize)
//		return true;
//
//	for(int i = column; i < m_fieldSize; i++)
//
//	m_board.at(row).at(row).SetState(State::BLACK);
//	PrintBoard();
//	if (/*!CheckRowUnique(row) && !CheckColumnUnique(column) &&*/ CheckShadedSequence(row, column) && CheckContinuousArea(row, column))
//	{
//		int columnNext = (column == m_fieldSize - 1) ? 0 : column + 1;
//		int rowNext = (column == m_fieldSize - 1) ? row + 1 : row;
//		if (BacktrackAlgorithm(rowNext, columnNext))
//			return true;
//	}
//	m_board.at(row).at(column).SetState(State::WHITE);
//
//	return false;
//}


//vector<int> Hitori_Board::FindRowDuplicateIndices(int row)
//{
//	vector<bool> occurenceIdx(m_board.at(row).size());
//	for (unsigned int i = 0; i < m_board.at(row).size() - 1; i++)
//		for (unsigned int j = i + 1; j < m_board.at(row).size(); j++)
//		{
//			if (m_board.at(row).at(i).GetNumber() == m_board.at(row).at(j).GetNumber())
//			{
//				occurenceIdx.at(i) = 1;
//				occurenceIdx.at(j) = 1;
//			}
//		}
//
//	vector<int> indicies;
//
//	cout << "duplicate elements are at indexes: ";
//	for (unsigned int idx = 0; idx < occurenceIdx.size(); idx++)
//	{
//		if (occurenceIdx.at(idx) == 1)
//		{	
//			indicies.push_back(idx);
//			cout << idx << " ";
//		}
//	}
//	cout << '\n';
//
//	return indicies;
//}

#pragma endregion

Hitori_Board::~Hitori_Board()
{
}
