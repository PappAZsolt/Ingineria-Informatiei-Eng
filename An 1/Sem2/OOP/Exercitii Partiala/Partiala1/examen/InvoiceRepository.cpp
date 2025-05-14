#include "InvoiceRepository.h"
#include <iostream>

InvoiceRepository::InvoiceRepository(int initial_cap)
{
    capacity = initial_cap;
    size = 0;
    invoices = new Invoice[capacity];
}

InvoiceRepository::~InvoiceRepository()
{
    delete[] invoices;
}

void InvoiceRepository::resize()
{
    int new_capacity = capacity * 2;
    Invoice *new_invoice = new Invoice[new_capacity];

    for (int i = 0; i < size; i++)
    {
        new_invoice[i] = invoices[i];
    }

    delete[] invoices;
    invoices = new_invoice;
    capacity = new_capacity;
}

bool InvoiceRepository::addInvoice(int id, const Power &p)
{
    for (int i = 0; i < size; i++)
        if (invoices[i].id == id)
        {
            std::cerr << "Invoice Id already in use.";
            return false;
        }

    if (size >= capacity)
        resize();

    invoices[size].id = id;
    invoices[size].p = p;
    size++;
    return true;
}

void InvoiceRepository::printInvoice(char delimiter) const
{
    for (int i = 0; i < size; i++)
        std::cout << invoices[i].id << delimiter << invoices[i].p << std::endl;
}

Power InvoiceRepository::getTotalInvoices() const
{
    Power total(0, 'W');
    for (int i = 0; i < size; i++)
        total = total + invoices[i].p;
    return total;
}

void InvoiceRepository::clear()
{
    size = 0;
}

int InvoiceRepository::count_Invoices_between(const Power &min, const Power &max) const
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (invoices[i].p.comp(min) >= 0 && invoices[i].p.comp(max) <= 0)
        {
            count++;
        }
    }
    return count;
}