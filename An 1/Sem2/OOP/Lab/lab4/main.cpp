#include <iostream>
#include "deque.h"

int main() {
    Deque deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_front(5);
    std::cout  << deq << std::endl;

    deq.pop_front();
    std::cout  << deq << std::endl;

    deq.pop_back();
    std::cout  << deq << std::endl;

    std::cout  << deq.top() << " " << deq.back() << std::endl;

    return 0;
}