#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

ListIterator::ListIterator(const IndexedList& list) : list(list){
   currentNode = list.head;
}

void ListIterator::first(){
    currentNode = list.head;
}

void ListIterator::next(){
    if (!valid())
        throw std::exception();
    currentNode = list.nodes[currentNode].next;
}

bool ListIterator::valid() const{
    if (currentNode != -1)
        return true;
    return false;
}

TElem ListIterator::getCurrent() const{
   if (!valid())
       throw std::exception();
   return list.nodes[currentNode].value;
}