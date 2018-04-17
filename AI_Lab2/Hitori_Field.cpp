#include "stdafx.h"
#include "Hitori_Field.h"

// Generates random integer number from min to max using Mersenne Twister
//int GetRandomNumber(int min, int max)
//{
//	static std::random_device rd;
//	static std::mt19937 mersenne{ rd() };
//	static const double fraction = 1.0 / (static_cast<double>(mersenne.max()) + 1.0);
//	return min + static_cast<int>((max - min + 1) * (mersenne() * fraction));
//}


Hitori_Field::Hitori_Field(int number) : m_number(number)
{
	m_state = State::WHITE;
}

Hitori_Field::Hitori_Field(int number, State state = State::WHITE) : m_number(number), m_state(state) {}

string Hitori_Field::GetStringState()
{
	switch (m_state) 
	{
	case State::WHITE:
		return "White";
	case State::BLACK:
		return "Black";
	default:
		return "Unknown";
	}
}


Hitori_Field::~Hitori_Field()
{
}
