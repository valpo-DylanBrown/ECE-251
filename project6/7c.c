#include <stdio.h>

int main()
{
  int maxNum;
  int i;
  float old;
  float new = 0;
  printf("How many numbers would you like to average?");
  scanf("%d", &maxNum);
  for(i=1; i<=maxNum; i++)
    {
      printf("What is number #%i? ",i);
      scanf("%f", &old);
      new += old;
      //printf("%f", new);
    }
    new /= maxNum;
    printf("The average of those %i numbers is %.3f.", maxNum, new);
}
