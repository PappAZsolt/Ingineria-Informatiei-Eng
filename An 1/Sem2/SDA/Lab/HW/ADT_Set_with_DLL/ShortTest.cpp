#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"


void testAll() {
    Set s;
    assert(s.isEmpty() == true);
    assert(s.size() == 0);
    assert(s.add(5)==true);
    assert(s.add(1)==true);
    assert(s.add(10)==true);
    assert(s.add(7)==true);
    assert(s.add(1)==false);
    assert(s.add(10)==false);
    assert(s.add(-3)==true);
    assert(s.size() == 5);
    assert(s.search(10) == true);
    assert(s.search(16) == false);
    assert(s.remove(1) == true);
    assert(s.remove(6) == false);
    assert(s.size() == 4);


    SetIterator it = s.iterator();
    it.first();
    int sum = 0;
    while (it.valid()) {
        TElem e = it.getCurrent();
        sum += e;
        it.next();
    }
    assert(sum == 19);

    Set newS;
    newS.add(5);
    newS.add(1);
    newS.add(100);
    newS.add(12);
    newS.add(23);
    newS.add(123);
    newS.add(1234);

    SetIterator ite = newS.iterator();
    ite.first();
    ite.next();
    ite.next();
    ite.next();
    ite.next();

    ite.jumpBackward(4);
    assert(ite.getCurrent() == 5);
    //ite.jumpBackward(4);



}

