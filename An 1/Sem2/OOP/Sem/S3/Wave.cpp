#include "Wave.h"

void Wave::generate(size_t duration, double sampleRate) {
    samples = Vector(duration*sampleRate);
    for (size_t i = 0; i < samples.getLength();i++)
    {
        double t = 1 / sampleRate;
        samples[i] = waveEq(t);
    }
}

ostream& operator<<(ostream& os, const Wave& wav)
{
    os << wav.samples;
    return os;
}