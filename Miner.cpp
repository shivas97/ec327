#include <iostream>
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Miner.h"
//#include "Model.h"
#include <math.h>

using namespace std;

Miner::Miner():Person('M')
{
  amount = 0;
  mine = NULL;
  home = NULL;
  state = 's';
  cout << "Miner default constructed." << endl;
}

Miner::Miner(int in_id, Cart_Point in_loc):Person('M', in_id, in_loc)
{
  amount = 0;
  mine = NULL;
  home = NULL;
  state = 's';
  cout << "Miner constructed." << endl;
}

bool Miner::update()
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
      //bool value = update_location();
      value = update_location();
      if(value)
      {
        state = 's';
        //return value;
      }
      return value;
      break;

    case 'o':
      value = update_location();
      if(value)
      {
        state = 'g';
      }
      return value;
      break;

    case 'g':
      amount = mine -> dig_gold(35.0);

      cout << display_code << get_id() << ": Got " << amount << " gold." << endl;

      setup_destination(home->get_location());

      state = 'i';
        return true;
        break;

    case 'i':
        value = update_location();
        if (value)
        {
          state = 'd';
          //return true;
        }
        //cout << "Inbound to home with load: " << amount << endl;
        return value;
        break;

      case 'd':
        cout << display_code << get_id() << ": Deposit " << amount << "of gold." << endl;

        home->deposit_gold(amount);
          amount = 0.0;
          if (mine->is_empty())
            {
              state = 's';
              cout << display_code << get_id() << " More work?" << endl;
              return true;
            }
          else
            {
              setup_destination(mine->get_location());
              state = 'o';
              cout << display_code << get_id() << " Going back for more." << endl;
              return true;
            }
  }
}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
  state = 'o';
  mine = inputMine;
  home = inputHome;

  cout << "Miner " << get_id() << " mining at Gold_Mine " << mine->get_id() << " and depositing at Town_hall. " << home->get_id() << endl;
  cout << display_code << get_id() << ": Yes, my lord." << endl;

  setup_destination(mine->get_location());
}

void Miner::show_status()
{
  cout << display_code << get_id() << endl;
	Person::show_status();
  //cout << display_code << get_id() << endl;
	switch(state)
  {
    case 'o':
      cout << "Outbound to a mine." << endl;
    break;

    case 'g':
      cout << "Getting gold from mine." << endl;
    break;

    case 'i':
    cout << "Inbound to home with load: " << amount << endl;
    break;

    case 'd':
      cout << "Depositing gold." << endl;
    break;
  }
}
Cart_Point Miner::get_location()
{
  cout << "Miner status:" << endl;
  Person::show_status();
  return location;
}

Miner::~Miner()
{
  cout << "Miner destructed." << endl;
}
