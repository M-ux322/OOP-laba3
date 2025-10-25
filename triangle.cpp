#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
}
Triangle::Triangle(const Triangle& other) {
    for (int i = 0; i < 3; ++i) {
        vertices[i] = other.vertices[i];
    }
}
Point Triangle::geometricCenter() const {
    double centerX = (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0;
    double centerY = (vertices[0].y + vertices[1].y + vertices[2].y) / 3.0;
    return Point(centerX, centerY);
}
double Triangle::area() const {
    double area = std::abs(
        (vertices[0].x * (vertices[1].y - vertices[2].y) +
         vertices[1].x * (vertices[2].y - vertices[0].y) +
         vertices[2].x * (vertices[0].y - vertices[1].y)) / 2.0
    );
    return area;
}
void Triangle::printVertices(std::ostream& os) const {
    os << "Triangle top: ";
    for (int i = 0; i < 3; ++i) {
        os << vertices[i];
        if (i < 2) os << ", ";
    }
}
void Triangle::readFromStream(std::istream& is) {
    for (int i = 0; i < 3; ++i) {
        is >> vertices[i];
    }
}
std::unique_ptr<Figure> Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}
Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        for (int i = 0; i < 3; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}
Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 3; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}
bool Triangle::operator==(const Triangle& other) const {
    for (int i = 0; i < 3; ++i) {
        if (!(vertices[i] == other.vertices[i])) {
            return false;
        }
    }
    return true;
}
std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    triangle.printVertices(os);
    return os;
}
std::istream& operator>>(std::istream& is, Triangle& triangle) {
    triangle.readFromStream(is);
    return is;

}
