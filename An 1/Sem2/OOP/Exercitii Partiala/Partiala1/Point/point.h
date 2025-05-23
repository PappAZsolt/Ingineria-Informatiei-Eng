#include <iostream>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:
    Point(double x_val, double y_val) : x(x_val), y(y_val){}
    friend double distance(const Point& p1, const Point& p2);
};
