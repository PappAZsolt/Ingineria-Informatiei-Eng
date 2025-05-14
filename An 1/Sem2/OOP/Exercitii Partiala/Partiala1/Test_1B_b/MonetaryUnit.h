#include <iostream>

class MonetaryUnit{
private:
    int cents;

public:
    MonetaryUnit();
    MonetaryUnit(int amount, char unit);

    int getCents() const;
    double get(char unit) const;

    MonetaryUnit operator+(const MonetaryUnit& other) const;
    MonetaryUnit operator-(const MonetaryUnit& other) const;

    int compare(const MonetaryUnit& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MonetaryUnit& mu);
};