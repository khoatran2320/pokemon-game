#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>
#include <math.h>
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Rival.h"
#include "BattleArena.h"
#include <cstdlib>
enum PokemonStates
{
    STOPPED = 0,
    MOVING = 1,
    EXHAUSTED = 2,
    IN_GYM = 3,
    IN_CENTER = 4,
    MOVING_TO_GYM = 5,
    MOVING_TO_CENTER = 6,
    TRAINING_IN_GYM = 7,
    RECOVERING_STAMINA = 8,
    IN_ARENA = 9,
    MOVING_TO_ARENA = 10,
    BATTLE = 11,
    FAINTED = 12
};
class Pokemon : public GameObject
{
public:
    Pokemon();
    Pokemon(char in_code);
    Pokemon(std::string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    void StartMoving(Point2D dest);
    void StartMovingToCenter(PokemonCenter *center);
    void StartMovingToGym(PokemonGym *gym);
    void StartTraining(unsigned int num_training_units);
    void StartRecoveringStamina(unsigned int num_stamina_points);
    
    void Stop();
    bool IsExhausted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    std::string GetPokemonName();
    Pokemon(std::string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc);
    bool IsAlive();
    void TakeHit(double physical_damage, double magical_damage, double defense);
    void ReadyBattle(Rival *in_target);
    bool StartBattle();

    ~Pokemon();

protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);
    double health = 20;         //initial value is 20
    double store_health;        //will be same as health and used to restore health if pokemon wins battle
    double physical_damage = 5; //initial value is 5
    double magical_damage = 4;  //initial value is 4
    double defense = 15;        //parry percentage of attack
    Rival *target;              //rival battle in arena
    bool is_in_arena;           //returns true if in arena
    BattleArena *current_arena;

private:
    double speed;
    bool is_in_gym;
    bool is_in_center;
    unsigned int stamina;
    unsigned int experience_points;
    double pokemon_dollars;
    unsigned int training_units_to_buy;
    unsigned int stamina_points_to_buy;
    std::string name;
    PokemonCenter *current_center;
    PokemonGym *current_gym;
    Point2D destination;
    Vector2D delta;
};
double GetRandomAmountOfPokemonDollars();
#endif