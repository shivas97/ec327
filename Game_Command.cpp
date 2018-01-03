#include <iostream>
#include "Game_Command.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Model.h"
#include "Person.h"

using namespace std;

void do_move_command(Model &model)
{
  int id, x, y;
  cin >> id >> x >> y;

  Cart_Point newlocation(x,y);
  Person* moves = model.get_Person_ptr(id);
  moves->start_moving(newlocation);

}

void do_work_command(Model &model)
{
  int id1, id2, id3;

  cin >> id1 >> id2 >> id3;

  Person* mines = model.get_Person_ptr(id1);

  Gold_Mine* goldmines = model.get_Gold_Mine_ptr(id2);

  Town_Hall* townhalls = model.get_Town_Hall_ptr(id3);

  mines->start_mining(goldmines, townhalls);
}

void do_stop_command(Model &model)
{
  int id;
  cin >> id;

  Person* moves = model.get_Person_ptr(id);
  //moves.stop(newlocation);
  moves->stop();
}


void do_go_command(Model &model)
{
  //do_list_command(model);
  bool returnthis = model.update();
  //do_list_command(model);
  //model.show_status();
  cout << "Advancing one tick." << endl;
  do_list_command(model);
  //cout << display_code << get_id() << ": I'm there!" << endl;
}

void do_run_command(Model &model)
{
  cout << "Advancing to next event." << endl;
  for(int i = 0; i < 5; i++)
  {
    bool returnthis = model.update();
    if(returnthis)
    {
      do_list_command(model);
      return;
    }

  }
  return;
}

void do_spawn_command(Model &model)
{
	char type;
	int id;
	double x, y;

	cin >> type >> id >> x >> y;

	model.handle_new_command(type, id, x, y);
}

void do_quit_command(Model &model)
{
  cout << "Terminating the program." << endl;
}

void do_list_command(Model &model)
{
  model.show_status();
}
