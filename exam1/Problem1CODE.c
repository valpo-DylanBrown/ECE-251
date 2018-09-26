/*PROGRAM 1 CODE
Dylan Brown
ECE-251 EXAM
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
/*VARIABLES */
int sides;
char ch; //character for choice
int trials;
int i,j; //for loop iterators
int success = 0; //winning dice rolls
float percent;
int die1,die2,number;
int diceRolled;
/*FUNCTIONS */
int calcPercent(){ //function to calculate percent
  percent = (float)success/diceRolled*100;
  /*calculate percent per CHALLENEGE NEEDS EXPLICIT CASTING*/
  printf("In %d trials at advantage, %.2f%% succeeded over %d.\n", trials, percent, i);
  success=0; //set success back to zero for next CHALLENEGE
}
int advantage(){ //function for advantages
  srand(time(NULL)); //seed for random number
  for (i=2; i<=sides; i++){ //flip through CHALLENEGE numbers
    for (j=1; j<=diceRolled;j++){ //trials
      die1 = rand()%sides+1; //user dice roll
      die2 = rand()%sides+1;//user dice roll
      if (die1 >= die2){
        number = die1;
      }
      else if (die1 < die2){
        number = die2;
      }
      //printf("number = %d\n", number); //for success debug
      if (number >= i){ //if user dice roll is over CHALLENEGE,success+1
        success++; //winning rolls
        //printf("n = %d\n",success); //for percent debug
      }
    }
    calcPercent(); //call function
 }
}
int disadvantage(){ //function for disadvantages
  srand(time(NULL)); //seed for random number
  for (i=2; i<=sides; i++){ //flip through CHALLENEGE numbers
    for (j=1; j<=diceRolled;j++){ //trials
      die1 = rand()%sides+1; //user dice roll
      die2 = rand()%sides+1;//user dice roll
      if (die1 >= die2){
        number = die2;
      }
      else if (die1 < die2){
        number = die1;
      }
      //printf("number = %d\n", number); //for success debug
      if (number >= i){ //if user dice roll is over CHALLENEGE, success+1
        success++; //winning rolls
        //printf("n = %d\n",success); //for percent debug
      }
    }
    calcPercent(); //calls function
 }
}
/*MAIN */
int main()
{
  printf("How many sides are on your die? ");
  scanf("%d", &sides); //scan for # of sides
  printf("'a' for advantage 'd' for disadvantage? ");
  scanf(" %c", &ch); //scan for a or d
  printf("How many trials? ");
  scanf("%d", &trials); //scan for # of trials
  diceRolled = trials*(sides-1)*2; //calc diceRolled
  //printf("DICE ROLLED: %d\n", diceRolled); //debug diceRolled
  if (ch == 'a'){ //IF advantage chosen
    advantage(); //calls function
    printf("THANKS!"); //thank users before exit
  }
  if (ch == 'd'){ //IF advantage chosen
    disadvantage(); //calls function
    printf("THANKS!"); //thank users before exit
  }
  return 0;
}
