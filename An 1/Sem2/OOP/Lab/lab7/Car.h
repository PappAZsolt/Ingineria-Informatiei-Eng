
#include "Vehicle.h"

class Car : public Vehicle {
private:
    std::string bodyStyle;
public:
    Car(const std::string& regNum, const std::string& body);

    std::string getBodyStyle() const;
    void setBodyStyle(const std::string& style);

    void display() const override;
};


