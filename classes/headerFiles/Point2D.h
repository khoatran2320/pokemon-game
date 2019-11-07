#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
class Point2D
{
public:
    double x;
    double y;
    Point2D();
    Point2D(double in_x, double in_y);
};
double GetDistanceBetween(Point2D p1, Point2D p2);
std::ostream &operator<<(std::ostream &out, Point2D &point);
Point2D operator+(Point2D &class1, Point2D &class2);
Point2D operator-(Point2D &class1, Point2D &class2);

#endif