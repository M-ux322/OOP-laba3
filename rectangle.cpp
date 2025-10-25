#include "Rectangle.h"
#include <cmath>


Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices[0] = p1;
    vertices[1] = p2;
    vertices[2] = p3;
    vertices[3] = p4;
}

Rectangle::Rectangle(const Rectangle& other) {
    for (int i = 0; i < 4; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Point Rectangle::geometricCenter() const {
    double centerX = (vertices[0].x + vertices[1].x + vertices[2].x + vertices[3].x) / 4.0;
    double centerY = (vertices[0].y + vertices[1].y + vertices[2].y + vertices[3].y) / 4.0;
    return Point(centerX, centerY);
}

double Rectangle::area() const {
    double width = std::sqrt(
        std::pow(vertices[1].x - vertices[0].x, 2) + 
        std::pow(vertices[1].y - vertices[0].y, 2)
    );
    double height = std::sqrt(
        std::pow(vertices[2].x - vertices[1].x, 2) + 
        std::pow(vertices[2].y - vertices[1].y, 2)
    );
    return width * height;
}

void Rectangle::printVertices(std::ostream& os) const {
    os << "Rectangle top: ";
    for (int i = 0; i < 4; ++i) {
        os << vertices[i];
        if (i < 3) os << ", ";
    }
}

void Rectangle::readFromStream(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertices[i];
    }
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = std::move(other.vertices[i]);
        }
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    for (int i = 0; i < 4; ++i) {
        if (!(vertices[i] == other.vertices[i])) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) {
    rectangle.printVertices(os);
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    rectangle.readFromStream(is);
    return is;
}