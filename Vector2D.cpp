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

int main()
{
    Vector2D v1;
    Vector2D v2(4.0, 4.0);
    Vector2D v3(1.0, 2.0);

    v1 = v2 * 2.0;
    cout << v1 << '\n';
    v1 = v2 / 2.0;
    cout << v1 << '\n';
    return 0;
}