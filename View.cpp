#include "View.h"
bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
    if (((location.x - origin.x) / scale < view_maxsize) && ((location.y - origin.y) / scale < view_maxsize))
    {
        out_x = floor((location.x - origin.x) / scale);
        out_y = floor((location.y - origin.y) / scale);
        return true;
    }
    else
    {
        std::cout << "An object is outside the display\n";
        return false;
    }
}

View::View()
{
    size = 11;
    scale = 2;
    Point2D inOrigin(0, 0);
    origin = inOrigin;
}

void View::Clear()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View::Plot(GameObject *ptr)
{
    int out_x = 0;
    int out_y = 0;
    if (GetSubscripts(out_x, out_y, ptr->GetLocation()))
    {

        ptr->DrawSelf(grid[out_x][out_y]);
    }
}

void View::Draw()
{
    std::cout << 20;
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][10][0];
        std::cout << grid[i][10][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][9][0];
        std::cout << grid[i][9][1];
    }
    std::cout << '\n';
    std::cout << 16;
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][8][0];
        std::cout << grid[i][8][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][7][0];
        std::cout << grid[i][7][1];
    }
    std::cout << '\n';
    std::cout << 12;
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][6][0];
        std::cout << grid[i][6][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][5][0];
        std::cout << grid[i][5][1];
    }
    std::cout << '\n';
    std::cout << 8 << ' ';
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][4][0];
        std::cout << grid[i][4][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][3][0];
        std::cout << grid[i][3][1];
    }
    std::cout << '\n';
    std::cout << 4 << ' ';
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][2][0];
        std::cout << grid[i][2][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][1][0];
        std::cout << grid[i][1][1];
    }
    std::cout << '\n';
    std::cout << 0 << ' ';
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[i][0][0];
        std::cout << grid[i][0][1];
    }
    std::cout << "\n  ";
    std::cout << "0   4   8   12  16  20\n";
}