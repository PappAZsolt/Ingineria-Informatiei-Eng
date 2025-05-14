#ifndef TEST1B_A_VOLUME_H
#define TEST1B_A_VOLUME_H

#include <iostream>

class Volume{
private:
    int mililiters;

public:
    Volume();
    Volume(int amount, char unit);

    int getMililiters() const;
    double get(char unit) const;

    Volume operator+(const Volume& other) const;
    Volume operator-(const Volume& other) const;

    int compare(const Volume& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Volume& vol);
};

#endif //TEST1B_A_VOLUME_H
