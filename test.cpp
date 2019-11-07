#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"

int main()
{
    //some testing variables
    int in_id = 2;
    double stamina_cost = 2.3;
    unsigned int stamina = 100;
    unsigned int staminaCost = 10;
    unsigned int stamina_cap = 20;
    unsigned int stamina_points = 10;
    double budget = 22.1;
    double dollar_cost = 10.0;
    unsigned int points_needed = 10;
    char in_code = 'K';
    unsigned int max_training_units = 10;
    unsigned int exp_points_per_unit = 10;
    unsigned int unit_qty = 2;
    unsigned int training_units = 2;

    //testing Point2D
    Point2D point1(1.0, 1.0);
    Point2D point2(2.0, 2.0);
    Point2D point3 = point1 + point2;
    std::cout << point3 << '\n';
    point3 = point1 - point2;
    std::cout << point3 << '\n';
    std::cout << GetDistanceBetween(point1, point2) << '\n';

    //testing Vector2D
    Vector2D vect1(1.0, 1.0);
    Vector2D vect2(2.0, 2.0);
    Vector2D vect3 = vect1 * 2.0;
    std::cout << vect3 << '\n';
    vect3 = vect1 / 2.0;
    std::cout << vect3 << '\n';

    //testing GameObject
    GameObject gameObj1;
    GameObject gameObj2('H');
    GameObject gameObj3(point1, 2, 'H');
    Point2D point4 = gameObj3.GetLocation();
    std::cout << point4 << '\n';
    std::cout << gameObj3.GetId() << '\n';
    std::cout << gameObj3.GetState() << '\n';
    gameObj3.ShowStatus();

    //Building
    Point2D in_loc = point1;
    Building building1;
    Building building2(in_code, in_id, in_loc);
    building1.ShowStatus();
    building1.AddOnePokemon();
    building1.ShowStatus();
    building1.RemoveOnePokemon();
    building1.ShowStatus();
    std::cout << building1.ShouldBeVisible() << '\n';
    building2.ShowStatus();
    building2.AddOnePokemon();
    building2.ShowStatus();
    building2.RemoveOnePokemon();
    building2.ShowStatus();
    std::cout << building2.ShouldBeVisible() << '\n';

    //testing PokemonCenter
    PokemonCenter pokemonCent1;
    PokemonCenter pokemonCent2(in_id, stamina_cost, stamina_cap, in_loc);
    std::cout << pokemonCent1.HasStaminaPoints() << '\n';
    std::cout << pokemonCent1.GetNumStaminaPointsRemaining() << '\n';
    std::cout << pokemonCent1.CanAffordStaminaPoints(stamina_points, budget) << '\n';
    std::cout << pokemonCent1.GetDollarCost(stamina_points) << '\n';
    std::cout << pokemonCent1.DistributeStamina(points_needed) << '\n';
    std::cout << pokemonCent1.Update() << '\n';
    pokemonCent1.ShowStatus();
    std::cout << pokemonCent2.HasStaminaPoints() << '\n';
    std::cout << pokemonCent2.GetNumStaminaPointsRemaining() << '\n';
    std::cout << pokemonCent2.CanAffordStaminaPoints(stamina_points, budget) << '\n';
    std::cout << pokemonCent2.GetDollarCost(stamina_points) << '\n';
    std::cout << pokemonCent2.DistributeStamina(points_needed) << '\n';
    std::cout << pokemonCent2.Update() << '\n';
    pokemonCent2.ShowStatus();

    //testing PokemonGym
    PokemonGym pokemonGym1;
    PokemonGym pokemonGym2(max_training_units, staminaCost, dollar_cost, exp_points_per_unit, in_id, in_loc);
    std::cout << pokemonGym1.GetDollarCost(unit_qty) << '\n';
    std::cout << pokemonGym1.GetStaminaCost(unit_qty) << '\n';
    std::cout << pokemonGym1.GetNumTrainingUnitsRemaining() << '\n';
    std::cout << pokemonGym1.IsAbleToTrain(unit_qty, budget, stamina) << '\n';
    std::cout << pokemonGym1.TrainPokemon(training_units) << '\n';
    std::cout << pokemonGym1.Update() << '\n';
    std::cout << pokemonGym1.IsBeaten() << '\n';
    pokemonGym1.ShowStatus();
    std::cout << pokemonGym2.GetDollarCost(unit_qty) << '\n';
    std::cout << pokemonGym2.GetStaminaCost(unit_qty) << '\n';
    std::cout << pokemonGym2.GetNumTrainingUnitsRemaining() << '\n';
    std::cout << pokemonGym2.IsAbleToTrain(unit_qty, budget, stamina) << '\n';
    std::cout << pokemonGym2.TrainPokemon(training_units) << '\n';
    std::cout << pokemonGym2.Update() << '\n';
    std::cout << pokemonGym2.IsBeaten() << '\n';
    pokemonGym2.ShowStatus();
    return 0;
}