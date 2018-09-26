/*Program 4c*/

#include <stdio.h>

int main()
{
  /*begin var defs*/
  /*ints*/
  int daysSince;
  int age;
  /*end var defs*/

  printf("Please enter your age at your last birthday: ");
  scanf("%d", &age);
  printf("Please enter the number of days since your last birthday: ");
  scanf("%d", &daysSince);

  age *= 365;
  age += daysSince;
  printf("You have lived %d days\n", age);

  age *= 24;
  printf("You have lived %d hours\n", age);

  age *= 60;
  printf("You have lived %d minutes\n", age);

  age *= 60;
  printf("You have lived %d seconds\n", age);



  return 0;

}
