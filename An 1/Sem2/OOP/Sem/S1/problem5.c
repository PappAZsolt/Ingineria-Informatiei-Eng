// Write a function that approximates the sqrt of a real positive num
// Approach with divide et impera

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float radical(float x, float eps, float st, float dr)
{
  float m = st + (dr - st) / 2;
  if (fabs(m * m - x) < eps)
    return m;
  if (m * m - x > eps)
    return radical(x, eps, st, m);
  return radical(x, eps, m, dr);
}

float radicall(float x, float eps)
{
  return radical(x, eps, 0, x);
}

int main()
{
  float x = radicall(2, 0.01);
  printf("%f", x);
}