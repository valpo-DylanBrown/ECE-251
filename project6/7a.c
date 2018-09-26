#include <stdio.h>

int main()
{
  int val = 1;
  int i;
  int sum;


  for (i=0; i<50; i+=2){
    sum = val+i;
    printf("%i,", sum);
  }
  return 0;
}
