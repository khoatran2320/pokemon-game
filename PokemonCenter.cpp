#include "PokemonCenter.h"

PokemonCenter::PokemonCenter()
{
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;
    std::cout << "PokemonCenter default constructed\n";
}
PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc) : Building('C', in_id, in_loc)
{
    display_code = 'C';
    id_num = in_id;
    location = in_loc;
    stamina_capacity = stamina_cap;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = stamina_cost;
    state = STAMINA_POINTS_AVAILABLE;
    std::cout << "PokemonCenter constructed.\n";
}
bool PokemonCenter::HasStaminaPoints()
{
    if (STAMINA_POINTS_AVAILABLE >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
    return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    if (budget > stamina_points * dollar_cost_per_stamina_point)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    return stamina_points * dollar_cost_per_stamina_point;
}
unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
    if (num_stamina_points_remaining >= points_needed)
    {
        num_stamina_points_remaining -= points_needed;
        return points_needed;
    }
    else
    {
        unsigned int temp = num_stamina_points_remaining;
        num_stamina_points_remaining = 0;
        return temp;
    }
}

bool PokemonCenter::Update()
{
    if (num_stamina_points_remaining == 0 && state != NO_STAMINA_POINTS_AVAILABLE)
    {
        state = NO_STAMINA_POINTS_AVAILABLE;
        display_code = 'c';
        std::cout << "PokemonCenter " << id_num << " has ran out of stamina points.\n";
        return true;
    }
    else
    {
        return false;
    }
}
void PokemonCenter::ShowStatus()
{
    std::cout << "Pokemon Center Status: ";
    Building::ShowStatus();
    std::cout << "\tPokemon dollar cost per stamina point: " << dollar_cost_per_stamina_point << '\n';
    std::cout << "\thas " << num_stamina_points_remaining << " stamina point(s) remaining\n";
}
PokemonCenter::~PokemonCenter()
{
    std::cout << "PokemonCenter destructed.\n";
}