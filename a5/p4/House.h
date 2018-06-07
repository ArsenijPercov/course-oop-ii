#include <bits/stdc++.h>
#include "GenericPlayer.h"

#ifndef _HOUSE_H
#define _HOUSE_H

class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");

    virtual ~House();

    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;

    //flips over first card
    void FlipFirstCard();
};

#endif