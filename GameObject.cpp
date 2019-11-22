#include <iostream>
#include "GameObject.h"

GameObject::GameObject()
{
    display_code = ' ';
}
GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    state = 0;
    std::cout << "GameObject Constructed\n";
}
GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    state = 0;
    std::cout << "GameObject Constructed\n";
}
Point2D GameObject::GetLocation()
{
    return location;
}
int GameObject::GetId()
{
    return id_num;
}
char GameObject::GetState()
{
    return state;
}
void GameObject::ShowStatus()
{
    std::cout << display_code << id_num << " at " << location;
}

GameObject::~GameObject()
{
    std::cout << "GameObject destructed.\n";
}
void GameObject::DrawSelf(char *ptr)
{
    *ptr = display_code;
    *(ptr + 1) = id_num;
}