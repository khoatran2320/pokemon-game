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
        ptr->DrawSelf(&grid[out_x][out_y][0]);
    }
}

void View::Draw()
{
    std::cout << 20;
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[0][i][0];
        std::cout << grid[0][i][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[1][i][0];
        std::cout << grid[1][i][1];
    }
    std::cout << '\n';
    std::cout << 16;
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[2][i][0];
        std::cout << grid[2][i][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[3][i][0];
        std::cout << grid[3][i][1];
    }
    std::cout << '\n';
    std::cout << 12;
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[4][i][0];
        std::cout << grid[4][i][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[5][i][0];
        std::cout << grid[5][i][1];
    }
    std::cout << '\n';
    std::cout << 8 << ' ';
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[6][i][0];
        std::cout << grid[6][i][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[7][i][0];
        std::cout << grid[7][i][1];
    }
    std::cout << '\n';
    std::cout << 4 << ' ';
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[8][i][0];
        std::cout << grid[8][i][1];
    }
    std::cout << "\n  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[9][i][0];
        std::cout << grid[9][i][1];
    }
    std::cout << '\n';
    std::cout << 0 << ' ';
    for (int i = 0; i < size; i++)
    {
        std::cout << grid[10][i][0];
        std::cout << grid[10][i][1];
    }
    std::cout << "\n  ";
    std::cout << "0   4   8   12  16  20\n";
}