/* PROGRAM 4A */

#include <stdio.h>

int main()
{
  int r1;
  int r2;
  float req;

  printf("Please enter the value for the first resistor: ");
  scanf("%d", &r1);
  printf("Please enter the value for the second resistor: ");
  scanf("%d", &r2);

  req = (float)(r1*r2)/(r1+r2);

  printf("The equivalent resistance is %.3f ohms", req);
  return 0;
}
