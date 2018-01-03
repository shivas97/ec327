#ifndef CART_VECTOR_H
#define	CART_VECTOR_H

class Cart_Vector
{

public:

  double y;
  double x;
  Cart_Vector();
  Cart_Vector(double inputx, double inputy);

};

std::ostream& operator<<(std::ostream& thingy, const Cart_Vector& v1);

Cart_Vector operator/(Cart_Vector v1, double d);

Cart_Vector operator*(Cart_Vector v1, double d);

#endif
