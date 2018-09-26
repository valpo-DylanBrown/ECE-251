/*Program 4b*/

#include <stdio.h>

int main()
{
  /*begin var defs*/
  /*constants*/
  const int adultPrice = 12;
  const int childPrice = 7;
  /*ints*/
  int adultTickets;
  int childTickets;
  int ticketsSold;
  /*floats*/
  float avgPrice;
  /*end var defs*/

  printf("Please enter the number of adult tickets sold: ");
  scanf("%d", &adultTickets);
  printf("Please enter the number of child tickets sold: ");
  scanf("%d", &childTickets);

  ticketsSold = (adultPrice*adultTickets)+(childPrice*childTickets);
  avgPrice = (float)ticketsSold/(adultTickets+childTickets);

  printf("The total amount of money collected was: $%d \n", ticketsSold);
  printf("The average ticket price was: $%.2f \n", avgPrice);

  return 0;

}
