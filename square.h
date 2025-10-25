#pragma once
#include "Figure.h"

class Square : public Figure {
private:
    Point vertices[4];

public:
    Square() = default;
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Square(const Square& other);
    
    Point geometricCenter() const override;
    double area() const override;
    void printVertices(std::ostream& os) const override;
    void readFromStream(std::istream& is) override;
    
    std::unique_ptr<Figure> clone() const override;
    
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Square& square);
    friend std::istream& operator>>(std::istream& is, Square& square);
};