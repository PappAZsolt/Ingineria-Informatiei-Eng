#include "Garage.h"
#include <iostream>

void Garage::addVehicle(std::shared_ptr<Vehicle> vehicle) {
    vehicles.push_back(vehicle);
}

void Garage::display() const {
    std::cout << "Garage contains:" << std::endl;
    for (const auto& vehicle : vehicles) {
        vehicle->display(); // Polymorphism
    }
}
