#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    std::string bodyStyle;
public:
    Car(const std::string& reg, const std::string& style);
    void display() const override;
    std::string getBodyStyle() const;
};

#endif
