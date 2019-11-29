#include "Pokemon.h"
Pokemon::Pokemon()
{
    speed = 5;
    stamina = 20;
    std::cout << "Pokemon default constructed.\n";
}
Pokemon::Pokemon(char in_code)
{
    speed = 5;
    state = STOPPED;
    stamina = 20;
    display_code = in_code;
    std::cout << "Pokemon constructed.\n";
}

//update this
Pokemon::Pokemon(std::string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc) : GameObject(in_loc, in_id, 'P')
{
    name = in_name;
    speed = speed;
    health = hp;
    magical_damage = magic_dmg;
    defense = def;
}

Pokemon::Pokemon(std::string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    location = in_loc;
    id_num = in_id;
    speed = in_speed;
    name = in_name;
    stamina = 20;
    std::cout << "Pokemon constructed.\n";
}
void Pokemon::StartMoving(Point2D dest)
{
    //removing pokemon if leaving from gym or center. Also getting rid of the current_center and the current_gym
    SetupDestination(dest);
    if (state == IN_CENTER)
    {
        current_center->RemoveOnePokemon();
        current_center = NULL;
    }

    if (state == IN_GYM)
    {
        current_gym->RemoveOnePokemon();
        current_gym = NULL;
    }
    //checking to see if pokemon is already at destination
    if (!GetDistanceBetween(location, dest))
    {
        std::cout << this->display_code << this->id_num << ": I'm already there. See?\n";
    }
    else if (state == EXHAUSTED)
    {
        std::cout << this->display_code << this->id_num << ": I am exhausted. I may move but you cannot see me.\n";
    }
    else
    {
        state = MOVING;
        std::cout << this->display_code << this->id_num << ": On my way.\n";
    }
}
void Pokemon::StartMovingToCenter(PokemonCenter *center)
{
    //same as above
    if (state == IN_GYM)
    {
        current_gym->RemoveOnePokemon();
        current_gym = NULL;
    }
    if (state == IN_CENTER)
    {
        current_center->RemoveOnePokemon();
        current_center = NULL;
    }
    //adding the current_center
    current_center = center;

    SetupDestination(center->GetLocation());
    if (state == EXHAUSTED)
    {
        std::cout << display_code << id_num << ": I am exhausted so I can’t move to recover stamina…\n";
    }
    else if (!GetDistanceBetween(location, center->GetLocation()))
    {
        std::cout << display_code << id_num << ": I am already at the Pokemon Center!\n";
    }
    else
    {
        state = MOVING_TO_CENTER;
        std::cout << display_code << id_num << ": On my way to center " << center->GetId() << '\n';
    }
}
void Pokemon::StartMovingToGym(PokemonGym *gym)
{
    if (state == IN_GYM)
    {
        current_gym->RemoveOnePokemon();
        current_gym = NULL;
    }
    if (state == IN_CENTER)
    {
        current_center->RemoveOnePokemon();
        current_center = NULL;
    }

    current_gym = gym;

    SetupDestination(gym->GetLocation());
    if (state == EXHAUSTED)
    {
        std::cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the gym.\n";
    }
    else if (!GetDistanceBetween(location, gym->GetLocation()))
    {
        std::cout << display_code << id_num << ": I am already at the Pokemon Gym!\n";
    }
    else
    {
        state = MOVING_TO_GYM;
        std::cout << display_code << id_num << ": On my way to gym " << gym->GetId() << '\n';
    }
}
void Pokemon::StartTraining(unsigned int num_training_units)
{
    if (state == EXHAUSTED)
    {
        std::cout << display_code << id_num << ": I am exhausted so no more training for me...\n";
    }
    else if (state != IN_GYM)
    {
        std::cout << display_code << id_num << ": I can only train in a Pokemon Gym!\n";
    }
    else if (current_gym->IsBeaten())
    {
        std::cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already beaten!\n";
    }
    else if (stamina <= current_gym->GetStaminaCost(num_training_units) && pokemon_dollars <= current_gym->GetDollarCost(num_training_units))
    {
        std::cout << display_code << id_num << ": Not enough stamina and/or money for training\n";
    }
    else
    {
        state = TRAINING_IN_GYM;
        (num_training_units > current_gym->GetNumTrainingUnitsRemaining()) ? training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining() : training_units_to_buy = num_training_units;
        std::cout << display_code << id_num << ": Started " << num_training_units << " training unit(s) at Pokemon Gym " << current_gym->GetId() << '\n';
    }
}
void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
    if (state != IN_CENTER)
    {
        std::cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!\n";
    }
    else if (current_center->GetNumStaminaPointsRemaining() < 1)
    {
        std::cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center\n";
    }
    else if (pokemon_dollars < current_center->GetDollarCost(num_stamina_points))
    {
        std::cout << display_code << id_num << ": Not enough money to recover stamina.\n";
    }
    else
    {
        state = RECOVERING_STAMINA;
        stamina_points_to_buy = num_stamina_points;
        std::cout << display_code << id_num << " Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " << current_center->GetId() << ".\n";
    }
}
void Pokemon::Stop()
{
    state = STOPPED;
    std::cout << display_code << id_num << ":   Stopping...\n";
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
    switch (state)
    {
    case STOPPED:
        std::cout << " stopped\n";
        std::cout << "\tStamina: " << stamina << '\n';
        std::cout << "\tPokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "\tExperience Points: " << experience_points << '\n';
        break;
    case MOVING:
        std::cout << " moving at a speed of " << speed << " to " << destination << " at each step of " << delta << '\n';
        std::cout << "\tStamina: " << stamina << '\n';
        std::cout << "\tPokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "\tExperience Points: " << experience_points << '\n';
        break;
    case MOVING_TO_CENTER:
        std::cout << " heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << '\n';
        std::cout << "\tStamina: " << stamina << '\n';
        std::cout << "\tPokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "\tExperience Points: " << experience_points << '\n';
        break;

    case MOVING_TO_GYM:
        std::cout << " heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << '\n';
        std::cout << "\tStamina: " << stamina << '\n';
        std::cout << "\tPokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "\tExperience Points: " << experience_points << '\n';
        break;
    case IN_CENTER:
        std::cout << " inside Pokemon Center " << current_center->GetId() << '\n';
        std::cout << "\tStamina: " << stamina << '\n';
        std::cout << "\tPokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "\tExperience Points: " << experience_points << '\n';
        break;
    case IN_GYM:
        std::cout << " inside Pokemon Gym " << current_gym->GetId() << '\n';
        std::cout << "\tStamina: " << stamina << '\n';
        std::cout << "\tPokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "\tExperience Points: " << experience_points << '\n';
        break;
    case TRAINING_IN_GYM:
        std::cout << " training in Pokemon Gym " << current_gym->GetId() << '\n';
        break;

    case RECOVERING_STAMINA:
        std::cout << " recovering in Pokemon Center " << current_center->GetId() << '\n';
        break;
    case EXHAUSTED:
        std::cout << '\n';
        std::cout << "\tStamina: " << stamina << '\n';
        std::cout << "\tPokemon Dollars: " << pokemon_dollars << '\n';
        std::cout << "\tExperience Points: " << experience_points << '\n';
    }
}
bool Pokemon::Update()
{
    int temp;
    switch (state)
    {
    case EXHAUSTED:
        return false;
    case STOPPED:
        return false;
    case MOVING:

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
        UpdateLocation();
        if (!GetDistanceBetween(location, destination))
        {
            state = IN_CENTER;
            current_center->AddOnePokemon();
            return true;
        }
        else
        {
            return false;
        }
    case MOVING_TO_GYM:
        UpdateLocation();
        if (!GetDistanceBetween(location, destination))
        {
            state = IN_GYM;
            current_gym->AddOnePokemon();
            return true;
        }
        else
        {
            return false;
        }
    case IN_CENTER:

        return false;
    case IN_GYM:
        return false;
    case TRAINING_IN_GYM:
        temp = current_gym->TrainPokemon(training_units_to_buy);
        stamina -= current_gym->GetStaminaCost(training_units_to_buy);
        pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
        experience_points += temp;
        std::cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)! **\n";
        std::cout << "** " << name << " gained " << temp << " experience point(s)! **\n";
        state = IN_GYM;
        return true;
    case RECOVERING_STAMINA:
        temp = current_center->DistributeStamina(stamina_points_to_buy);
        stamina += temp;
        pokemon_dollars -= current_center->GetDollarCost(stamina_points_to_buy);
        std::cout << "** " << name << " recovered " << temp << " stamina point(s)! **\n";
        state = IN_CENTER;
        return true;
    case FAINTED:
        return false;
    case MOVING_TO_ARENA:
        if (!GetDistanceBetween(location, destination))
        {
            state = IN_ARENA;
            current_arena->AddOnePokemon();
            return true;
        }
        else
        {
            return false;
        }
    case BATTLE:
        //this will be the step after ReadyBattle() is called
        pokemon_dollars -= current_arena->GetDollarCost();
        stamina -= current_arena->GetStaminaCost();
        StartBattle();
        if (health > 0)
        {
            health += store_health;
            state = IN_ARENA;
            target->IsAlive();
        }
        else
        {
            state = FAINTED;
            target->IsAlive();
        }
    }
}
bool Pokemon::UpdateLocation()
{
    if (fabs(destination.x - location.x) <= fabs(delta.x) || fabs(destination.y - location.y) <= fabs(delta.y))
    {
        location = destination;
        std::cout << display_code << id_num << ": I’m there!\n";
        return true;
    }
    else
    {

        if (stamina == 0)
        {
            state = EXHAUSTED;
            std::cout << name << " is out of stamina and can't move.\n";
            return false;
        }
        else
        {
            location.x += delta.x;
            location.y += delta.y;
            stamina--;
            pokemon_dollars += GetRandomAmountOfPokemonDollars();
            std::cout << display_code << id_num << ": step...\n";
            return false;
        }
    }
}
void Pokemon::SetupDestination(Point2D dest)
{
    Vector2D temp(dest.x - location.x, dest.y - location.y);
    delta = temp * (speed / GetDistanceBetween(dest, location));
    destination = dest;
}

Pokemon::~Pokemon()
{
    std::cout << "Pokemon destructed.\n";
}
std::string Pokemon::GetPokemonName()
{
    return name;
}

double GetRandomAmountOfPokemonDollars()
{
    double randNum = rand() / ((double)RAND_MAX / 2);
    return randNum;
}

bool Pokemon::IsAlive()
{
    if (state == FAINTED)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense)
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

void Pokemon::ReadyBattle(Rival *in_target)
{
    if (state == IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars, stamina) && !current_arena->IsBeaten() && in_target->IsAlive())
    {
        target = in_target;
        state = BATTLE;
    }
    else
    {
        state = IN_ARENA;
    }
}
//call in battle state
bool Pokemon::StartBattle()
{
    while (health > 0 && target->get_health() > 0)
    {
        target->TakeHit(physical_damage, magical_damage, defense);
        TakeHit(target->get_phys_dmg(), target->get_magic_dmg, target->get_defense);
    }
}