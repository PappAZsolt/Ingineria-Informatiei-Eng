#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include <memory>
#include <string>
#include "Vehicle.h"

class Garage {
private:
    std::vector<std::shared_ptr<Vehicle>> vehicles;
public:
    void addVehicle(std::shared_ptr<Vehicle> vehicle);
    void display() const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif
