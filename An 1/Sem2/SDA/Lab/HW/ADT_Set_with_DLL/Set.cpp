#include "Set.h"
#include "SetIterator.h"

Set::Set() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}


bool Set::add(TElem elem) {  // Worst == Avg == Theta(length)
    if (search(elem))       // Best == Theta(1) if element at head
        return false;
    Node* newNode = new Node(elem);
    if (head == nullptr)  // Check if set empty
        head = tail = newNode;
    else
    {
        tail -> next = newNode; // We add a new node to the end of list
        newNode -> prev = tail;
        tail = newNode;
    }
    length++;
    return true;
}



bool Set::remove(TElem elem) { // Same as add()
    Node* current = head;
    while (current != nullptr) {  // Check if not empty
        if (current->value == elem) {
            if (current->prev != nullptr) // If the node has a previous node
                current->prev->next = current->next;  // Updates the previous next to the current next
            else
                head = current->next;

            if (current->next != nullptr)  // If the next node is not empty
                current->next->prev = current->prev;  // We point it to the current previous node
            else
                tail = current->prev;

            delete current;
            length--;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool Set::search(TElem elem) const {  // Theta(length)
    Node* current = head;
    while(current != nullptr)
    {
        if (current -> value == elem)
            return true;
        current = current->next;
    }
    return false;
}


int Set::size() const {     // O(1)

    return length;
}


bool Set::isEmpty() const { // O(1)

    return length == 0;
}


Set::~Set() { // Theta(length)
    Node* current = head;
    while(current != nullptr)
    {
        Node* tobeDeleted = current;
        current = current->next;
        delete tobeDeleted;
    }
}


SetIterator Set::iterator() const {
    return SetIterator(*this);
}


