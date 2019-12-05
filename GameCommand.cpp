#include "GameCommand.h"

void GameCommand::DoMoveCommand(Model &model, int pokemon_id, Point2D p1)
{
    if (model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        std::cout << "Moving " << pokemon->GetPokemonName() << " to " << p1 << '\n';
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
        std::cout << "Moving " << pokemon->GetPokemonName() << " to center " << center_id << '\n';
        pokemon->StartMovingToCenter(pokemon_center);
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
        std::cout << "Moving " << pokemon->GetPokemonName() << " to gym " << gym_id << '\n';
        pokemon->StartMovingToGym(pokemon_gym);
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
        std::cout << "Stopping " << pokemon->GetPokemonName() << '\n';
        pokemon->Stop();
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

        std::cout << "Training " << pokemon->GetPokemonName() << '\n';

        pokemon->StartTraining(training_units);
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

        std::cout << "Recovering " << pokemon->GetPokemonName() << "\'s stamina\n";
        pokemon->StartRecoveringStamina(stamina_points);
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
    bool temp = false;
    std::cout << "Advancing to next event.\n";
    for (int i = 0; i < 5; i++)
    {
        temp = model.Update();
        model.Display(view);
        if (temp)
        {
            return;
        }
    }
}

void GameCommand::DoBattle(Model &model, int pokemon_id, int rival_id)
{
    if (model.GetPokemonPtr(pokemon_id) && model.GetRivalPtr(rival_id))
    {

        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        Rival *rival = model.GetRivalPtr(rival_id);
        pokemon->ReadyBattle(rival);
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}

void GameCommand::DoMoveToArenaCommand(Model &model, int pokemon_id, int arena_id)
{
    if (model.GetBattleArenaPtr(arena_id) && model.GetPokemonPtr(pokemon_id))
    {
        Pokemon *pokemon = model.GetPokemonPtr(pokemon_id);
        BattleArena *arena = model.GetBattleArenaPtr(arena_id);
        std::cout << "Moving " << pokemon->GetPokemonName() << " to arena " << arena_id << '\n';
        pokemon->StartMovingToArena(arena);
    }
    else
    {
        std::cout << "Error: Please enter a valid command!\n";
    }
}