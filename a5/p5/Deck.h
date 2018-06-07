#include <bits/stdc++.h>
#include "Hand.h"
#include "GenericPlayer.h"

#ifndef _DECK_H
#define _DECK_H

class Deck : public Hand
{
public:
    Deck();
    
    virtual ~Deck();

    //create a standard deck of 52 cards
    void Populate();

    //shuffle cards
    void Shuffle();

    //deal one card to a hand
    void Deal(Hand& aHand);

    //give additional cards to a generic player 
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

#endif // !_DECK_H