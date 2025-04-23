#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string registrationNumber;
public:
    Vehicle(const std::string& regNum);
    virtual void display() const = 0;
    virtual ~Vehicle() = default;
};

#endif // VEHICLE_H
