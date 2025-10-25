#pragma once
#include <iostream>
#include <cmath>

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0);
    bool operator==(const Point& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
};
