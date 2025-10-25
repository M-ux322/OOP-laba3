#pragma once
#include "Figure.h"

class Triangle : public Figure {
private:
    Point vertices[3];

public:
    Triangle() = default;
    Triangle(const Point& p1, const Point& p2, const Point& p3);
    Triangle(const Triangle& other);

    
    Point geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    
    std::unique_ptr<Figure> clone() const override;
    
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    bool operator==(const Triangle& other) const;
    
    
    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
    friend std::istream& operator>>(std::istream& is, Triangle& triangle);
};