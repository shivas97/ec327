#ifndef SOLDIER_H
#define SOLDIER_H

#include "Cart_Point.h"
#include "Game_Object.h"
#include "Cart_Vector.h"
#include "Person.h"

class Soldier:public Person
{
private:
  int attack_strength;
  double range;
  Person *target;

public:
  void start_attack(Person *in_target);
  bool update();
  void show_status();
  ~Soldier();
  Soldier(int in_id, Cart_Point in_loc);
  Soldier();

};
#endif
