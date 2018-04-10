#pragma once
class Hitori_Field
{
	enum State
	{
		NONE,
		BLACK,
		WHITE,
	};


	int rowIdx;
	int colIdx;
	State state;

public:
	Hitori_Field();
	~Hitori_Field();
};

