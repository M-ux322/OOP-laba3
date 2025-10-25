#include "Array.h"
#include <iostream>

int main() {
    Array figuresArray;
    Point t1(1, 1), t2(5, 1), t3(1, 3);
    Triangle triangle(t1, t2, t3);
    figuresArray.addFigure(std::make_unique<Triangle>(triangle));
    Point s1(6, 6), s2(8, 6), s3(8, 8), s4(6, 8);
    Square square(s1, s2, s3, s4);
    figuresArray.addFigure(std::make_unique<Square>(square));
    Point r1(0, 0), r2(5, 0), r3(5, 3), r4(0, 3);
    Rectangle rectangle(r1, r2, r3, r4);
    figuresArray.addFigure(std::make_unique<Rectangle>(rectangle));
    figuresArray.printAllFigures();
    std::cout << std::endl;
    double total = figuresArray.totalArea();
    std::cout << "S (all): " << total << std::endl;
    figuresArray.removeFigure(0);
    figuresArray.printAllFigures();
    
    return 0;
}
