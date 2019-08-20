#include <iostream>
#include "Town_Hall.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

Town_Hall::Town_Hall():Game_Object('t',0,Cart_Point())
{
//  display_code = 't';
//  id_num = 0;
  state = 'o';
  amount = 0.0;
  //Cart_Point loc(0.0,0.0);
  //location = loc;
  cout << "Town_Hall default constructed." << endl;
}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc):Game_Object('t', inputId, inputLoc)
{
  //id_num = inputId;
  location = inputLoc;
  //display_code = 't';
  state = 'o';
  amount = 0.0;
  //Cart_Point loc(0.0,0.0);
  cout << "Town_Hall constructed." << endl;
}

/*Cart_Point Town_Hall::get_location()
{
  return Cart_Point location;
}*/

/*int Town_Hall::get_id()
{
  return get_id();
}*/

void Town_Hall::deposit_gold(double deposit_amount)
  {
    amount = amount + deposit_amount;
  }

bool Town_Hall::update()
{
  if (amount >= 50 && state != 'u')
  {
    state = 'u';
    display_code = 'T';

    cout << "Town_Hall (" << get_id() << ") has been upgraded." << endl;
    return true;
  }
  else
    {
      return false;
    }
}

void Town_Hall::show_status()
{
  cout << "Town Hall status: " << display_code << get_id() << " at " << location << " contains " << amount << " of gold. Not yet upgraded." << endl;
}

Town_Hall::~Town_Hall()
{
  cout << "Town_Hall destructed" << endl;
}
