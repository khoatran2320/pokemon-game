#include <iostream>
#include "Vector2D.h"
using namespace std;

Vector2D::Vector2D()
{
    x = 0.0;
    y = 0.0;
}
Vector2D::Vector2D(double x_in, double y_in)
{
    x = x_in;
    y = y_in;
}

ostream &operator<<(ostream &out, Vector2D &vector)
{
    out << '<' << vector.x << ',' << vector.y << '>';
    return out;
};
Vector2D operator*(Vector2D &vector, double d)
{
    Vector2D newClass;
    newClass.x = vector.x * d;
    newClass.y = vector.y * d;
    return newClass;
};
Vector2D operator/(Vector2D &vector, double d)
{
    if (d == 0)
    {
        return vector;
    }
    else
    {
        Vector2D newClass;

        newClass.x = vector.x / d;
        newClass.y = vector.y / d;
        return newClass;
    }
}
