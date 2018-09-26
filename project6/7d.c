#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
  int i;
  int userInput;
  int number;
  number = rand()%100+1;

  srand(time(NULL));
  for(i=1; ;i++ )
    {
      printf("What is your guess? ");
      scanf("%i", &userInput);
      if (userInput == number)
        {
          printf("Congratulations, you got it on guess #%i", i);
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
