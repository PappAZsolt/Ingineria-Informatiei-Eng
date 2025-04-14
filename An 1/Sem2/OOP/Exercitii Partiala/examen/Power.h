#ifndef EXAMEN_POWER_H
#define EXAMEN_POWER_H

#include <iostream>

class Power{
private:
    int watts;

public:
    Power();
    Power(int amount, char unit);

    int getWatt() const;
    double get(char unit) const;

    Power operator+(const Power& other) const;
    Power operator-(const Power& other) const;

    int comp(const Power& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Power& power);
};


#endif //EXAMEN_POWER_H
