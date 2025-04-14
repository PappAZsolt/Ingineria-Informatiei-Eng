#include "MonetaryUnit.h"

MonetaryUnit::MonetaryUnit() : cents(0) {}

MonetaryUnit::MonetaryUnit(int amount, char unit) {
    if (unit == 'c')
        cents = amount;
    else if (unit == 'D')
        cents = amount * 100;
    else{
        std::cerr << "Invalid unit.";
        cents = 0;
    }
}

int MonetaryUnit::getCents() const {
    return cents;
}

double MonetaryUnit::get(char unit) const {
    if (unit == 'c') {
        return cents;
    } else if (unit == 'D') {
        return cents / 100.0;
    } else {
        std::cerr << "Error: Invalid unit. Use 'c' for cents or 'D' for dollars.\n";
        return -1; // Return -1 to indicate an error
    }
}

// Overloading + operator
MonetaryUnit MonetaryUnit::operator+(const MonetaryUnit& other) const {
    return MonetaryUnit(cents + other.cents, 'c');
}

// Overloading - operator
MonetaryUnit MonetaryUnit::operator-(const MonetaryUnit& other) const {
    return MonetaryUnit(cents - other.cents, 'c');
}

// Compare method
int MonetaryUnit::compare(const MonetaryUnit& other) const {
    if (cents < other.cents) return -1;
    if (cents > other.cents) return 1;
    return 0;
}

// Overloading << operator for output formatting
std::ostream& operator<<(std::ostream& os, const MonetaryUnit& mu) {
    int dollars = mu.cents / 100;
    int remaining_cents = mu.cents % 100;
    if (dollars > 0) {
        os << dollars << "D";
    }
    if (remaining_cents > 0 || dollars == 0) { // Ensure we print cents if it's the only unit
        os << remaining_cents << "c";
    }
    return os;
}