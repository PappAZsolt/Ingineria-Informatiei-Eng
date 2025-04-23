#include "Car.h"
#include <iostream>

Car::Car(const std::string& regNum, const std::string& body)
        : Vehicle(regNum), bodyStyle(body) {}

std::string Car::getBodyStyle() const {
    return bodyStyle;
}

void Car::setBodyStyle(const std::string& style) {
    bodyStyle = style;
}

void Car::display() const {
    std::cout << "Car - Reg: " << registrationNumber
              << ", Body Style: " << bodyStyle << std::endl;
}
