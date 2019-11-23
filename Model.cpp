#include "Model.h"

Model::Model()
{
    time = 0;

    Point2D pokemon1InLocation(5, 1);
    Point2D pokemon2InLocation(10, 1);
    Point2D pokemonCenter1InLocation(1, 20);
    Point2D pokemonCenter2InLocation(10, 20);
    Point2D pokemonGym1InLocation(0, 0);
    Point2D pokemonGym2InLocation(5, 5);

    std::string pokemon1InName = "Pikachu";
    std::string pokemon2InName = "Bulbasaur";

    Pokemon *pokemon1 = new Pokemon(pokemon1InName, 1, 'P', 2, pokemon1InLocation);
    Pokemon *pokemon2 = new Pokemon(pokemon2InName, 2, 'P', 1, pokemon2InLocation);
    PokemonCenter *pokemonCenter1 = new PokemonCenter(1, 1, 100, pokemonCenter1InLocation);
    PokemonCenter *pokemonCenter2 = new PokemonCenter(2, 2, 200, pokemonCenter2InLocation);
    PokemonGym *pokemonGym1 = new PokemonGym(10, 1, 2, 3, 1, pokemonGym1InLocation);
    PokemonGym *pokemonGym2 = new PokemonGym(20, 5, 7.5, 8, 2, pokemonGym2InLocation);

    object_ptrs[0] = pokemon1;
    object_ptrs[1] = pokemon2;
    object_ptrs[2] = pokemonCenter1;
    object_ptrs[3] = pokemonCenter2;
    object_ptrs[4] = pokemonGym1;
    object_ptrs[5] = pokemonGym2;

    pokemon_ptrs[0] = pokemon1;
    pokemon_ptrs[1] = pokemon2;

    center_ptrs[0] = pokemonCenter1;
    center_ptrs[1] = pokemonCenter2;

    gym_ptrs[0] = pokemonGym1;
    gym_ptrs[1] = pokemonGym2;

    num_objects = 6;
    num_pokemon = 2;
    num_centers = 2;
    num_gyms = 2;

    std::cout << "Model default constructed.\n";
}
Model::~Model()
{
    for (int i = 0; i < num_objects; i++)
    {
        delete object_ptrs[i];
    }
    for (int i = 0; i < num_pokemon; i++)
    {
        delete pokemon_ptrs[i];
    }
    for (int i = 0; i < num_centers; i++)
    {
        delete center_ptrs[i];
    }
    for (int i = 0; i < num_gyms; i++)
    {
        delete gym_ptrs[i];
    }
    std::cout << "Model destructed.\n";
}

Pokemon *Model::GetPokemonPtr(int id)
{
    for (int i = 0; i < num_pokemon; i++)
    {
        if (pokemon_ptrs[i]->GetId() == id)
        {
            return pokemon_ptrs[i];
        }
    }
    return 0;
}

PokemonCenter *Model::GetPokemonCenterPtr(int id)
{
    for (int i = 0; i < num_centers; i++)
    {
        if (center_ptrs[i]->GetId() == id)
        {
            return center_ptrs[i];
        }
    }
    return 0;
}
PokemonGym *Model::GetPokemonGymPtr(int id)
{
    for (int i = 0; i < num_gyms; i++)
    {
        if (gym_ptrs[i]->GetId() == id)
        {
            return gym_ptrs[i];
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

    for (int i = 0; i < num_objects; i++)
    {
        if (object_ptrs[i]->Update() && !temp)
        {
            temp = true;
        }
    }

    for (int i = 0; i < num_gyms; i++)
    {
        if (gym_ptrs[i]->IsBeaten())
        {
            gyms_beaten++;
        }
    }
    for (int i = 0; i < num_pokemon; i++)
    {
        if (pokemon_ptrs[i]->IsExhausted())
        {
            pokemon_exhausted++;
        }
    }

    if (gyms_beaten == num_gyms)
    {
        std::cout << "GAME OVER: You win! All Pokemon Gyms beaten\n";
        exit(EXIT_SUCCESS);
    }
    if (pokemon_exhausted == num_pokemon)
    {
        std::cout << "GAME OVER: You lose! All of your Pokemon are tired!\n";
        exit(EXIT_SUCCESS);
    }

    if (temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Model::Display(View &view)
{

    for (int i = 0; i < num_objects; i++)
    {
        view.Plot(object_ptrs[i]);
    }
}
void Model::ShowStatus()
{
    std::cout << "Time: " << time << '\n';
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}