#include <stdio.h>
#include "libgeom.h"

int main(){
  float a, b, c;
  a = 1.2;
  b = 3.4;
  c = 5.6;
  printf("\nA triangle with sides %2.1f, %2.1f, %2.1f has ", a, b, c);
  printf("an area of %3.2f ", calcAreaTriangle(a, b, c));
  printf("and a perimeter of %3.2f.\n", calcPerimeterTriangle(a, b, c));
  printf("\nA rectangle with sides %2.1f, %2.1f has ", a, b);
  printf("an area of %3.2f ", calcAreaRectangle(a, b));
  printf("and a perimeter of %3.2f.\n", calcPerimeterRectangle(a, b));
  printf("\nA circle with radius %2.1f has ", a);
  printf("an area of %3.2f ", calcAreaCircle(a));
  printf("and a circumfrence of %3.2f.\n", calcPerimeterCircle(a));
}
