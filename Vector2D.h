#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
class Vector2D
{
public:
    double x;
    double y;
    Vector2D();
    Vector2D(double in_x, double in_y);
};
std::ostream &operator<<(std::ostream &out, Vector2D &vector);
Vector2D operator*(Vector2D &vector, double d);
Vector2D operator/(Vector2D &vector, double d);
#endif