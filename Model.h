#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <stdlib.h>
#include <list>
#include <iterator>
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "Point2D.h"
#include "BattleArena.h"
#include "Rival.h"
#include "Input_Handling.h"

class Model
{
public:
    Model();
    ~Model();
    Pokemon *GetPokemonPtr(int id);
    PokemonCenter *GetPokemonCenterPtr(int id);
    PokemonGym *GetPokemonGymPtr(int id);
    Rival *GetRivalPtr(int id);
    BattleArena *GetBattleArenaPtr(int id);
    void NewCommand(char type, int id, Point2D location);
    bool Update();
    void Display(View &view);
    void ShowStatus();

protected:
    int time;
    // GameObject *object_ptrs[10];
    std::list<GameObject *> object_ptrs;
    std::list<GameObject *>::iterator object_it;

    std::list<GameObject *> active_ptrs;
    std::list<GameObject *>::iterator active_it;
    // int num_objects;

    // Pokemon *pokemon_ptrs[10];
    std::list<Pokemon *> pokemon_ptrs;
    std::list<Pokemon *>::iterator pokemon_it;

    // int num_pokemon;

    // PokemonCenter *center_ptrs[10];
    std::list<PokemonCenter *> center_ptrs;
    std::list<PokemonCenter *>::iterator center_it;
    // int num_centers;

    // PokemonGym *gym_ptrs[10];
    std::list<PokemonGym *> gym_ptrs;
    std::list<PokemonGym *>::iterator gym_it;
    // int num_gyms;

    // BattleArena *arena_ptrs[10];
    std::list<BattleArena *> arena_ptrs;
    std::list<BattleArena *>::iterator arena_it;
    // int num_arenas;

    // Rival *rival_ptrs[10];
    std::list<Rival *> rival_ptrs;
    std::list<Rival *>::iterator rival_it;
    // int num_rivals;
};
#endif