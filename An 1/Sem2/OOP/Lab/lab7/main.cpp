#include "Garage.h"
#include "Car.h"
#include "Truck.h"

#include <memory>

int main() {
    Garage garage;

    std::shared_ptr<Vehicle> car1 = std::make_shared<Car>("123894", "Sedan");
    std::shared_ptr<Vehicle> truck1 = std::make_shared<Truck>("21347", 10.5);

    garage.addVehicle(car1);
    garage.addVehicle(truck1);

    garage.display();

    return 0;
}
