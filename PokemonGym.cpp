#include "PokemonGym.h"

PokemonGym::PokemonGym()
{
    display_code = 'G';
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    std::cout << "PokemonGym default constructed\n";
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc)
{
    id_num = in_id;
    max_number_of_training_units = max_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    dollar_cost_per_training_unit = dollar_cost;
    location = in_loc;
    display_code = 'G';
    state = NOT_BEATEN;
    num_training_units_remaining = max_number_of_training_units;
    experience_points_per_training_unit = 2;
    std::cout << "PokemonGym constructed\n";
}
double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
    return dollar_cost_per_training_unit * unit_qty;
}
unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
    return stamina_cost_per_training_unit * unit_qty;
}
unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
    return num_training_units_remaining;
}
bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
    if (budget >= unit_qty * dollar_cost_per_training_unit && stamina >= unit_qty * stamina_cost_per_training_unit)
    {
        return true;
    }
    else
    {
        return false;
    }
}
unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
    if (training_units > num_training_units_remaining)
    {
        return experience_points_per_training_unit * num_training_units_remaining;
    }
    else
    {
        return training_units * experience_points_per_training_unit;
    }
}
bool PokemonGym::Update()
{
    if (num_training_units_remaining == 0 && state != BEATEN)
    {
        state = BEATEN;
        display_code = 'g';
        std::cout << display_code << id_num << " has been beaten.\n";
        return true;
    }
    else
    {
        return false;
    }
}

bool PokemonGym::IsBeaten()
{
    if (num_training_units_remaining == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PokemonGym::ShowStatus()
{
    std::cout << "Pokemon Gym Status: ";
    Building::ShowStatus();
    std::cout << "Max number of training units: " << max_number_of_training_units << '\n';
    std::cout << "Stamina cost per training unit: " << stamina_cost_per_training_unit << '\n';
    std::cout << "Pokemon dollar per training unit: " << dollar_cost_per_training_unit << '\n';
    std::cout << "Experience points per training unit: " << experience_points_per_training_unit << '\n';
    std::cout << num_training_units_remaining << " training unit(s) are remaining for this gym" << '\n';
}