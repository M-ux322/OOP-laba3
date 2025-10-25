#pragma once
#include "Point.h"
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;
    virtual Point geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void printVertices(std::ostream& os) const = 0;
    virtual void readFromStream(std::istream& is) = 0;
    virtual std::unique_ptr<Figure> clone() const = 0;
    bool operator==(const Figure& other) const;
    operator double() const;
};
