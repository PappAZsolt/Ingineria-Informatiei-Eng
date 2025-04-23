#include "Garage.h"
#include "Car.h"
#include "Truck.h"
#include <fstream>
#include <iostream>

void Garage::addVehicle(std::shared_ptr<Vehicle> vehicle) {
    vehicles.push_back(vehicle);
}

void Garage::display() const {
    std::cout << "Garage contains:\n";
    for (const auto& v : vehicles)
        v->display();
}

void Garage::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Could not open for reading.\n";
        return;
    }

    std::string type;
    while (in >> type) {
        std::string reg;
        in >> reg;

        if (type == "Car") {
            std::string style;
            in >> style;
            vehicles.push_back(std::make_shared<Car>(reg, style));
        } else if (type == "Truck") {
            double capacity;
            in >> capacity;
            vehicles.push_back(std::make_shared<Truck>(reg, capacity));
        }
    }

    in.close();
}

void Garage::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Could not open for writing.\n";
        return;
    }

    for (const auto& v : vehicles) {
        if (auto car = std::dynamic_pointer_cast<Car>(v)) {
            out << "Car " << car->getRegistrationNumber() << " " << car->getBodyStyle() << "\n";
        } else if (auto truck = std::dynamic_pointer_cast<Truck>(v)) {
            out << "Truck " << truck->getRegistrationNumber() << " " << truck->getPayloadCapacity() << "\n";
        }
    }

    out.close();
}
