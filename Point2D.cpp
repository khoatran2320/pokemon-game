#include <math.h>
#include <iostream>
#include "Point2D.h"
using namespace std;

Point2D::Point2D()
{
    x = 0.0;
    y = 0.0;
}
Point2D::Point2D(double in_x, double in_y)
{
    x = in_x;
    y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

ostream &operator<<(ostream &out, Point2D &point)
{
    out << '(' << point.x << ',' << point.y << ')';
    return out;
}
Point2D operator+(Point2D &class1, Point2D &class2)
{
    Point2D newClass;
    newClass.x = class1.x + class2.x;
    newClass.y = class1.y + class2.y;
    return newClass;
}

Point2D operator-(Point2D &class1, Point2D &class2)
{
    Point2D newClass;
    newClass.x = class1.x - class2.x;
    newClass.y = class1.y - class2.y;
    return newClass;
}
// int main()
// {
//     Point2D c1;
//     Point2D c2(1.0, 1.0);
//     Point2D c3(2.5, 3.1);
//     c1 = c2 + c3;
//     cout << c1 << '\n';
//     c1 = c2 - c3;
//     cout << c1 << '\n';
// }