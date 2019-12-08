#include <iostream>
#include <ios>
#include <ctime>
#include <limits>
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
#include "Input_Handling.h"

double GetRandomAmountOfPokemonDollars();
double GetDistanceBetween(Point2D p1, Point2D p2);

//functions for input
char get_command()
{
    char a;
    if (!(std::cin >> a))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw Invalid_Input("Please enter an a single character");
    }

    return a;
}
int get_int()
{
    int a;
    if (!(std::cin >> a))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw Invalid_Input("Please enter an integer");
    }
    return a;
}

double get_double()
{
    double a;
    if (!(std::cin >> a))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw Invalid_Input("Please enter a real number");
    }
    return a;
}

int main()
{
    std::cout << "EC327: Introduction to Software Engineering\n";
    std::cout << "Fall 2019\n";
    std::cout << "Programming Assignment 4\n";

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

    // //functions for input
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
        try
        {
            command = get_command();
            // try
            // {
            switch (command)
            {
            case 'm':
                game_command.DoMoveCommand(model, get_int(), Point2D(get_double(), get_double()));
                view.Draw();
                break;

            case 'g':

                game_command.DoMoveToGymCommand(model, get_int(), get_int());
                view.Draw();
                break;

            case 'c':

                game_command.DoMoveToCenterCommand(model, get_int(), get_int());
                view.Draw();
                break;

            case 's':

                game_command.DoStopCommand(model, get_int());
                view.Draw();
                break;

            case 'r':

                game_command.DoRecoverInCenterCommand(model, get_int(), get_int());
                view.Draw();
                break;

            case 't':

                game_command.DoTrainInGymCommand(model, get_int(), get_int());
                view.Draw();
                break;

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

                game_command.DoBattle(model, get_int(), get_int());
                view.Draw();
                break;

            case 'a':

                game_command.DoMoveToArenaCommand(model, get_int(), get_int());
                view.Draw();
                break;

            case 'q':
                break;
            default:
                std::cout << "Please enter a valid command\n";
                break;
            }
            // }
            // catch (Invalid_Input &except)
            // {
            //     std::cout << "Invalid input - " << except.msg_ptr << '\n';
            // }
        }
        catch (Invalid_Input &except)
        {
            std::cout << "Invalid input - " << except.msg_ptr << '\n';
            // std::cin.clear();
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        //switch the commands and call appropriate game commands. Certain commands also redraw the grid
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