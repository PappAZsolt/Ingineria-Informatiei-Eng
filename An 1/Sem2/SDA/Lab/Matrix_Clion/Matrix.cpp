#include "Matrix.h"
#include <exception>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols)  {
    rows = nrLines;
    cols = nrCols;
    size = 0;
    capacity = 10;
    elements = new Triple[capacity];
}

Matrix::~Matrix() {         // BEST == WORST == AVG == O(1)
    delete[] elements;
}

int Matrix::nrLines() const {   // BEST == WORST == AVG == O(1)
    return rows;
}

int Matrix::nrColumns() const {     // BEST == WORST == AVG == O(1)
    return cols;
}

TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw exception();
    }
    for (int k = 0; k < size; k++) {            // BEST == O(1)  WORST == AVG == O(k)
        if (elements[k].row == i && elements[k].col == j) {
            return elements[k].value;
        }
    }
    return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {    // BEST == Theta(1)  WORST == Theta(k)  Overall == O(k)
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw exception();
    }
    for (int k = 0; k < size; k++) {
        if (elements[k].row == i && elements[k].col == j) {
            TElem oldValue = elements[k].value;
            if (e == NULL_TELEM) {
                for (int m = k; m < size - 1; m++) {
                    elements[m] = elements[m + 1];
                }
                size--;
            } else {
                elements[k].value = e;
            }
            return oldValue;
        }
    }
    if (e != NULL_TELEM) {
        if (size == capacity) {
            resize();
        }
        int pos = 0;
        while (pos < size && (elements[pos].row < i || (elements[pos].row == i && elements[pos].col < j))) {
            pos++;
        }
        for (int m = size; m > pos; m--) {
            elements[m] = elements[m - 1];
        }
        elements[pos] = {i, j, e};
        size++;
    }
    return NULL_TELEM;
}

void Matrix::resize() {         // BEST == WORST == AVG == O(n)
    capacity *= 2;
    Triple* newElements = new Triple[capacity];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

int Matrix::numberOfNonZeroElems(int line) const { // BEST == WORST == AVG == Theta(k)
    if (line < 0 || line >= rows)
        throw exception();

    int cnt = 0;
    for (int k = 0; k < size; k++)
        if (elements[k].row == line)
            cnt++;

    return cnt;

}


