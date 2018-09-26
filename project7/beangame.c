#include <stdio.h>
#include <ctype.h>
int main (void)
{
 int counter=0;
 int inputNumber;
 int sum=21;
 int player=1;

 printf("This game begins with 21 beans. \n");
 printf("Each player can remove 1, 2, or 3 at a time.\n");
 printf("The goal is to remove the last bean.\n");

 while (sum > 0)
 {
 printf("-------\n");
 printf("Player %d, there are currently %d beans remaining. \n",player,sum);
 printf("How many do you want to take away?:");
  scanf("%d", &inputNumber);
  if(inputNumber<1 || inputNumber>3) {
  printf("You chose a bad number. I'll remove 3 beans.\n");
  inputNumber=3;
  }
  sum -= inputNumber;
  if(player==1) player=2;
  else player=1;
  } // Game is over.
  printf("-------\n");
  if(player==1) player=2; //must switch player back to declare winner.
  else player=1;

  printf("Good game! Player %d was the winner.", player);

  return 0;
 }
