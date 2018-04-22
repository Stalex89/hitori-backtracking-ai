#include "stdafx.h"
#include "Hitori_Field.h"

Hitori_Field::Hitori_Field(int number) : m_number(number)
{
	m_state = State::GRAY;
}

Hitori_Field::Hitori_Field(int number, State state = State::GRAY) : m_number(number), m_state(state) {}

string Hitori_Field::GetStringState()
{
	switch (m_state) 
	{
	case State::WHITE:
		return "White";
	case State::BLACK:
		return "Black";
	case State::GRAY:
		return "Gray";
	default:
		return "Unknown";
	}
}


Hitori_Field::~Hitori_Field()
{
}
