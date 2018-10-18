#include <stdio.h>
#include <math.h>

int sum();

int main(){
  int intA, intB;

  printf("Please enter your first number: ");
  scanf("%d", &intA);
  printf("Please enter your second number: ");
  scanf("%d", &intB);
  printf("Int A: Address= %p, Value= %i \n", &intA, intA);
  printf("Int B: Address= %p, Value= %i\n", &intB, intB);
  sum(intA,intB);
  return 0;
}

int sum(int a, int b){
  int sum;
  sum = a+b;
  printf("A: Address= %p, Value= %i \n", &a, a);
  printf("B: Address= %p, Value= %i \n", &b, b);
  printf("SUM: %d\n", sum);
  return sum;
}
