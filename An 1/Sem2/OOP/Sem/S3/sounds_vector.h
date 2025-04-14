
#ifndef S3_SOUNDS_VECTOR_H
#define S3_SOUNDS_VECTOR_H

#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class Vector
{
private:
    size_t size;
    double* elements;

public:
    Vector(size_t size);
    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    double& operator[](size_t index);
    friend ostream& operator<<(ostream&os, const Vector& vec);
    inline size_t getLength() const{
        return size;
    }
};

#endif //S3_SOUNDS_VECTOR_H
