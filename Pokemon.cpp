#include "Pokemon.h"
Pokemon::Pokemon()
{
    speed = 5;
    std::cout << "Pokemon default constructed.\n";
}
Pokemon::Pokemon(char in_code)
{
    speed = 5;
    state = STOPPED;
    display_code = in_code;
    std::cout << "Pokemon constructed.\n";
}
Pokemon::Pokemon(std::string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
{
    speed = in_speed;
    name = in_name;
    std::cout << "Pokemon constructed.\n";
}
void Pokemon::StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if (!GetDistanceBetween(location, dest))
    {
        std::cout << display_code << ' ' << id_num << ": I'm already there. See?\n";
    }
    else if (state == EXHAUSTED)
    {
        std::cout << display_code << ' ' << id_num << ": I am exhausted. I may move but you cannot see me.\n";
    }
    else
    {
        state = MOVING;
        std::cout << display_code << ' ' << id_num << ": On my way.\n";
    }
}
void Pokemon::StartMovingToCenter(PokemonCenter *center)
{
    SetupDestination(center->GetLocation());
    if (state == EXHAUSTED)
    {
        std::cout << display_code << ' ' << id_num << ": I am exhausted so I can’t move to recover stamina…\n";
    }
    else if (!GetDistanceBetween(location, center->GetLocation()))
    {
        std::cout << display_code << ' ' << id_num << ":  I am already at the Pokemon Center!\n";
    }
    else
    {
        state = MOVING_TO_CENTER;
        std::cout << display_code << ' ' << id_num << ":  on my way to center " << center->GetId() << '\n';
    }
}
void Pokemon::StartMovingToGym(PokemonGym *gym)
{
    SetupDestination(gym->GetLocation());
    if (state == EXHAUSTED)
    {
        std::cout << display_code << ' ' << id_num << ": I am exhausted so I shouldn't be going to the gym.\n";
    }
    else if (!GetDistanceBetween(location, gym->GetLocation()))
    {
        std::cout << display_code << ' ' << id_num << ":  I am already at the Pokemon Gym!\n";
    }
    else
    {
        state = MOVING_TO_GYM;
        std::cout << display_code << ' ' << id_num << ":  On my way to gym " << gym->GetId() << '\n';
    }
}
void Pokemon::StartTraining(unsigned int num_training_units)
{
    if (state == EXHAUSTED)
    {
        std::cout << display_code << ' ' << id_num << ":  I am exhausted so no more training for me...\n";
    }
    else if (state != IN_GYM)
    {
        std::cout << display_code << ' ' << id_num << ":  I can only train in a Pokemon Gym!\n";
    }
    else if (current_gym->IsBeaten())
    {
        std::cout << display_code << ' ' << id_num << ":  Cannot train! This Pokemon Gym is already beaten!\n";
    }
    else if (stamina >= current_gym->GetStaminaCost(num_training_units) && pokemon_dollars >= current_gym->GetDollarCost(num_training_units))
    {
        std::cout << display_code << ' ' << id_num << ":  Not enough stamina and/or money for training\n";
    }
    else
    {
        state = TRAINING_IN_GYM;
        (num_training_units > current_gym->GetNumTrainingUnitsRemaining()) ? training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining() : training_units_to_buy = num_training_units;
        std::cout << display_code << " Started to train at Pokemon Gym " << current_gym->GetId() << " with " << num_training_units << " training units\n";
    }
}
void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
    if (state != IN_CENTER)
    {
        std::cout << display_code << ' ' << id_num << ":   I can only recover stamina at a Pokemon Center!\n";
    }
    else if (current_center->GetNumStaminaPointsRemaining() < 1)
    {
        std::cout << display_code << ' ' << id_num << ":   Cannot recover! No stamina points remaining in this Pokemon Center\n";
    }
    else if (pokemon_dollars < current_center->GetDollarCost(num_stamina_points))
    {
        std::cout << display_code << ' ' << id_num << ":   Not enough money to recover stamina.\n";
    }
    else
    {
        state = RECOVERING_STAMINA;
        std::cout << display_code << ' ' << id_num << " Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " << current_center->GetId() << ".\n";
    }
}
void Pokemon::Stop()
{
    state = STOPPED;
    std::cout << display_code << ' ' << id_num << ":   Stopping...\n";
}
bool Pokemon::IsExhausted()
{
    if (stamina == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pokemon::ShouldBeVisible()
{
    if (state == EXHAUSTED)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Pokemon::ShowStatus()
{
    std::cout << name << " status: ";
    GameObject::ShowStatus();
    Update();
}
bool Pokemon::Update()
{
    switch (state)
    {
    case STOPPED:
        std::cout << " stopped.\n";
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        return false;
    case MOVING:
        std::cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << '\n';
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        UpdateLocation();
        if (!GetDistanceBetween(location, destination))
        {
            state = STOPPED;
            return true;
        }
        else
        {
            return false;
        }
    case MOVING_TO_CENTER:
        std::cout << " heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << '\n';
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        if (!GetDistanceBetween(location, destination))
        {
            state = IN_CENTER;
            return true;
        }
        else
        {
            return false;
        }
    case MOVING_TO_GYM:
        std::cout << " heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << '\n';
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        if (!GetDistanceBetween(location, destination))
        {
            state = IN_GYM;
            return true;
        }
        else
        {
            return false;
        }
    case IN_CENTER:
        std::cout << " inside Pokemon Center " << current_center->GetId() << '\n';
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        return false;
    case IN_GYM:
        std::cout << " inside Pokemon Gym " << current_gym->GetId() << '\n';
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        return false;
    case TRAINING_IN_GYM:
        std::cout << " training in Pokemon Gym " << current_gym->GetId() << '\n';
        stamina -= current_gym->GetStaminaCost(training_units_to_buy);
        pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
        experience_points += current_gym->TrainPokemon(training_units_to_buy);
        std::cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)!**\n";
        std::cout << "** " << name << " gained " << current_gym->TrainPokemon(training_units_to_buy) << " experience point(s)! **\n";
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        state = IN_GYM;
        return true;
    case RECOVERING_STAMINA:
        std::cout << " recovering in Pokemon Center " << current_center->GetId() << '\n';
        stamina += current_center->DistributeStamina(stamina_points_to_buy);
        pokemon_dollars -= current_center->GetDollarCost(stamina_points_to_buy);
        std::cout << "** " << name << " recovered " << current_center->DistributeStamina(stamina_points_to_buy) << " stamina point(s)! **\n";
        std::cout << "Stamina: " << stamina << '\n';
        std::cout << "Pokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "Experience Points: " << experience_points << '\n';
        state = IN_CENTER;
        return true;
    }
}
bool Pokemon::UpdateLocation()
{
    if (fabs(destination.x - location.x) <= delta.x && fabs(destination.y - location.y) <= delta.y)
    {
        location = destination;
        std::cout << display_code << ' ' << id_num << " : I’m there!\n";
        return true;
    }
    else
    {
        location.x += delta.x;
        location.y += delta.y;
        std::cout << display_code << ' ' << id_num << " : step...\n";
        return false;
    }
}
void Pokemon::SetupDestination(Point2D dest)
{
    Vector2D temp(dest.x - location.x, dest.y - location.y);
    delta = temp * (speed / GetDistanceBetween(dest, location));
    destination = dest;
}