#pragma once
#include "Hitori_Field.h"
#include "stdafx.h" 

class Hitori_Board
{
	int fieldSize;
	deque<deque<Hitori_Field>> board;

public:
	Hitori_Board();
	~Hitori_Board();
};

