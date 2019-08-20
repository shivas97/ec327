#include <iostream>
#include <iomanip>
#include <cmath>
#include "View.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Miner.h"
#include "Gold_Mine.h"

using namespace std;


View::View()
{
    size = 11;
    scale = 2;
    origin = Cart_Point();

}

void View::clear()
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
      {
        grid[i][j][0] = '.';
        grid[i][j][1] = ' ';
      }
  }
}

void View::plot(Game_Object *ptr)
{
  int i, j;
  if(get_subscripts(i, j, ptr->get_location()))
    {
      {
 				if ((grid[i][j][1] == ' ') && (grid[i][j][0]=='.'))
 				{
 					ptr->drawself(grid[i][j]);
 				}
 				else
 				{
 					grid[i][j][1] =  ' ';
 					grid[i][j][0] = '*';
 				}
 			}
    }
}

void View::draw()
{
  int thisgrid = scale;
    for (int j = size - 1; j >= 0; j-- )
      {
        if ( j % thisgrid == 0)
          cout << setw(2) << left << scale * j;
          else
          cout << "  ";

          for (int i = 0; i < size; i++ )
            {
              cout << grid[i][j][0];
              cout << grid[i][j][1];

            }

          cout << endl;
      }

    cout << " ";
    for (int k = 0; k < size; k++)
      {
        if(k % thisgrid == 0)
          cout << setw(4) << left << scale * k;
      }
        cout << endl;
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
  ix = (location.x - origin.x) / scale;
  iy = (location.y - origin.y) / scale;

  //int ix = location_x;
  //int iy = location_y;

  if(ix < size && iy < size)
      return true;
  else
    cout << "An object is outside the display." << endl;
}
