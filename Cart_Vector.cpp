#include <iostream>
#include "Cart_Vector.h"
#include <cmath>

using namespace std;

Cart_Vector::Cart_Vector()
{
     x = 0.0;
     y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)

{
   y = inputy;
   x = inputx;
}

std::ostream& operator<<(std::ostream& thingy, const Cart_Vector& v1)
{
   thingy << "<" << v1.x << "," << " " << v1.y << ">";
   return thingy;
}

 Cart_Vector operator*(Cart_Vector v1, double d)

 {
   Cart_Vector multi;
   multi.x = v1.x *d;
   multi.y = v1.y *d;

   //Cart_Vector omg3(v1.x * d, v1.y * d);
   //return omg3;
  return multi;

 }

 Cart_Vector operator/(Cart_Vector v1, double d)

 {
   if (d != 0.0)
    {
      Cart_Vector divides;
      divides.x = v1.x / d;
      divides.y = v1.y / d;

      return divides;
    }

  else
    {
      return v1;
    }

 }
