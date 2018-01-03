#include <iostream>
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
//#include <cmath>
#include <math.h>

using namespace std;

Person::Person():Game_Object('P', 0)
{

  speed = 0.0;

}

Person::Person(char in_code):Game_Object('P', 0)
{

  speed = 5.0;
  cout << "Person default constructed." << endl;
}

Person::Person(char in_code, int in_id, Cart_Point in_loc):Game_Object(in_code, in_id, in_loc)
{

  speed = 5.0;
  cout << "Person constructed." << endl;

}

void Person::start_moving(Cart_Point dest)
{
  if(state == 'x')
  {
    cout << "I'm dead." << endl;
    return;
  }

      setup_destination(dest);
      cout << "Moving " << get_id() << " to " << dest << ". " << endl;

    /*setup_destination(dest);
    state = 'm';*/
      if(dest.x == location.x && dest.y == location.y)
  //state = 'm';
      {
        state = 's';
        //cout << "Moving " << get_id() << " to " << dest << ". " << endl;
        cout << display_code << get_id() << ": Already there. See?" << endl;
      }else{
        state = 'm';
        //cout << "Moving " << get_id() << " to " << dest << ". " << endl;
        cout << display_code << get_id() << ": On my way." << endl;
      }
}

void Person::stop()
{

  state = 's';
  cout << "Stopping " << get_id() << ". " << display_code << get_id() << ": All right." << endl;

}

void Person::show_status()
{
  Game_Object::show_status();

  switch(state)
      {
        case 's':
          cout << "Stopped." << endl;
        break;

        case 'm':
          cout << "Moving at speed " << speed << " to " << destination << " amounts on each step are " << delta << endl;
          cout << "Miner is at location " << location << endl;
        break;

        case 'o':
          cout << "Outbound to a mine." << endl;
        break;

        case 'g':
          cout << "Getting gold from mine." << endl;
        break;

        /*case 'i':
        cout << "Inbound to home with load: " << amount << endl;

        break;*/

        case 'd':
          cout << "Depositing gold." << endl;
        break;
      }
}

bool Person::update_location()
{
  if( fabs((destination-location).x) <= fabs(delta.x) && fabs((destination-location).y) <= fabs(delta.y))

    {
		   location = destination;
		   cout << display_code << get_id() << ": I'm there!" << endl;

		   return true;
	  }

  else

    {
		  location = location + delta;
		  cout << display_code << get_id() << " : step..." << endl;

      return false;
	  }
}

void Person::setup_destination(Cart_Point dest)
{
  state = 'm';
  destination = dest;
  delta = (destination - location) * (speed / cart_distance(destination, location));
}

 Person::~Person()
 {
   cout << "Person destructed" << endl;
 }

void Person::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
  cout << "Sorry, I can't work a mine." << endl;
}

/*Person::Person()
{
  health = 5;
}*/

bool Person::is_alive()
{
  if (state == 'x')
    return false;
  else
    return true;
}

void Person::take_hit(int attack_strength)
{
  health = health - attack_strength;

  if(health <= 0)
  {
    cout << "Arrggh!" << endl;
    state = 'x';
  }

  else
    cout << "Ouch!" << endl;
}

void Person::start_attack(Person *target)
{
  if(state == 'x')
    cout << "I'm dead." << endl;
  else
    cout << "I can't attack." << endl;
}
