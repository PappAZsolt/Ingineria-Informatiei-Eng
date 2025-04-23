#include "Truck.h"
#include <iostream>

Truck::Truck(const std::string& reg, double capacity)
        : Vehicle(reg), payloadCapacity(capacity) {}

void Truck::display() const {
    std::cout << "Truck - Reg#: " << registrationNumber
              << ", Payload Capacity: " << payloadCapacity << " tons\n";
}

double Truck::getPayloadCapacity() const {
    return payloadCapacity;
}
