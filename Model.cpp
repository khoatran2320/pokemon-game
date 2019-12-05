#include "Model.h"

Model::Model()
{
    time = 0;

    //initialize all the locations for each object
    Point2D pokemon1InLocation(5, 1);
    Point2D pokemon2InLocation(10, 1);
    Point2D pokemonCenter1InLocation(1, 20);
    Point2D pokemonCenter2InLocation(10, 20);
    Point2D pokemonGym1InLocation(0, 0);
    Point2D pokemonGym2InLocation(5, 5);
    Point2D battleArenaInLocation(15, 12);

    std::string pokemon1InName = "Pikachu";
    std::string pokemon2InName = "Bulbasaur";

    //making new objects
    //add Rivals
    Pokemon *pokemon1 = new Pokemon(pokemon1InName, 2, 23, 3, 6, 12, 1, 'P', pokemon1InLocation);
    Pokemon *pokemon2 = new Pokemon(pokemon2InName, 1, 26, 4, 3.7, 16, 2, 'P', pokemon2InLocation);
    PokemonCenter *pokemonCenter1 = new PokemonCenter(1, 1, 100, pokemonCenter1InLocation);
    PokemonCenter *pokemonCenter2 = new PokemonCenter(2, 2, 200, pokemonCenter2InLocation);
    PokemonGym *pokemonGym1 = new PokemonGym(10, 1, 2, 3, 1, pokemonGym1InLocation);
    PokemonGym *pokemonGym2 = new PokemonGym(20, 5, 7.5, 8, 2, pokemonGym2InLocation);
    BattleArena *battleArena1 = new BattleArena(3, 3, 2.5, 1, battleArenaInLocation);
    Rival *rival1 = new Rival("burhack", 2, 16, 3, 7.2, 20, 1, battleArenaInLocation);
    Rival *rival2 = new Rival("mmark9", 3, 29, 4, 5.2, 12, 2, battleArenaInLocation);
    Rival *rival3 = new Rival("Densmore(aka BigBoss)", 4, 41, 6, 8.2, 18, 3, battleArenaInLocation);

    object_ptrs.push_back(pokemon1);
    object_ptrs.push_back(pokemon2);
    object_ptrs.push_back(rival1);
    object_ptrs.push_back(rival2);
    object_ptrs.push_back(rival3);
    object_ptrs.push_back(pokemonCenter1);
    object_ptrs.push_back(pokemonCenter2);
    object_ptrs.push_back(pokemonGym1);
    object_ptrs.push_back(pokemonGym2);
    object_ptrs.push_back(battleArena1);

    active_ptrs.push_back(pokemon1);
    active_ptrs.push_back(pokemon2);
    active_ptrs.push_back(rival1);
    active_ptrs.push_back(rival2);
    active_ptrs.push_back(rival3);
    active_ptrs.push_back(pokemonCenter1);
    active_ptrs.push_back(pokemonCenter2);
    active_ptrs.push_back(pokemonGym1);
    active_ptrs.push_back(pokemonGym2);
    active_ptrs.push_back(battleArena1);

    //storing the objects in the appropriate arrays
    // object_ptrs[0] = pokemon1;
    // object_ptrs[1] = pokemon2;
    // object_ptrs[2] = rival1;
    // object_ptrs[3] = rival2;
    // object_ptrs[4] = rival3;
    // object_ptrs[5] = pokemonCenter1;
    // object_ptrs[6] = pokemonCenter2;
    // object_ptrs[7] = pokemonGym1;
    // object_ptrs[8] = pokemonGym2;
    // object_ptrs[9] = battleArena1;

    pokemon_ptrs.push_back(pokemon1);
    pokemon_ptrs.push_back(pokemon2);
    // pokemon_ptrs[0] = pokemon1;
    // pokemon_ptrs[1] = pokemon2;

    rival_ptrs.push_back(rival1);
    rival_ptrs.push_back(rival2);
    rival_ptrs.push_back(rival3);
    // rival_ptrs[0] = rival1;
    // rival_ptrs[1] = rival2;
    // rival_ptrs[2] = rival3;

    center_ptrs.push_back(pokemonCenter1);
    center_ptrs.push_back(pokemonCenter2);
    // center_ptrs[0] = pokemonCenter1;
    // center_ptrs[1] = pokemonCenter2;

    gym_ptrs.push_back(pokemonGym1);
    gym_ptrs.push_back(pokemonGym2);
    // gym_ptrs[0] = pokemonGym1;
    // gym_ptrs[1] = pokemonGym2;

    arena_ptrs.push_back(battleArena1);
    // arena_ptrs[0] = battleArena1;

    // num_objects = 10;
    // num_pokemon = 2;
    // num_centers = 2;
    // num_gyms = 2;
    // num_rivals = 3;
    // num_arenas = 1;
    std::cout << "Model default constructed.\n";
}
Model::~Model()
{
    //delete all the objects
    for (object_it = object_ptrs.begin(); object_it != object_ptrs.end(); ++object_it)
    {
        delete *object_it;
    }

    std::cout << "Model destructed.\n";
}

//loop through the arrays and check the id
Pokemon *Model::GetPokemonPtr(int id)
{
    for (pokemon_it = pokemon_ptrs.begin(); pokemon_it != pokemon_ptrs.end(); ++pokemon_it)
    {
        if ((*pokemon_it)->GetId() == id)
        {
            return *pokemon_it;
        }
    }
    return 0;
}

PokemonCenter *Model::GetPokemonCenterPtr(int id)
{
    for (center_it = center_ptrs.begin(); center_it != center_ptrs.end(); ++center_it)
    {
        if ((*center_it)->GetId() == id)
        {
            return *center_it;
        }
    }
    return 0;
}
PokemonGym *Model::GetPokemonGymPtr(int id)
{
    for (gym_it = gym_ptrs.begin(); gym_it != gym_ptrs.end(); ++gym_it)
    {
        if ((*gym_it)->GetId() == id)
        {
            return *gym_it;
        }
    }
    return 0;
}

Rival *Model::GetRivalPtr(int id)
{
    for (rival_it = rival_ptrs.begin(); rival_it != rival_ptrs.end(); ++rival_it)
    {
        if ((*rival_it)->GetId() == id)
        {
            return *rival_it;
        }
    }
    return 0;
}
BattleArena *Model::GetBattleArenaPtr(int id)
{
    for (arena_it = arena_ptrs.begin(); arena_it != arena_ptrs.end(); ++arena_it)
    {
        if ((*arena_it)->GetId() == id)
        {
            return *arena_it;
        }
    }
    return 0;
}
bool Model::Update()
{
    time++;
    int gyms_beaten = 0;
    int pokemon_exhausted = 0;
    bool temp = false;

    for (pokemon_it = pokemon_ptrs.begin(); pokemon_it != pokemon_ptrs.end(); ++pokemon_it)
    {
        if (!(*pokemon_it)->IsAlive())
        {

            active_ptrs.remove(*pokemon_it);
            std::cout << "Dead " << (*pokemon_it)->GetPokemonName() << " removed\n";
        }
    }
    for (rival_it = rival_ptrs.begin(); rival_it != rival_ptrs.end(); ++rival_it)
    {
        if (!(*rival_it)->IsAlive())
        {

            active_ptrs.remove(*rival_it);
            std::cout << "Dead " << (*rival_it)->GetRivalName() << " removed\n";
        }
    }

    //see if any object update returns true and set bool to temp if temp not already true
    for (active_it = active_ptrs.begin(); active_it != active_ptrs.end(); ++active_it)
    {
        if ((*active_it)->Update() && !temp)
        {
            temp = true;
        }
    }
    //count the gyms beaten and pokemon exhausted to compare to total numbers to identify end game status
    for (gym_it = gym_ptrs.begin(); gym_it != gym_ptrs.end(); ++gym_it)
    {
        if ((*gym_it)->IsBeaten())
        {
            gyms_beaten++;
        }
    }
    for (pokemon_it = pokemon_ptrs.begin(); pokemon_it != pokemon_ptrs.end(); ++pokemon_it)
    {
        if ((*pokemon_it)->IsExhausted())
        {
            pokemon_exhausted++;
        }
    }

    if (gyms_beaten == gym_ptrs.size())
    {
        std::cout << "GAME OVER: You win! All Pokemon Gyms beaten\n";

        exit(EXIT_SUCCESS);
    }
    if (pokemon_exhausted == pokemon_ptrs.size())
    {
        std::cout << "GAME OVER: You lose! All of your Pokemon are tired!\n";
        exit(EXIT_SUCCESS);
    }

    return temp;
}

void Model::Display(View &view)
{

    for (active_it = active_ptrs.begin(); active_it != active_ptrs.end(); ++active_it)
    {
        //plot all the game objects if they're visible

        view.Plot((*active_it));
    }
}
void Model::ShowStatus()
{
    //show status for every game object
    std::cout << "Time: " << time << '\n';
    for (object_it = object_ptrs.begin(); object_it != object_ptrs.end(); ++object_it)
    {
        (*object_it)->ShowStatus();
    }
}