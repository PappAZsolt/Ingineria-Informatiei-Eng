#include "BottleRepository.h"
#include <iostream>

BottleRepository::BottleRepository(int initial_cap) {
    capacity = initial_cap;
    size = 0;
    bottles = new Bottle[capacity];
}

BottleRepository::~BottleRepository()
{
    delete[] bottles;
}

void BottleRepository::resize() {
    int new_cap = capacity * 2;
    Bottle* new_bottles = new Bottle[new_cap];

    for (int i = 0; i < size; i++)
        new_bottles[i] = bottles[i];

    delete[] bottles;
    bottles = new_bottles;
    capacity = new_cap;
}

bool BottleRepository::addBottle(int id, const Volume &amount) {
    for (int i = 0; i < size; i++)
        if (bottles[i].id == id)
        {
            std::cerr << "Id already exists\n";
            return false;
        }

    if (size >= capacity)
        resize();

    bottles[size].id = id;
    bottles[size].amount = amount;
    size++;
    return true;
}

void BottleRepository::printBottle(char delimiter) const {
    for (int i = 0; i < size; i++)
        std::cout << bottles[i].id << delimiter << bottles[i].amount << '\n';
}

Volume BottleRepository::getTotalVolume() const {
    Volume total(0,'m');
    for (int i = 0; i < size; i++)
        total = total + bottles[i].amount;
    return total;
}

void BottleRepository::clear() {
    size = 0;
}

int BottleRepository::countBottlesBetween(const Volume &min, const Volume &max) const {
    int cnt = 0;
    for (int i = 0; i < size; i++)
        if (bottles[i].amount.compare(min) >= 0 && bottles[i].amount.compare(max) <= 0)
            cnt++;

    return cnt;
}
