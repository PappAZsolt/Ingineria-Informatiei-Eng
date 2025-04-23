#pragma once
#include "Set.h"
#include <iostream>

class SetIterator
{
    //DO NOT CHANGE THIS PART
    friend class Set;
private:
    //DO NOT CHANGE THIS PART
    const Set& set;
    SetIterator(const Set& s);

    Node* current;

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
    void jumpBackward(int k);
};


