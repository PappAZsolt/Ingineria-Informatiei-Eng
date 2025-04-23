
#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <assert.h>

using namespace std;


int main() {


	testAll();
	testAllExtended();
	cout << "Test End" << endl;

    Matrix m(4,4);
    m.modify(1,1,5);
    m.modify(1,2,10);
    m.modify(1,3,0);
    m.modify(2,2,12);
    assert(m.numberOfNonZeroElems(1) == 2);

	system("pause");
}