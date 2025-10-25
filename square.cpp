#include "Square.h"
#include <cmath>



Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
}

Square::Square(const Square& other) {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Point Square::geometricCenter() const {
    double centerX = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4.0;
    double centerY = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4.0;
    return Point(centerX, centerY);
}

double Square::area() const {
    double side = std::sqrt(
        std::pow(vertices[1].x - vertices[0].x, 2) + 
        std::pow(vertices[1].y - vertices[0].y, 2)
    );
    return side * side;
}

void Square::printVertices(std::ostream& os) const {
    os << "Square top: ";
    for (int i = 0; i < 4; ++i) {
        os << vertices[i];
        if (i < 3) os << ", ";
    }
}

void Square::readFromStream(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertices[i];
    }
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Square::operator==(const Square& other) const {
    for (int i = 0; i < 4; ++i) {
        if (!(vertices[i] == other.vertices[i])) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Square& square) {
    square.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Square& square) {
    square.readFromStream(is);
    return is;
}