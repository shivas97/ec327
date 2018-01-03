#include <iostream>
#include "Soldier.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Cart_Vector.h"
#include "Person.h"

using namespace std;

void Soldier::start_attack(Person *in_target)
{
  double mydistance;
  mydistance = cart_distance(get_location(), in_target->get_location());

  if (mydistance <= range)
  {
    cout << "Clang!" << endl;

    state = 'a';

    target = in_target;

  }

  else
    cout << "Target is out of range!" << endl;

}

bool Soldier::update()
{
  bool value;
  switch(state)
  {
    case 'x':
      return false;
    break;

    case 's':
      return false;
    break;

    case 'm':
      value = update_location();
      if(value)
        {
          state = 's';
          //return value;
        }
      return false;
    break;

    case 'a':
    double mydistance;
    mydistance = cart_distance(get_location(),target->get_location());

      if (mydistance <= range)
        {
          cout << "Out of range" << endl;
          state = 's';
          return true;
        }
      else
      {
        if(is_alive())
        {
          cout << "Clang!" << endl;
          target->take_hit(attack_strength);
          return false;
        }
        else
        {
          cout << "I triumph!" << endl;
          state = 's';
          return true;
        }
      }

  }
}

void Soldier::show_status()
{
  cout << "Soldier status: " << endl;

  Person::show_status();

  if(state == 'a')
    cout << "Attacking." << endl;
  else
    cout << "Not attacking." << endl;
}

Soldier::Soldier():Person('S')
{
  attack_strength = 2;
  range = 2;
  state = 's';
  cout << "Soldier default constructed." << endl;
}

Soldier::Soldier(int in_id, Cart_Point in_loc):Person('S', in_id, in_loc)
{
  attack_strength = 2;
  range = 2;
  state = 's';

  cout << "Soldier constructed." << endl;
}

Soldier::~Soldier()
{
  cout << "Soldier destructed." << endl;
}
