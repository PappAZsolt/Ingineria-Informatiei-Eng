
#ifndef TEST1B_A_BOTTLEREPOSITORY_H
#define TEST1B_A_BOTTLEREPOSITORY_H

#include "volume.h"

struct Bottle
{
    int id;
    Volume amount;
};

class BottleRepository
{
private:
    Bottle* bottles;
    int size;
    int capacity;
    void resize();

public:
    BottleRepository(int initial_cap = 10);
    ~BottleRepository();


    bool addBottle(int id, const Volume& amount);
    void printBottle(char delimiter) const;
    Volume getTotalVolume() const;
    void clear();
    int countBottlesBetween(const Volume&min, const Volume&max) const;
};

#endif //TEST1B_A_BOTTLEREPOSITORY_H
