#include "deque.h"
#include <iostream>
#include <stdexcept>

Deque::Deque(int initial_cap) : size(0), cap(initial_cap) {
    deque = new int[cap];
}

Deque::~Deque() {
    delete[] deque;
}

void Deque::resize() {
    int new_cap = cap * 2;
    int* new_deque = new int[new_cap];
    for (int i = 0; i < size; i++) {
        new_deque[i] = deque[i];
    }
    delete[] deque;
    deque = new_deque;
    cap = new_cap;
}

void Deque::push_front(int value) {
    if (size == cap) resize();
    for (int i = size; i > 0; i--) {
        deque[i] = deque[i - 1];
    }
    deque[0] = value;
    size++;
}

void Deque::push_back(int value) {
    if (size == cap) resize();
    deque[size++] = value;
}

void Deque::pop_front() {
    if (size == 0) throw std::underflow_error("Deque is empty");
    for (int i = 0; i < size - 1; i++) {
        deque[i] = deque[i + 1];
    }
    size--;
}

void Deque::pop_back() {
    if (size == 0) throw std::underflow_error("Deque is empty");
    size--;
}

int Deque::top() const {
    if (size == 0) throw std::underflow_error("Deque is empty");
    return deque[0];
}

int Deque::back() const {
    if (size == 0) throw std::underflow_error("Deque is empty");
    return deque[size - 1];
}

std::ostream& operator<<(std::ostream& os, const Deque& deq) {
    for (int i = 0; i < deq.size; i++) {
        os << deq.deque[i] << " ";
    }
    return os;
}