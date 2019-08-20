#ifndef GOLD_MINE_H
#define GOLD_MINE_H
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"


class Gold_Mine:public Game_Object

{
  public:
    //Cart_Point get_location();
    //int get_id();
    bool is_empty();
    double dig_gold(double amount_to_dig);
    bool update();
    void show_status();
    Gold_Mine();
    Gold_Mine(int inputId, Cart_Point& inputLoc);
    virtual ~Gold_Mine();

  private:
    double amount;
};

#endif
