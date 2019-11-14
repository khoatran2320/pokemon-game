#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include "Building.h"
enum PokemonGymStates
{
    NOT_BEATEN = 0,
    BEATEN = 1
};
class PokemonGym : public Building
{
public:
    PokemonGym();
    PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc);
    double GetDollarCost(unsigned int unit_qty);
    unsigned int GetStaminaCost(unsigned int unit_qty);
    unsigned int GetNumTrainingUnitsRemaining();
    bool IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina);
    unsigned int TrainPokemon(unsigned int training_units);
    bool Update();
    bool IsBeaten();
    void ShowStatus();

private:
    unsigned int num_training_units_remaining;
    unsigned int max_number_of_training_units;
    unsigned int stamina_cost_per_training_unit;
    unsigned int dollar_cost_per_training_unit;
    unsigned int experience_points_per_training_unit;
};
#endif