#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"
#include <iostream>
#include <string>
class Building : public GameObject
{
private:
    unsigned int pokemon_count;

public:
    Building();
    Building(char in_code, int in_Id, Point2D in_loc);
    void AddOnePokemon();
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();
};
#endif