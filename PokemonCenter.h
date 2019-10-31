#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include "Building.h"
class PokemonCenter : Building
{
    enum PokemonCenterStates
    {
        STAMINA_POINTS_AVAILABLE = 0,
        NO_STAMINA_POINTS_AVAILABLE = 1
    };

public:
    PokemonCenter();
    PokemonCenter(int in_Id, Point2D in_loc);
    bool HasStaminaPoints();
    unsigned int GetNumStaminaPointsRemaing();
    bool CanAffordStaminaPoints(unsigned int stamina_points, double budget);
    double GetDollarCost(unsigned int stamina_points);
    unsigned int DistributeStamina(unsigned int points_needed = 0);
    bool Update();
    void ShowStatus();

private:
    unsigned int stamina_capacity;
    unsigned int num_stamina_points_remaining;
    double dollar_cost_per_stamina_point;
};
#endif