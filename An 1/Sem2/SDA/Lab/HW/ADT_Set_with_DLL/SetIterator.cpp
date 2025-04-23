#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set& m) : set(m)
{
   current = set.head;
}


void SetIterator::first() {
    current = set.head;
}


void SetIterator::next() {
    if (!valid())
        throw std::exception();
    current = current->next;
}


TElem SetIterator::getCurrent()
{
    if (!valid())
        throw std::exception();
    return current->value;
}

bool SetIterator::valid() const {

    return current != nullptr;
}

// Every function above has the same complexity = Theta(1)

void SetIterator::jumpBackward(const int k) { // Best = Theta(1) if the error triggers
    if (k <= 0 || set.length < k)               // Avg = Worst = Theta(k)
        throw std::exception();                 // Overall O(k)
    Node* temp = current;
    int cnt = 0;
    while (temp != nullptr && cnt < k)
    {
        temp = temp -> prev;
        cnt++;
    }
    if (cnt == k)
    {
        while (cnt != 0)
        {
            current = current ->prev;
            cnt--;
        }
    }
    else
        throw std::exception();

}



