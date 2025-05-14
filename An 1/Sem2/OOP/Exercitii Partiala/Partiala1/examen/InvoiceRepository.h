#ifndef EXAMEN_INVOICEREPOSITORY_H
#define EXAMEN_INVOICEREPOSITORY_H

#include "Power.h"

struct Invoice{
    int id;
    Power p;
};

class InvoiceRepository{
private:
    Invoice* invoices;
    int size;
    int capacity;
    void resize();

public:
    InvoiceRepository(int initial_cap = 5);
    ~InvoiceRepository();
    bool addInvoice(int id, const Power& p);
    void printInvoice(char delimiter) const;
    Power getTotalInvoices() const;
    void clear();
    int count_Invoices_between(const Power& min, const Power& max) const;
};

#endif //EXAMEN_INVOICEREPOSITORY_H
