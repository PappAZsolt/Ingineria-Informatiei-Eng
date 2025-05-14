#include <iostream>
#include "BottleRepository.h"

int main()
{
    /*Volume v1(1234, 'm');
    Volume v2(1,'L');

    Volume v3 = v1 + v2;
    Volume v4 = v1 - v2;

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v4 << std::endl;

    std::cout << v1.get('L') << std::endl;

    int comp = v1.compare(v2);
    std::cout << comp << std::endl;*/

    BottleRepository repo;
    repo.addBottle(1,Volume(1234,'m'));
    repo.addBottle(2,Volume(1,'L'));

    repo.printBottle(' ');
    std::cout << '\n';

}