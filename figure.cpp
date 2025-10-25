#include "Figure.h"

bool Figure::operator==(const Figure& other) const {
    return this->area() == other.area();
}
Figure::operator double() const {
    return area();
}
