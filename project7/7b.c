//7b
#include<stdio.h>
#include<math.h>

int main()
{
  int maxNum;
  int prime;
  int i,j;

  printf("How far do you want to search for prime numbers? ");
  scanf("%d", &maxNum);

  for (i = 1; i<=maxNum; i++) {
    prime = 1;
    for (j=2; j<=sqrt(i);j++){
      if(i % j == 0){
        prime = 0;
        break;
      }
    }
  if(prime==1){
    printf("%d is prime\n", i);
  }
  }
  return 0;
}
