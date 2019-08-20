#include <iostream>
#include "Cart_Point.h"
#include "Gold_Mine.h"
#include "Cart_Vector.h"
//#include "Cart_Point.h"
#include "Game_Object.h"


using namespace std;

Gold_Mine::Gold_Mine():Game_Object('G', 0, Cart_Point(0.0, 0.0))
  {
    state = 'f';
    amount = 100;
    cout << "Gold_Mine default constructed." << endl;
  }

Gold_Mine::Gold_Mine(int inputId, Cart_Point& inputLoc):Game_Object('G', inputId, inputLoc)
{

  //id_num = inputId;
  //location = inputLoc;
  //display_code = 'G';
  state = 'f';
  amount = 100;
  //Cart_Point location(0.0,0.0);
  //loc = location;
  cout << "Gold_Mine constructed." << endl;

}

/*Cart_Point Game_Object::get_location()
{
  return location;
}

int Gold_Mine::get_id()
{
  return id_num;
}*/

bool Gold_Mine::is_empty()
{

  if (amount > 0.0)
    return false;

  else
    return true;

}

double Gold_Mine::dig_gold(double amount_to_dig)
{

  if (amount >= amount_to_dig)
  {

    amount = amount - amount_to_dig;

    return amount_to_dig;

  }
  else
  {
    amount_to_dig = amount;
    amount = 0;
    return amount_to_dig;
  }
}

bool Gold_Mine::update()
{
  if (is_empty() && state != 'e')
  {
    state = 'e';
    display_code = 'g';
    cout << "Gold_Mine " << get_id() << " has been depleted" << endl;

    return true;
  }
  else
    return false;
}

void Gold_Mine::show_status()
{
  cout << "Gold Mine status: " << get_id() << " at location " << location << " Contains " << amount << "." << endl;
}

Gold_Mine::~Gold_Mine()
{
  cout << "Gold_Mine destructed" << endl;
}
