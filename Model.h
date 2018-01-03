#ifndef MODEL_H
#define MODEL_H
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Game_Command.h"
#include "Town_Hall.h"
#include "View.h"
#include "Person.h"
#include <list>

using namespace std;
class Model
{
  private:
    int time;
    /*Game_Object* object_ptrs[10];
    int num_objects;
    Person* person_ptrs[10];
    int num_persons;
    Gold_Mine* mine_ptrs[10];
    int num_mines;
    Town_Hall* hall_ptrs[10];
    int num_halls;*/
    list<Game_Object*>object_ptrs;
    list<Game_Object*>active_ptrs;
    list<Person*>person_ptrs;
    list<Town_Hall*>hall_ptrs;
    list<Gold_Mine*>mine_ptrs;

  public:
    Model();
    ~Model();
    Person* get_Person_ptr(int id);
    Gold_Mine* get_Gold_Mine_ptr(int id);
    Town_Hall* get_Town_Hall_ptr(int id);
    bool update();
    //Model::update();
    void display(View &view);
    void show_status();
    void handle_new_command(char, int, double, double);

};

#endif
