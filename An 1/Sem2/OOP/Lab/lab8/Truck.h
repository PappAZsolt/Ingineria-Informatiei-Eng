#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double payloadCapacity;
public:
    Truck(const std::string& reg, double capacity);
    void display() const override;
    double getPayloadCapacity() const;
};

#endif
