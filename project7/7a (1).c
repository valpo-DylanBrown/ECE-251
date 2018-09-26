//Program 7b
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
  int i;
  int userInput;
  int number;
  int count=0;
  srand(time(NULL));
  number = rand()%100+1;



  while (1) {
    printf("What is your guess? ");
    scanf("%i", &userInput);
    count+=1;
    if (userInput == number)
      {
        printf("Congratulations, you got it on guess #%i", count);
        break;
      }
    else if (userInput < number)
      {
        printf("Higher, please.\n");
      }
    else if (userInput > number)
      {
        printf("Lower, please.\n");
      }
    else {
      printf("Please enter a number from 1-100.\n");
    }
  }

    return 0;
}
