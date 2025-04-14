//
// Created by Papp Zsolt on 03.04.2025.
//

#ifndef LAB4_DEQUE_H
#define LAB4_DEQUE_H

#include <iostream>


class Deque{

private:
    int* deque;
    int size;
    int cap;
    void resize();

public:
    Deque(int initial_cap = 10);
    ~Deque();
    void push_front(int value) ;
    void pop_front();
    void push_back(int value);
    void pop_back();
    int top() const;
    int back() const;
    friend std::ostream& operator<<(std::ostream& os, const Deque& deq);

};


#endif //LAB4_DEQUE_H
