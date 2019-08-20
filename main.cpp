#include <iostream>
#include <string>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Game_Command.h"
#include "Town_Hall.h"
#include "Model.h"
#include "View.h"
#include "Person.h"
#include "Input_Handling.h"
using namespace std;

int main()
{
//  Model model;
//  View view;

  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2016" << endl;
  cout << "Programming Assignment 4" << endl;
  Model model;
  View view;
  char letter_command = 'l';

  while(letter_command != 'q')
  {
  //char letter_command;

    try
    {switch(letter_command)
        {
            case 'm':
            do_move_command(model);
            break;

            case 'w':
            do_work_command(model);
            break;

            case 's':
            do_stop_command(model);
            break;

            case 'g':
            do_go_command(model);
            break;

            case 'r':
            do_run_command(model);
            break;

            case 'l':
            do_list_command(model);
            break;

            case 'q':
            do_quit_command(model);
            break;

            case 'a':
            do_quit_command(model);
            break;

            case 'n':
            do_spawn_command(model);
            break;

            default:
              throw Invalid_Input("Command not valid");
          }
        }
          catch (Invalid_Input& except)
          {
            cout << "Invalid_Input - " << except.msg_ptr << endl;
          }
        model.display(view);
        cout << "Enter command: ";
        cin >> letter_command;
        //model.display(view);
  }
cout << "Terminating program." << endl;
return 0;
}
