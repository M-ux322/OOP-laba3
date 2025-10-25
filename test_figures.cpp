#include <gtest/gtest.h>
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

TEST(TriangleTest, ConstructorAndArea) {
    Point p1(1, 12), p2(4, 8), p3(1, 3);
    Triangle triangle(p1, p2, p3);
    EXPECT_DOUBLE_EQ(triangle.area(), 13.5); 
}
TEST(TriangleTest, GeometricCenter) {
    Point p1(2, 9), p2(6, 8), p3(7, 4);
    Triangle triangle(p1, p2, p3);
    Point center = triangle.geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 5.0);
    EXPECT_DOUBLE_EQ(center.y, 7.0); 
}
TEST(TriangleTest, StreamOperators) {
    Triangle triangle;
    std::stringstream ss("1 7 9 3 4 2");
    ss >> triangle;
    std::stringstream output;
    triangle.printVertices(output); 
    EXPECT_FALSE(output.str().empty()); 
}
TEST(TriangleTest, DoubleConversionOperator) {
    Point p1(3, 8), p2(4, 5), p3(2, 3);
    Triangle triangle(p1, p2, p3);
    
    double area = static_cast<double>(triangle);
    EXPECT_DOUBLE_EQ(area, 4.0);
}
TEST(TriangleTest, EqualityOperator) {
    Point p1(12, 0), p2(4, 10), p3(11, 13);
    Triangle triangle1(p1, p2, p3);
    Triangle triangle2(p1, p2, p3);
    EXPECT_TRUE(triangle1 == triangle2);
}
TEST(TriangleTest, CopyAssignment) {
    Point p1(10, 8), p2(4, 24), p3(6, 0);
    Triangle triangle1(p1, p2, p3);
    Triangle triangle2;
    triangle2 = triangle1;
    EXPECT_TRUE(triangle1 == triangle2);
}
TEST(TriangleTest, MoveAssignment) {
    Point p1(3, 7), p2(4, 2), p3(1, 3);
    Triangle triangle1(p1, p2, p3);
    Triangle triangle2;
    triangle2 = std::move(triangle1);
    EXPECT_DOUBLE_EQ(triangle2.area(), 7.0); 
}
TEST(SquareTest, ConstructorAndArea) {
    Point p1(0, 0), p2(3, 0), p3(3, 3), p4(0, 3);
    Square square(p1, p2, p3, p4);
    EXPECT_DOUBLE_EQ(square.area(), 9.0);
}
TEST(SquareTest, GeometricCenter) {
    Point p1(0, 0), p2(8, 0), p3(8, 8), p4(0, 8);
    Square square(p1, p2, p3, p4);
    Point center = square.geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 4.0); 
    EXPECT_DOUBLE_EQ(center.y, 4.0); 
}
TEST(SquareTest, StreamOperators) {
    Square square;
    std::stringstream ss("0 0 7 0 7 7 0 7");
    ss >> square;
    std::stringstream output;
    square.printVertices(output); 
    EXPECT_FALSE(output.str().empty());
}
TEST(SquareTest, DoubleConversionOperator) {
    Point p1(0, 0), p2(2, 0), p3(2, 2), p4(0, 2);
    Square square(p1, p2, p3, p4);
    double area = static_cast<double>(square);
    EXPECT_DOUBLE_EQ(area, 4.0);
}
TEST(SquareTest, EqualityOperator) {
    Point p1(0, 0), p2(6, 0), p3(6, 6), p4(0, 6);
    Square square1(p1, p2, p3, p4);
    Square square2(p1, p2, p3, p4);
    EXPECT_TRUE(square1 == square2);
}
TEST(RectangleTest, ConstructorAndArea) {
    Point p1(1, 1), p2(4, 1), p3(4, 7), p4(1, 7);
    Rectangle rectangle(p1, p2, p3, p4);
    EXPECT_DOUBLE_EQ(rectangle.area(), 18.0);
}
TEST(RectangleTest, GeometricCenter) {
    Point p1(1, 1), p2(6, 1), p3(6, 4), p4(1, 4);
    Rectangle rectangle(p1, p2, p3, p4);
    Point center = rectangle.geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 3.5);
    EXPECT_DOUBLE_EQ(center.y, 2.5);
}
TEST(RectangleTest, StreamOperators) {
    Rectangle rectangle;
    std::stringstream ss("0 0 4 0 4 3 0 3");
    ss >> rectangle;
    std::stringstream output;
    rectangle.printVertices(output); 
    EXPECT_FALSE(output.str().empty());
}
TEST(RectangleTest, DoubleConversionOperator) {
    Point p1(3, 3), p2(4, 3), p3(4, 7), p4(3, 7);
    Rectangle rectangle(p1, p2, p3, p4);
    double area = static_cast<double>(rectangle);
    EXPECT_DOUBLE_EQ(area, 4.0);
}
TEST(RectangleTest, EqualityOperator) {
    Point p1(9, 9), p2(14, 9), p3(14, 13), p4(9, 13);
    Rectangle rectangle1(p1, p2, p3, p4);
    Rectangle rectangle2(p1, p2, p3, p4);
    EXPECT_TRUE(rectangle1 == rectangle2);
}
TEST(FigurePolymorphismTest, TriangleThroughBasePointer) {
    Point p1(10, 10), p2(16, 10), p3(10, 16);
    auto triangle = std::make_unique<Triangle>(p1, p2, p3);
    Figure* figure = triangle.get();
    Point center = figure->geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 12.0); 
    EXPECT_DOUBLE_EQ(center.y, 12.0); 
    double area = static_cast<double>(*figure);
    EXPECT_DOUBLE_EQ(area, 18.0); 
    std::stringstream output;
    figure->printVertices(output);
    EXPECT_FALSE(output.str().empty());
}
TEST(FigurePolymorphismTest, SquareThroughBasePointer) {
    Point p1(20, 20), p2(22, 20), p3(22, 22), p4(20, 22);
    auto square = std::make_unique<Square>(p1, p2, p3, p4);
    Figure* figure = square.get();
    Point center = figure->geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 21.0);
    EXPECT_DOUBLE_EQ(center.y, 21.0);
    double area = static_cast<double>(*figure);
    EXPECT_DOUBLE_EQ(area, 4.0);
}

TEST(FigurePolymorphismTest, RectangleThroughBasePointer) {
    Point p1(15, 15), p2(19, 15), p3(19, 18), p4(15, 17);
    auto rectangle = std::make_unique<Rectangle>(p1, p2, p3, p4);
    Figure* figure = rectangle.get();
    Point center = figure->geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 17.0);
    EXPECT_DOUBLE_EQ(center.y, 16.25);
    double area = static_cast<double>(*figure);
    EXPECT_DOUBLE_EQ(area, 12.0);
}

TEST(FigureComparisonTest, AreaBasedComparison) {
    Point p1(11, 11), p2(14, 11), p3(11, 13);
    auto triangle = std::make_unique<Triangle>(p1, p2, p3);
    Point p4(24, 24), p5(32, 24), p6(24, 32);
    auto triangle2 = std::make_unique<Triangle>(p4, p5, p6);
    Figure* fig1 = triangle.get();
    Figure* fig2 = triangle2.get();
    EXPECT_FALSE(*fig1 == *fig2); 
}

TEST(FigureCloneTest, TriangleClone) {
    Point p1(7, 7), p2(4, 7), p3(7, 1);
    Triangle triangle(p1, p2, p3);
    auto clone = triangle.clone();
    EXPECT_DOUBLE_EQ(clone->area(), 9.0);
    Point center = clone->geometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 6.0); 
    EXPECT_DOUBLE_EQ(center.y, 5.0); 
}

TEST(FigureCloneTest, SquareClone) {
    Point p1(4, 4), p2(9, 4), p3(9, 7), p4(9, 7);
    Square square(p1, p2, p3, p4);
    auto clone = square.clone();
    EXPECT_DOUBLE_EQ(clone->area(), 25.0);
}

TEST(FigureCloneTest, RectangleClone) {
    Point p1(4, 4), p2(9, 4), p3(9, 7), p4(9, 7);
    Rectangle rectangle(p1, p2, p3, p4);
    auto clone = rectangle.clone();
    EXPECT_DOUBLE_EQ(clone->area(), 15.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
