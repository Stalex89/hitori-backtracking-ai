#pragma once
#include "stdafx.h"


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
	array<bool, 2> m_domain{ 1,1 };

public:
	Hitori_Field(int number);
	Hitori_Field(int number, State state);
	int GetNumber() { return m_number; }
	State GetState() { return m_state; }
	void SetState(State state) { m_state = state; }
	string GetStringState();
	bool GetDomainValueAt(int idx);
	void SetDomainValueAt(int idx, bool value);
	array<bool,2> GetDomainArray();
	void SetDomainArray(array<bool, 2> &domain);

	~Hitori_Field();
};

