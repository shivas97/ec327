#include <iostream>
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"
using namespace std;

Cart_Point::Cart_Point()

  {
     x = 0.0;
     y = 0.0;
  }

Cart_Point::Cart_Point(double inputx, double inputy)

    {
      x = inputx;
      y = inputy;
    }

double cart_distance(Cart_Point p1, Cart_Point p2)

  {

    double dist_x = p2.x - p1.x;
    double dist_y = p2.y - p1.y;
    double cart_distance = sqrt(pow(dist_x, 2) + pow(dist_y, 2));

    return cart_distance;

  }

std::ostream& operator<<(std::ostream& thingy, const Cart_Point& p1)

  {
      thingy << '(' << p1.x << ',' << p1.y << ')';
      return thingy;
  }

Cart_Point operator+( Cart_Point p1, Cart_Vector v1)

  {
       Cart_Point omg(p1.x + v1.x, p1.y + v1.y);
       return omg;
  }

Cart_Vector operator-(Cart_Point p1, Cart_Point p2)

  {
      //return Cart_Vector(p1.x - p2.x, p1.y - p2.y);
      Cart_Vector omg2(p1.x - p2.x, p1.y - p2.y);
      return omg2;
  }
