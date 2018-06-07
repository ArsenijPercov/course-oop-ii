#include <bits/stdc++.h>
#include "Card.h"

using namespace std;

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{} 

int Card::GetValue() const
{
	int value;

	// to be filled with content
	if(m_Rank == JACK || m_Rank == QUEEN || m_Rank == KING){
		value = 10;
	} else {
		value = m_Rank;
	}

	return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}