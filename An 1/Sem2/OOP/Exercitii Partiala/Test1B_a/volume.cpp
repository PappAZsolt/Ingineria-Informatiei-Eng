#include "volume.h"

Volume::Volume() : mililiters(0) {}

Volume::Volume(int amount, char unit)
{
    if (unit == 'm')
        mililiters = amount;
    else if (unit == 'L')
        mililiters = amount * 1000;
    else
    {
        std::cerr << "Invalid unit.";
        mililiters = 0;
    }
}

int Volume::getMililiters() const {
    return mililiters;
}

double Volume::get(char unit) const {
    if (unit == 'm')
        return mililiters;
    else if (unit == 'L')
        return mililiters / 1000.0;
    else
    {
        std::cerr << "Invalid unit";
        return -1;
    }
}

Volume Volume::operator+(const Volume &other) const {
    return Volume(mililiters + other.mililiters, 'm');
}

Volume Volume::operator-(const Volume &other) const {
    return Volume(mililiters - other.mililiters, 'm');
}

int Volume::compare(const Volume &other) const {
    if (mililiters < other.mililiters) return -1;
    if (mililiters > other.mililiters) return 1;
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Volume& vol)
{
    int liter = vol.mililiters / 1000;
    int remaining_ml = vol.mililiters % 1000;
    if (liter > 0)
        os << liter << "L";
    if (remaining_ml > 0 || liter == 0)
        os << remaining_ml << "m";
    return os;
}












