#ifndef RIVAL_H
#define RIVAL_H
#include "GameObject.h"
#include "BattleArena.h"
enum RivalStates
{
    ALIVE_RIVAL = 0,
    FAINTED_RIVAL = 1
};
class Rival : public GameObject
{
public:
    Rival(std::string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc);
    void TakeHit(double physical_damage, double magical_damage, double defense);
    double get_phys_dmg();
    double get_magic_dmg();
    double get_defense();
    double get_health();
    bool Update();
    bool IsAlive();
    void ShowStatus();
    bool ShouldBeVisible();

protected:
    double health = 20;
    double physical_damage = 5;
    double magical_damage = 4;
    double defense = 15;
    bool is_in_arena;
    BattleArena *current_arena;

private:
    double speed;
    std::string name;
};
#endif