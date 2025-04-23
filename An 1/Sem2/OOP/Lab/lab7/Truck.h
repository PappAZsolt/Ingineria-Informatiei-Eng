
#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double payloadCapacity;
public:
    Truck(const std::string& regNum, double capacity);

    double getPayloadCapacity() const;
    void setPayloadCapacity(double capacity);

    void display() const override;
};


