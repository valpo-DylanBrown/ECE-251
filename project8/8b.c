/* PROGRAM 8b */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
  float radius;
  float circum;
  printf("Please enter a radius for your circle: ");
  scanf("%f", &radius);
  circum = 2*PI*radius;
  printf("The circumfrence of circle with radius %.2f is %.2f", radius, circum);
  return 0;
}
