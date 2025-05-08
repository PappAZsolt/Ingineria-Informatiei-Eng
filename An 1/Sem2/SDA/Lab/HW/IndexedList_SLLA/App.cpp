#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "IndexedList.h"
#include "ListIterator.h"
#include <cstdlib>


using namespace std;

int main(){
    //testAll();
    //testAllExtended();

    IndexedList list = IndexedList();
    for (int i = 1; i < 17; i++)
    {
        list.addToEnd(rand() % 100);
    }

    ListIterator it = list.iterator();
    while(it.valid())
    {
        cout << it.getCurrent() << " ";
        it.next();
    }
    cout << endl;
    list.removeFromKtoK(4);

    it.first();
    while(it.valid())
    {
        cout << it.getCurrent() << " ";
        it.next();
    }

    cout<<"Finished LI Tests!"<<endl;
    return 0;
}