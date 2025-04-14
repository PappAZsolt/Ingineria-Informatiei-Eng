
#ifndef S3_WAVE_H
#define S3_WAVE_H

#pragma once
#include "sounds_vector.h"
#include <iostream>
#include <cmath>
#include <numbers>

class Wave{
protected:
    Vector samples;
    double freq, ampl;

public:
    void generate(size_t duration, double sample);
    virtual double waveEq(double t) = 0;
    friend ostream& operator<<(ostream& is, const Wave& wav)
};

class Sin : public Wave{
public:
    double waveEq(double t) override {
        return ampl * sin(2*t*freq*std::numbers::pi);
    }
};

#endif //S3_WAVE_H
