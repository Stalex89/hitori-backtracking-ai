#pragma once

enum State
{
	WHITE,
	BLACK,
	MAX_STATE,
	GRAY,

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
	void SetState(State state) { m_state = state; }
	string GetStringState();
	~Hitori_Field();
};

