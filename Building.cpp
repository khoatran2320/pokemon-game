#include "Building.h"

Building::Building()
{
    display_code = 'B';
    pokemon_count = 0;
    std::cout << "Building default constructed\n";
}
Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    id_num = in_id;
    location = in_loc;
    display_code = in_code;
    pokemon_count = 0;
    std::cout << "Building constructed\n";
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
    std::cout << '\t' << pokemon_count << " pokemon " << verb << " in this building\n";
}
bool Building::ShouldBeVisible()
{
    return true;
}
Building::~Building()
{
    std::cout << "Building destructed.\n";
}