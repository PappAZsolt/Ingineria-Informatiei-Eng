#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"

IndexedList::IndexedList() {
	capacity = INITIAL_CAP;
    nodes = new Node[capacity];

    for (int i = 0; i < capacity - 1; i++)
        nodes[i].next = i + 1;
    nodes[capacity - 1].next = -1;
    head = -1;
    firstEmpty = 0;
    length = 0;
}

int IndexedList::size() const {
    return length;
}


bool IndexedList::isEmpty() const {
    return length == 0;
}

TElem IndexedList::getElement(int pos) const {
    if (pos < 0 || pos >= length)
        throw std::exception();

    int current = head;
    for (int i = 0; i < pos; i++)
        current = nodes[current].next;
    return nodes[current].value;
}

TElem IndexedList::setElement(int pos, TElem e) {
   if (pos < 0 || pos >= length)
       throw std::exception();

   int current = head;
   for(int i = 0; i < pos; i++)
       current = nodes[current].next;

   int oldTElem = nodes[current].value;
   nodes[current].value = e;
   return oldTElem;
}

void IndexedList::addToEnd(TElem e) {
    if (firstEmpty == -1) // If there is no space available
        resize();

    int newPos = firstEmpty;
    firstEmpty = nodes[firstEmpty].next; // Go to next free spot

    nodes[newPos].value = e;
    nodes[newPos].next = -1; // To indicate end of list

    if (head == -1)
        head = newPos;
    else{
        int current = head;
        while(nodes[current].next != -1)
            current = nodes[current].next;
        nodes[current].next = newPos;
    }
    length++;
}

void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0 || pos > length)
        throw std::exception();


    if (firstEmpty == -1)
        resize();

    int newPos = firstEmpty;
    firstEmpty = nodes[firstEmpty].next;

    nodes[newPos].value = e;

    if (pos == 0)
    {
        nodes[newPos].next = head;
        head = newPos;
    }
    else
    {
        int prev = head;
        for (int i = 0; i < pos - 1; i++)
            prev = nodes[prev].next;

        nodes[newPos].next = nodes[prev].next;
        nodes[prev].next = newPos;

    }
    length++;
}

TElem IndexedList::remove(int pos) {
    if (pos < 0 || pos >= length)
        throw std::exception();

    int removedPos;
    TElem removedValue;

    if (pos == 0)
    {
        removedPos = head;
        head = nodes[head].next;
    }
    else
    {
        int prev = head;
        for (int i = 0; i < pos - 1; i++)
            prev = nodes[prev].next;

        removedPos = nodes[prev].next;
        nodes[prev].next = nodes[removedPos].next;
    }

    removedValue = nodes[removedPos].value;
    nodes[removedPos].next = firstEmpty;
    firstEmpty = removedPos;

    length--;
    return removedValue;

}

int IndexedList::search(TElem e) const {
    int current = head;
    int pos = 0;
    while (current != -1) {
        if (nodes[current].value == e)
            return pos;
        current = nodes[current].next;
        pos++;
    }
    return -1;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	delete[] nodes;
}

void IndexedList::resize() {
    int newCapacity = capacity * 2;
    Node* newNodes = new Node[newCapacity];

    for (int i = 0; i < capacity; i++)
        newNodes[i] = nodes[i];

    for (int i = capacity; i < newCapacity - 1; i++)
        newNodes[i].next = i + 1;

    newNodes[newCapacity - 1].next = -1;

    delete[] nodes;
    nodes = newNodes;
    firstEmpty = capacity;
    capacity = newCapacity;
}
