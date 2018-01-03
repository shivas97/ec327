#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"


using namespace std;


Game_Object::Game_Object(char in_code, int in_id)
{

  display_code = in_code;
  id_num = in_id;
  location = Cart_Point(0,0);

  cout << "Game_Object default constructed." << endl;

}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{

  display_code = in_code;
  id_num = in_id;
  location = in_loc;

  cout << "Game_Object constructed." << endl;

}

void Game_Object::drawself(char* pointer)
{

  pointer[0]=display_code;
	pointer[1]=char(id_num+48);

}

Cart_Point Game_Object::get_location()
{
  return location;
}

int Game_Object::get_id()
{
  return id_num;
}

void Game_Object::show_status()
{
  cout << "Miner status: " << display_code << get_id() << " at location " << location << endl;
}

Game_Object::~Game_Object()
{
  cout << "Game_Object destructed" << endl;
}

bool Game_Object::is_alive()
{
  return true;
}
