#include <iostream>
#include "point.h"
#include <cmath>
double distance(const Point& p1, const Point& p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y,2));
}

int main()
{
    Point p1(1.0,2.0);
    Point p2(4.0,6.0);
    double dist = distance(p1,p2);
    std::cout << dist << std::endl;
}