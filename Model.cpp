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
    pokemon_ptrs[0] = pokemon1;

    num_objects = 6;
}