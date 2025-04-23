#include "Truck.h"
#include <iostream>

Truck::Truck(const std::string& regNum, double capacity)
        : Vehicle(regNum), payloadCapacity(capacity) {}

double Truck::getPayloadCapacity() const {
    return payloadCapacity;
}

void Truck::setPayloadCapacity(double capacity) {
    payloadCapacity = capacity;
}

void Truck::display() const {
    std::cout << "Truck - Reg: " << registrationNumber
              << ", Payload Capacity: " << payloadCapacity << " tons" << std::endl;
}
