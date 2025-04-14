#include "BillRepository.h"
#include <iostream>

BillRepository::BillRepository(int initial_cap) {
    capacity = initial_cap;
    size = 0;
    bills = new Bill[capacity];
}

BillRepository::~BillRepository()
{
    delete[] bills;
}

void BillRepository::resize() {
    int new_capacity = capacity * 2;
    Bill* new_bills = new Bill[new_capacity];


    for (int i = 0; i < size; i++) {
        new_bills[i] = bills[i];
    }


    delete[] bills;
    bills = new_bills;
    capacity = new_capacity;
}


bool BillRepository::addBill(int id, const MonetaryUnit& amount) {

    for (int i = 0; i < size; i++) {
        if (bills[i].id == id) {
            std::cerr << "Error: Bill with ID " << id << " already exists.\n";
            return false;
        }
    }


    if (size >= capacity) {
        resize();
    }


    bills[size].id = id;
    bills[size].amount = amount;
    size++;
    return true;
}


void BillRepository::printBills(char delimiter) const {
    for (int i = 0; i < size; i++) {
        std::cout << bills[i].id << delimiter << bills[i].amount << "\n";
    }
}


MonetaryUnit BillRepository::getTotalMonetaryUnit() const {
    MonetaryUnit total(0, 'c');
    for (int i = 0; i < size; i++) {
        total = total + bills[i].amount;
    }
    return total;
}


void BillRepository::clear() {
    size = 0;
}


int BillRepository::countBillsBetween(const MonetaryUnit& min, const MonetaryUnit& max) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (bills[i].amount.compare(min) >= 0 && bills[i].amount.compare(max) <= 0) {
            count++;
        }
    }
    return count;
}