#include "Point2D.h"
#include "Vector2D.h"
// #include "GameObject.h"
// #include "Building.h"
// #include "PokemonCenter.h"

int main()
{
    //testing Point2D
    Point2D point1(1.0, 1.0);
    Point2D point2(2.0, 2.0);
    Point2D point3 = point1 + point2;
    std::cout << point3 << '\n';
    point3 = point1 - point2;
    std::cout << point3 << '\n';
    std::cout << GetDistanceBetween(point1, point2) << '\n';
    //testing Vector2D
    Vector2D vect1(1.0, 1.0);
    Vector2D vect2(2.0, 2.0);
    Vector2D vect3 = vect1 * 2.0;
    std::cout << vect3 << '\n';
    vect3 = vect1 / 2.0;
    std::cout << vect3 << '\n';

    return 0;
}