#include "Building.h"
#include "GameCommand.h"
#include "GameObject.h"
#include "Model.h"
#include "Point2D.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Vector2D.h"
#include "View.h"
#include <iostream>
#include <ctime>

double GetRandomAmountOfPokemonDollars();
double GetDistanceBetween(Point2D p1, Point2D p2);
int main()
{
    srand(time(NULL));
    Model model;
    GameCommand game_command;
    View view;
    view.Clear();
    model.ShowStatus();
    model.Display(view);
    view.Draw();

    int id1;
    int id2;
    int stamina_amount;
    int unit_amount;

    double x;
    double y;

    char command;
    while (command != 'q')
    {
        std::cin >> command;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            switch (command)
            {
            case 'm':
                if (std::cin >> id1 && std::cin >> x && std::cin >> y)
                {
                    Point2D location(x, y);
                    game_command.DoMoveCommand(model, id1, location);
                    view.Draw();
                    break;
                }
                else
                {
                    break;
                }
            case 'g':
                if (std::cin >> id1 && std::cin >> id2)
                {
                    game_command.DoMoveToGymCommand(model, id1, id2);
                    break;
                }
                else
                {
                    break;
                }
            case 'c':
                if (std::cin >> id1 && std::cin >> id2)
                {
                    game_command.DoMoveToCenterCommand(model, id1, id2);
                    break;
                }
                else
                {
                    break;
                }
            case 's':
                if (std::cin >> id1)
                {
                    game_command.DoStopCommand(model, id1);
                    break;
                }
                else
                {
                    break;
                }
            case 'r':
                if (std::cin >> id1 && std::cin >> stamina_amount)
                {
                    game_command.DoRecoverInCenterCommand(model, id1, stamina_amount);
                    break;
                }
                else
                {
                    break;
                }
            case 't':
                if (std::cin >> id1 && std::cin >> unit_amount)
                {
                    game_command.DoTrainInGymCommand(model, id1, unit_amount);
                    break;
                }
                else
                {
                    break;
                }
            case 'v':
                game_command.DoGoCommand(model, view);
                view.Clear();
                model.ShowStatus();
                model.Display(view);
                view.Draw();
                break;
            case 'x':
                int temp = 0;
                while (temp < 5)
                {
                    if (model.Update())
                    {
                        break;
                    }
                    else
                    {
                        game_command.DoRunCommand(model, view);
                        view.Clear();
                        model.ShowStatus();
                        model.Display(view);
                        view.Draw();
                        temp++;
                    }
                }
                break;
            }
        }
    }
    return 0;
}

// double GetRandomAmountOfPokemonDollars()
// {

//     return rand() / (double)RAND_MAX / 2;
// }
// double GetDistanceBetween(Point2D p1, Point2D p2)
// {
//     return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
// }