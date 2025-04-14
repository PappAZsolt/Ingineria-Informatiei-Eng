#include "sounds_vector.h"

Vector::Vector(size_t size)
{
    this->size = size;
    elements = new double[size];
}

Vector::~Vector()
{
    delete[] elements;
}

Vector::Vector(const Vector &other) {
    elements = new double[other.size];
    this->size = other.size;
    for (size_t i = 0; i < this->size;i++)
            elements[i] = other.elements[i];
}

Vector& Vector::operator=(const Vector& other)
{
    if(this == &other)
        return *this;
    delete[] elements;
    elements = new double[other.size];
    this->size = other.size;
    for (size_t i = 0; i < this->size;i++)
        elements[i] = other.elements[i];
    return *this;
}

double& Vector::operator[](size_t index) {
    return this->elements[index];
}

ostream& operator<<(ostream& os, const Vector& vec)
{
    for (size_t i = 0; i < vec.size; i++)
    {
        os << vec.elements[i] << "\n";
    }
    return os;
}