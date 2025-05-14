#ifndef TEST_1B_B_BILLREPOSITORY_H
#define TEST_1B_B_BILLREPOSITORY_H

#include "MonetaryUnit.h"

struct Bill{
    int id;
    MonetaryUnit amount;
};

class BillRepository{
private:
    Bill* bills;
    int size;
    int capacity;
    void resize();

public:
    BillRepository(int initial_cap = 10);
    ~BillRepository();

    bool addBill(int id, const MonetaryUnit& amount);
    void printBills(char delimiter) const;
    MonetaryUnit getTotalMonetaryUnit() const;
    void clear();
    int countBillsBetween(const MonetaryUnit& min, const MonetaryUnit& max) const;
};

#endif //TEST_1B_B_BILLREPOSITORY_H
