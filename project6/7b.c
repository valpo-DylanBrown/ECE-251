#include <stdio.h>

int main()
{
  //int val
  int i;
  int sum = 0;
  int maxNum;
  printf("Please enter the end rnage  you want to sum: ");
  scanf("%d", &maxNum);
  for (i=0; i<=maxNum; i+=2){
    sum += i;
  }
  printf("The sum from 1 to %i is %i. \n", maxNum, sum);
  return 0;
}
