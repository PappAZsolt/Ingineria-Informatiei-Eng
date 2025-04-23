
#include <vector>
#include <memory>
#include "Vehicle.h"

class Garage {
private:
    std::vector<std::shared_ptr<Vehicle>> vehicles;
public:
    void addVehicle(std::shared_ptr<Vehicle> vehicle);
    void display() const;
};


