#include "Rival.h"

Rival::Rival(std::string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc) : GameObject(in_loc, id, 'R')
{
    this->name = name;
    this->speed = speed;
    this->health = hp;
    this->physical_damage = phys_dmg;
    this->magical_damage = magic_dmg;
    this->defense = def;
    std::cout << "Rival constructed.\n";
}
void Rival::TakeHit(double physical_damage, double magical_damage, double defense)
{
    int randNum = rand() % 2;
    double rival_last_health = health;
    if (randNum == 0)
    {

        health -= (100.0 - defense) / 100 * physical_damage;

        std::cout << name << ": I'm being attacked\n";
        std::cout << name << ": Aaagh, no physical pain no gain!\n";
        std::cout << "Damage Taken: " << rival_last_health - health << '\n';
        std::cout << "Health Remaining: " << health << '\n';
        std::cout << "*******\n";
        rival_last_health = health;
    }
    else
    {
        health -= (100.0 - defense) / 100 * magical_damage;
        std::cout << name << ": I'm being attacked\n";
        std::cout << name << ": Ouch, I don't believe magic!\n";
        std::cout << "Damage Taken: " << rival_last_health - health << '\n';
        std::cout << "Health Remaining: " << health << '\n';
        std::cout << "*******\n";
        rival_last_health = health;
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
    std::cout << name << " status: ";
    GameObject::ShowStatus();
    if (state == ALIVE_RIVAL)
    {
        std::cout << " alive\n";
        std::cout << "\tHealth: " << this->health << '\n';
        std::cout << "\tPhysical Damage: " << this->physical_damage << '\n';
        std::cout << "\tMagical Damage: " << this->magical_damage << '\n';
        std::cout << "\tDefense: " << this->defense << '\n';
    }
    else
    {
        std::cout << " defeated\n";
        std::cout << "\tHealth: " << this->health << '\n';
        std::cout << "\tPhysical Damage: " << this->physical_damage << '\n';
        std::cout << "\tMagical Damage: " << this->magical_damage << '\n';
        std::cout << "\tDefense: " << this->defense << '\n';
    }
}
bool Rival::IsAlive()
{
    if (state == FAINTED_RIVAL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Rival::ShouldBeVisible()
{
    if (IsAlive())
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Rival::GetRivalName()
{
    return name;
}