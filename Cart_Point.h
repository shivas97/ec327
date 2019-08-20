#ifndef CART_POINT_H
#define	CART_POINT_H
#include <iostream>
#include "Cart_Vector.h"
#include <cmath>

//using namespace std;

//class Cart_Vector;

class Cart_Point
{

public:

  double y;
  double x;
  Cart_Point();
  Cart_Point(double inputx, double inputy);

};

std::ostream& operator<<(std::ostream& thingy, const Cart_Point& p1);

Cart_Point operator+(Cart_Point p1, Cart_Vector v1);

Cart_Vector operator-(Cart_Point p1, Cart_Point p2);

double cart_distance(Cart_Point p1, Cart_Point p2);



#endif
