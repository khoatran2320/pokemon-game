#include "GameCommand.h"

void GameCommand::DoMoveCommand(Model &model, int pokemon_id, Point2D p1)
{
    if (model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        std::cout << "Moving " << pokemon->GetPokemonName() << " to gym " << p1 << '\n';
        pokemon->StartMoving(p1);
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}

void GameCommand::DoMoveToCenterCommand(Model &model, int pokemon_id, int center_id)
{
    if (model.GetPokemonCenterPtr(center_id) && model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        PokemonCenter *pokemon_center = model.GetPokemonCenterPtr(center_id);
        pokemon->StartMovingToCenter(pokemon_center);
        std::cout << "Moving " << pokemon->GetPokemonName() << " to center " << center_id << '\n';
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}

void GameCommand::DoMoveToGymCommand(Model &model, int pokemon_id, int gym_id)
{
    if (model.GetPokemonGymPtr(gym_id) && model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        PokemonGym *pokemon_gym = model.GetPokemonGymPtr(gym_id);
        pokemon->StartMovingToGym(pokemon_gym);
        std::cout << "Moving " << pokemon->GetPokemonName() << " to " << gym_id << '\n';
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}

void GameCommand::DoStopCommand(Model &model, int pokemon_id)
{
    if (model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        pokemon->Stop();
        std::cout << "Stopping " << pokemon->GetPokemonName() << '\n';
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}
void GameCommand::DoTrainInGymCommand(Model &model, int pokemon_id, unsigned int training_units)
{
    if (model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        pokemon->StartTraining(training_units);
        if (pokemon->GetState() == TRAINING_IN_GYM)
        {
            std::cout << "Training " << pokemon->GetPokemonName() << '\n';
        }
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}
void GameCommand::DoRecoverInCenterCommand(Model &model, int pokemon_id, unsigned int stamina_points)
{
    if (model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        pokemon->StartRecoveringStamina(stamina_points);
        std::cout << "Recovering " << pokemon->GetPokemonName() << "\'s stamina\n";
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}

void GameCommand::DoGoCommand(Model &model, View &view)
{
    std::cout << "Advancing one tick.\n";
    model.Update();
    model.Display(view);
}
void GameCommand::DoRunCommand(Model &model, View &view)
{
    std::cout << "Advancing to next event.\n";
    model.Update();
    model.Display(view);
}