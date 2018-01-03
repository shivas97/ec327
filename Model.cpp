#include <iostream>
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
#include "Soldier.h"
#include <list>


using namespace std;

Model::Model()
{
  time = 0;
  Cart_Point thisminer1(5, 1);
  Cart_Point thisminer2(10, 1);
  Cart_Point goldMine1(1, 20);
  Cart_Point goldMine2(10, 20);
  Cart_Point townHall(0, 0);
  Cart_Point soldier3(5, 15);
  Cart_Point soldier4(10, 15);

  /*Game_Object* object_ptrs = new Game_Object[10];
  Person* person_ptrs = new Person[10];
  Gold_Mine* mine_ptrs = new Gold_Mine[10];
  Town_Hall* hall_ptrs = new Town_Hall[10];*/

  Miner* Miner1 = new Miner(1, thisminer1);
  //object_ptrs[0] = Miner1;
  //person_ptrs[0] = object_ptrs[0];

  Miner* Miner2 = new Miner(2, thisminer2);  //object_ptrs[1] = Miner2;
  //person_ptrs[1] = object_ptrs[1];

  Gold_Mine* GoldMine1 = new Gold_Mine(1, goldMine1);
  Gold_Mine* GoldMine2 = new Gold_Mine(2, goldMine2);
  Town_Hall* TownHall = new Town_Hall(1, townHall);
  Soldier* Soldier3 = new Soldier(3, soldier3);
  Soldier* Soldier4 = new Soldier(4, soldier4);
  /*Miner Miner1(1, Cart_Point(5,1));
  Miner Miner2(2, Cart_Point(10,1));
  Gold_Mine GoldMine1(1, Cart_Point(1,20));
  Gold_Mine GoldMine2(2, Cart_Point(10,20));
  Town_Hall TownHall;*/

  object_ptrs.push_back(Miner1);
  person_ptrs.push_back (Miner1);
  object_ptrs.push_back(Miner2);
  person_ptrs.push_back(Miner2);
  object_ptrs.push_back(GoldMine1);
  mine_ptrs.push_back(GoldMine1);
  object_ptrs.push_back(GoldMine2);
  mine_ptrs.push_back(GoldMine2);
  object_ptrs.push_back(TownHall);
  hall_ptrs.push_back(TownHall);
  object_ptrs.push_back(Soldier3);
  person_ptrs.push_back(Soldier3);
  object_ptrs.push_back(Soldier4);
  person_ptrs.push_back(Soldier4);

  active_ptrs.push_back(Miner1);
  active_ptrs.push_back(Miner2);
  active_ptrs.push_back(GoldMine1);
  active_ptrs.push_back(GoldMine2);
  active_ptrs.push_back(TownHall);
  active_ptrs.push_back(Soldier3);
  active_ptrs.push_back(Soldier4);

  cout << "Model constructed." << endl;
  /*num_objects = 7;
  num_persons = 4;
  num_objects = 5;
  num_persons = 2;
  num_mines = 2;
  num_halls = 1;*/
/*  for(list<Game_Object*>::iterator itperson = person_ptrs.begin(); itperson != person_ptrs.end(); itperson++)
  {
    //object_ptrs.push_back(<Game_Object>)

    //cout << "Model default constructed." << endl;
  }
  //for(itobject = object_ptrs.begin(); itobject != object_ptrs.end(); itobject++)
  for(itminer = miner_ptrs.begin(); itminer != miner_ptrs.end(); itminer++)
  {
    list<Game_Object*> (*itminer);
  }

  list<*Game_Object> (*hall_ptrs);
  active_ptrs = object_ptrs;

  cout << "Model default constructed." << endl;
}
*/
}
Model::~Model()
{
  for(list<Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++)
  {
    Game_Object *p = *it;
    delete p;
  }
  /*delete [] object_ptrs;
  delete [] person_ptrs;
  delete [] mine_ptrs;
  delete [] hall_ptrs;*/
  //for (int i = 0; i < num_objects; i++)
      //delete object_ptrs[i];

  /*for (int i = 0; i < num_persons; i++)
      delete person_ptrs[i];

  for(int i = 0; i < num_mines; i++)
      delete mine_ptrs[i];

  for(int i = 0; i < num_halls; i++)
      delete hall_ptrs[i];*/

  cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id)
{
for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); it++)
  {
      if((*it)->get_id() == id)
          return *it;
  }
  return 0;
}

Gold_Mine* Model::get_Gold_Mine_ptr(int id)
{
for(list<Gold_Mine*>::iterator it = mine_ptrs.begin(); it != mine_ptrs.end(); it++)
    {
      if((*it)->get_id() == id)
          return *it;
    }
  return 0;
}

Town_Hall* Model::get_Town_Hall_ptr(int id)
{
for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); it++)
    {
      if((*it)->get_id() == id)
          return *it;
    }
  return 0;
}

bool Model::update()
{
  time++;
  bool updated;
  for(list<Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++)
  {
    updated = (*it)->update();
    if(updated)
    {
      if(!((*it)->is_alive()))
      {
        active_ptrs.remove(*it);
      }
    }
  }
  return updated;

}

void Model::display(View &view)
{
  view.clear();
  for(list<Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); it++)
      {
        Game_Object *disp = *it;
        if(disp->is_alive())
        view.plot(disp);
      }
  //cout << "Time: " << time << endl;
  //cout << display_code << get_id() << endl;
  view.draw();
}

void Model::show_status()
{
  cout << "Time: " << time << endl;
  for(list<Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); it++)

  //cout << "Time: " << time << endl;
    {
      Game_Object *show_me = *it;
      show_me->show_status();
    }
}

void Model::handle_new_command(char type, int id, double x, double y)
{
  Cart_Point location(x,y);
  try{
    switch(type)
    {
      case 'g':
      {
        if (get_Gold_Mine_ptr(id) == 0)
          {
            Gold_Mine* my_mine = new Gold_Mine(id, location);

            mine_ptrs.push_back(my_mine);
            active_ptrs.push_back(my_mine);
            object_ptrs.push_back(my_mine);
          }
        else
          throw Invalid_Input("ID already exists!");

      }
      break;

      case 't':
      {
        if(get_Town_Hall_ptr(id) == 0)
          {
            Town_Hall *my_townhall = new Town_Hall(id, location);

            //mine_ptrs.push_back(my_townhall);
            active_ptrs.push_back(my_townhall);
            object_ptrs.push_back(my_townhall);
            hall_ptrs.push_back(my_townhall);
          }

        else
          throw Invalid_Input("ID already exists!");
      }
      break;

      case 'm':
      {
        if(get_Person_ptr(id) == 0)
          {
            Miner *my_miner = new Miner(id, location);

              active_ptrs.push_back(my_miner);
              object_ptrs.push_back(my_miner);
              person_ptrs.push_back(my_miner);
          }
        else
          throw Invalid_Input("ID already exists!");
      }
      break;

      case 's':
      {
        if(get_Person_ptr(id) == 0)
          {
            Soldier *my_soldier = new Soldier(id, location);

            active_ptrs.push_back(my_soldier);
            object_ptrs.push_back(my_soldier);
            person_ptrs.push_back(my_soldier);
          }

        else
          throw Invalid_Input("ID already exists!");
      }
      break;

      default:
      throw Invalid_Input("Command not found!");
      break;
    }
  }

  catch (Invalid_Input& except)
  {
    cout << "Invalid input - " << except.msg_ptr << endl;
  }
}
