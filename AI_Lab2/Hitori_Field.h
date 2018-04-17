#pragma once

enum State
{
	BLACK,
	WHITE,
	MAX_STATE,
	NONE,
};

class Hitori_Field
{


	int m_number;
	State m_state;

public:
	Hitori_Field(int number);
	Hitori_Field(int number, State state);
	int GetNumber() { return m_number; }
	State GetState() { return m_state; }
	string GetStringState();
	~Hitori_Field();
};

