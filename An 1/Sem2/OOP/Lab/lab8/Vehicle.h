#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string registrationNumber;
public:
    Vehicle(const std::string& reg) : registrationNumber(reg) {}
    virtual ~Vehicle() {}

    virtual void display() const = 0;
    std::string getRegistrationNumber() const {
        return registrationNumber;
    }
};

#endif
