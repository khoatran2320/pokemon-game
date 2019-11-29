#include "Rival.h"

Rival::Rival(std::string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc) : GameObject(in_loc, id, 'R')
{
    name = name;
    speed = speed;
    health = hp;
    physical_damage = physical_damage;
    magical_damage = magic_dmg;
    defense = def;
}
void Rival::TakeHit(double physical_damage, double magical_damage, double defense)
{
    int randNum = rand() % 2;

    if (randNum == 0)
    {
        health -= (100.0 - defense) / 100 * physical_damage;
    }
    else
    {
        health -= (100.0 - defense) / 100 * magical_damage;
    }
}
double Rival::get_phys_dmg()
{
    return physical_damage;
}
double Rival::get_magic_dmg()
{
    return magical_damage;
}
double Rival::get_health()
{
    return health;
}
double Rival::get_defense()
{
    return defense;
}

//update state if health is <=0 else don't update and return false
bool Rival::Update()
{
    if (health <= 0)
    {
        state = FAINTED_RIVAL;
        return true;
    }
    else
    {
        return false;
    }
}

void Rival::ShowStatus()
{
    std::cout << "Rival status: ";
    GameObject::ShowStatus();
    if (state == ALIVE_RIVAL)
    {
        std::cout << " alive\n";
        std::cout << "\thealth: " << health << '\n';
        std::cout << "\tphysical damage: " << physical_damage << '\n';
        std::cout << "\tmagic damage: " << magical_damage << '\n';
        std::cout << "\tdefense: " << defense << '\n';
    }
    else
    {
        std::cout << " defeated\n";
        std::cout << "\thealth: " << health << '\n';
        std::cout << "\tphysical damage: " << physical_damage << '\n';
        std::cout << "\tmagic damage: " << magical_damage << '\n';
        std::cout << "\tdefense: " << defense << '\n';
    }
}