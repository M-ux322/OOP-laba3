#pragma once
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include <vector>
#include <memory>

class Array {
private:
    std::vector<std::unique_ptr<Figure>> figures;
public:
    void addFigure(std::unique_ptr<Figure> figure);
    void removeFigure(int index);
    void printAllFigures() const;
    double totalArea() const;
    size_t size() const;
    const Figure* operator[](size_t index) const;
    
    Array() = default;
    Array(const Array& other);
    Array& operator=(const Array& other);
    Array(Array&& other) noexcept = default;
    Array& operator=(Array&& other) noexcept = default;

};
