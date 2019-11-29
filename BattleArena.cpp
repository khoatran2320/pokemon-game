#include "BattleArena.h"
BattleArena::BattleArena()
{
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;
    std::cout << "BattleArena default constructed.\n";
}
BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc) : Building('A', in_Id, in_loc)
{
    max_num_rivals = max_rivals;
    stamina_cost_per_fight = stamina_cost;
    dollar_cost_per_fight = dollar_cost;
    pokemon_count = 0;
    num_rivals_remaining = max_num_rivals;
    state = RIVALS_AVAILABLE;
    std::cout << "BattleArena constructed.\n";
}
unsigned int BattleArena::GetNumRivalsRemaining()
{
    return num_rivals_remaining;
}
bool BattleArena::HasEnoughRivals()
{
    return (num_rivals_remaining > 0);
}
double BattleArena::GetDollarCost()
{
    return dollar_cost_per_fight;
}
unsigned int BattleArena::GetStaminaCost()
{
    return stamina_cost_per_fight;
}
bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
    return (dollar_cost_per_fight < budget && stamina_cost_per_fight < stamina);
}

bool BattleArena::Update()
{
    if (num_rivals_remaining == 0 && state != NO_RIVALS_AVAILABLE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BattleArena::IsBeaten()
{
    return (num_rivals_remaining == 0);
}

void BattleArena::ShowStatus()
{
    GameObject::ShowStatus();
    Building::ShowStatus();
    std::cout << "\tMax number of rivals: " << max_num_rivals << '\n';
    std::cout << "\tStamina cost per fight: " << stamina_cost_per_fight << '\n';
    std::cout << "\tPokemon dollar per fight: " << dollar_cost_per_fight << '\n';
    std::cout << num_rivals_remaining << " rival(s) are remaining for this arena" << '\n';
}