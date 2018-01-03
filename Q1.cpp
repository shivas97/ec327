#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

double cx1;
double cy1;
double cx2;
double cy2;
double cx3;
double cy3;

double rise;
double run;
double slope;

double a;
double b;
double c;

double num;
double denom;
double totaldistance;

int main()

{

cout << "Please enter three (x,y) coordinates: " << endl; //prompt user to enter 6 numbers (3 coordinates)
cin >> cx1 >> cy1 >> cx2 >> cy2 >> cx3 >> cy3;

rise = cy2 - cy1; //calculates rise for slope
run = cx2 - cx1; //calculates run for slope
slope = rise/run; //slope=rise/run

a = rise * cx3; //multiply rise with 3rd x-coordinate
b = run * cy3; //multiply run with 3rd y-coordinate
c = (cx2 * cy1) - (cy2 * cx1); //c is value of the difference of product of other 2 coordinates

num = (abs(a - b + c)); // according to wiki, this equation is in the numerator
denom = sqrt((pow(rise,2))+(pow(run,2))); // according to wiki, this equation is in the denominator


totaldistance = num/denom; //total distance is quotient


cout << "The shortest distance for" "(" << cx3 << "," << cy3 << ")" "to the line composed of" "(" << cx1 << "," << cy1 << ")" "and" "(" << cx2 << "," << cy2 << ")" "is" << totaldistance << endl; // print out distance


return 0;

}
