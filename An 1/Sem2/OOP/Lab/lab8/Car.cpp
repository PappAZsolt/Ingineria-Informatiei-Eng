#include "Car.h"
#include <iostream>

Car::Car(const std::string& reg, const std::string& style)
        : Vehicle(reg), bodyStyle(style) {}

void Car::display() const {
    std::cout << "Car - Reg#: " << registrationNumber << ", Body Style: " << bodyStyle << '\n';
}

std::string Car::getBodyStyle() const {
    return bodyStyle;
}
