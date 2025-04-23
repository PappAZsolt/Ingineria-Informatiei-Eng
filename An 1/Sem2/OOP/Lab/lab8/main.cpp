#include "Garage.h"
#include "Car.h"
#include "Truck.h"

int main() {
    Garage garage;

    garage.loadFromFile("vehicles.txt");

    garage.addVehicle(std::make_shared<Car>("12351", "Sedan"));
    garage.addVehicle(std::make_shared<Truck>("421341", 7.5));

    garage.display();

    garage.saveToFile("vehiclesOut.txt");

    return 0;
}
