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
    std::cout << "EC327: Introduction to Software Engineering\n";
    std::cout << "Fall 2019\n";
    std::cout << "Programming Assignment 3\n";

    std::cout << "                                  ,'\\ \n";
    std::cout << "   _.----.        ____         ,'  _\\   ___    ___     ____ \n";
    std::cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. \n";
    std::cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | \n";
    std::cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | \n";
    std::cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | \n";
    std::cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | \n";
    std::cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | \n";
    std::cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | \n";
    std::cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | \n";
    std::cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | \n";
    std::cout << "                                `'                            '-._| \n";

    //set srand to time
    srand(time(NULL));

    //initialize the classes
    Model model;
    GameCommand game_command;
    View view;

    //showing initial status view
    view.Clear();
    model.ShowStatus();
    model.Display(view);
    view.Draw();

    //variables for input
    int id1;
    int id2;
    int stamina_amount;
    int unit_amount;

    double x;
    double y;

    char command;

    //looping for continuous inputs
    while (command != 'q')
    {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (std::cin.fail())
        {
            std::cout << "Please enter a valid command\n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        //switch the commands and call appropriate game commands. Certain commands also redraw the grid
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
                    view.Draw();
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
                    view.Draw();
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
                    view.Draw();
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
                    view.Draw();
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
                    view.Draw();
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
                game_command.DoRunCommand(model, view);
                view.Clear();
                model.ShowStatus();
                model.Display(view);
                view.Draw();
                break;
            case 'b':
                //battle case set up
            case 'q':
                break;
            default:
                std::cout << "Please enter a valid command\n";
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