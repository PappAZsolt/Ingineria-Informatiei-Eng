#include <iostream>
#include "BillRepository.h"

int main() {
    /*MonetaryUnit m1(1234, 'c');  // 1234 cents
    MonetaryUnit m2(12, 'D');    // 12 dollars (1200 cents)
    MonetaryUnit m3 = m1 + m2;   // Addition
    MonetaryUnit m4 = m1 - m2;   // Subtraction

    std::cout << "m1: " << m1 << std::endl;r
    std::cout << "m2: " << m2 << std::endl;
    std::cout << "m3 (m1 + m2): " << m3 << std::endl;
    std::cout << "m4 (m1 - m2): " << m4 << std::endl;

    std::cout << "m1 in dollars: " << m1.get('D') << "D" << std::endl;

    int comp = m1.compare(m2);
    if (comp < 0) {
        std::cout << "m1 is smaller than m2" << std::endl;
    } else if (comp > 0) {
        std::cout << "m1 is larger than m2" << std::endl;
    } else {
        std::cout << "m1 and m2 are equal" << std::endl;
    }*/

    BillRepository repo;

    // Adding bills
    repo.addBill(1, MonetaryUnit(500, 'c'));  // $5.00
    repo.addBill(2, MonetaryUnit(200, 'c'));  // $2.00
    repo.addBill(3, MonetaryUnit(15, 'D'));   // $15.00
    repo.addBill(4, MonetaryUnit(1000, 'c')); // $10.00
    repo.addBill(5, MonetaryUnit(50, 'c'));   // $0.50

    std::cout << "Bills List:\n";
    repo.printBills('|');  // Print with '|' as delimiter

    std::cout << "\nTotal Monetary Value: " << repo.getTotalMonetaryUnit() << "\n";

    int count = repo.countBillsBetween(MonetaryUnit(200, 'c'), MonetaryUnit(1000, 'c'));
    std::cout << "Number of bills between $2.00 and $10.00: " << count << "\n";

    repo.clear();
    std::cout << "Repository cleared.\n";
    repo.printBills('|');  // Should print nothing
    return 0;
}