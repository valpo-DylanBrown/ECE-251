#include <stdio.h>
#include <math.h>

int nextFibTerm();

int main(){
  int firstTerm = 0;
  int secondTerm = 1;
  printf("%i, %i, ", firstTerm, secondTerm);
  nextFibTerm(firstTerm, secondTerm);
  return 0;
}
int nextFibTerm(int a, int b){
  int temp;
  int i=1;
  while(b <= 100000){
    temp = b+a;
    a = b;
    b = temp;
    ++i;
    printf("%i, ", b);
    if (i==16 || i==26){
      printf("\n");
    }
  }
  return 0;
}
