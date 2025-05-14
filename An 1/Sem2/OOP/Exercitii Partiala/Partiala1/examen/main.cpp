#include <iostream>
#include "InvoiceRepository.h"

int main() {

    //////////////// FIRST PART /////////////

    std::cout << "-----First Part-------\n";
    Power p1(1234,'W');
    Power p2(1,'K');
    Power p3(1234,'L');


    Power p4 = p1 + p2;
    Power p5 = p1 - p2;

    std::cout << p1.get('K') << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;

    int comp = p1.comp(p2);
    std::cout << comp << std::endl;
    std::cout << "--------------------------\n";
    ///////////////////////////////////////

    /////////////// SECOND PART /////////////////
    std::cout << "-------Second Part--------\n";

    InvoiceRepository repo;

    repo.addInvoice(1,Power(1234,'W'));
    repo.addInvoice(2,Power(1,'K'));
    repo.addInvoice(3,Power(1000,'W'));
    repo.addInvoice(4,Power(900,'W'));
    repo.addInvoice(5,Power(3000,'W'));
    repo.addInvoice(6,Power(10,'W'));
    repo.addInvoice(1,Power(12,'W'));

    repo.printInvoice(' ');
    std::cout << '\n';

    std::cout << repo.getTotalInvoices() << "\n";

    int cnt = repo.count_Invoices_between(Power(1000,'W'), Power(2000,'W'));
    std:: cout << cnt << std::endl;

    repo.clear();
    repo.printInvoice(' ');
    std::cout << '\n';

    std::cout << "---------------\n";

    //////////////////////////////////////////

}
