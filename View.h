#ifndef VIEW_H
#define VIEW_H
#include "Point2D.h"
#include "GameObject.h"
#include <math.h>
const int view_maxsize = 20;
class View
{
public:
    View();
    void Clear();
    void Plot(GameObject *ptr);
    void Draw();

private:
    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    bool GetSubscripts(int &out_x, int &out_y, Point2D location);
};
#endif