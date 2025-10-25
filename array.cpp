#include "Array.h"
#include <iostream>



void Array::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void Array::removeFigure(int index) {
    if (index >= 0 && index < static_cast<int>(figures.size())) {
        figures.erase(figures.begin() + index);
    }
}

void Array::printAllFigures() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << *figures[i] << std::endl;
        std::cout << "Geom. center: " << figures[i]->geometricCenter() << std::endl;
        std::cout << "S: " << figures[i]->area() << std::endl << std::endl;
    }
}

double Array::totalArea() const {
    double total = 0;
    for (const auto& figure : figures) {
        total += figure->area();
    }
    return total;
}

size_t Array::size() const {
    return figures.size();
}

const Figure* Array::operator[](size_t index) const {
    if (index < figures.size()) {
        return figures[index].get();
    }
    return nullptr;
}

Array::Array(const Array& other) {
    for (const auto& figure : other.figures) {
        figures.push_back(figure->clone());
    }
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        figures.clear();
        for (const auto& figure : other.figures) {
            figures.push_back(figure->clone());
        }
    }
    return *this;
}