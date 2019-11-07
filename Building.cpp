#include "Building.h"

Building::Building()
{
    display_code = 'B';
    std::cout << "Building default constructed\n";
}
Building::Building(char in_code, int in_Id, Point2D in_loc)
{
    id_num = in_Id;
    location = in_loc;
    display_code = in_code;
}
void Building::AddOnePokemon()
{
    ++pokemon_count;
}
void Building::RemoveOnePokemon()
{
    --pokemon_count;
}
void Building::ShowStatus()
{
    std::string verb = " ";
    if (pokemon_count == 1)
    {
        verb = "is";
    }
    else
    {
        verb = "are";
    }
    std::cout << display_code << id_num << " located at " << location << '\n';
    std::cout << pokemon_count << " pokemon " << verb << " in this building\n";
}
bool Building::ShouldBeVisible()
{
    return true;
}