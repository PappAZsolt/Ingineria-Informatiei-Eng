#include "Power.h"

Power::Power() : watts(0) {}

Power::Power(int amount, char unit) {
    if (unit == 'W')
        watts = amount;
    else if (unit == 'K')
        watts = amount * 1000;
    else {
        std::cerr << "Invalid unit.";
        watts = 0;
    }
}

int Power::getWatt() const {
    return watts;
}

double Power::get(char unit) const {
    if (unit == 'W') {
        return watts;
    } else if (unit == 'K') {
        return watts / 1000.0;
    } else {
        std::cerr << "Invalid unit.";
        return -1;
    }
}

Power Power::operator+(const Power &other) const {
    return {watts + other.watts,'W'};
}

Power Power::operator-(const Power &other) const {
    return {watts - other.watts, 'W'};
}

int Power::comp(const Power &other) const {
    if (watts > other.watts)
        return 1;
    if (watts < other.watts)
        return -1;
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Power& power)
{
    int kiloW = power.watts / 1000;
    int leftW = power.watts % 1000;
    if (kiloW > 0)
        os << kiloW << "K";
    if (kiloW == 0 || leftW > 0)
        os << leftW << "W";
    return os;
}
