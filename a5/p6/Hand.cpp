#include "Hand.h"
#include <bits/stdc++.h>
using namespace std;

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()  
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}
 
void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
	int total;
    int num_aces;

    // to be filled with content
    vector<Card*>::const_iterator it;
    total = 0;
    num_aces = 0;
    for(it = m_Cards.begin(); it != m_Cards.end(); it++){
        Card* curr = *it;
        if(curr->GetValue() == Card::ACE){
            num_aces++;
        } else {
            total += curr->GetValue();
        }
    }

    while(num_aces--){
        if(total + 11 <= 21){
            total += 11;
        } else {
            total += 1;
        }
    }

    return total;
}