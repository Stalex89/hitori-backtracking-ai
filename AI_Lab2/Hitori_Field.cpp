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

bool Hitori_Field::GetDomainValueAt(int idx)
{
	return m_domain.at(idx);
}

void Hitori_Field::SetDomainValueAt(int idx, bool value)
{
	m_domain.at(idx) = value;
}

array<bool, 2> Hitori_Field::GetDomainArray() 
{ 
	return m_domain; 
}

void Hitori_Field::SetDomainArray(array<bool, 2> &domain) 
{ 
	m_domain[0] = domain[0]; 
	m_domain[1] = domain[1];
}


Hitori_Field::~Hitori_Field()
{
}
