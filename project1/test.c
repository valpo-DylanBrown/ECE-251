/* Program 2E Receiving Keyboard Input */
#include <stdio.h>
int numPeople;
int numPizzas;
int main(void)
{

 printf("Please enter the number of people: ");
 scanf("%d",&numPeople);
 printf("\nPlease enter the number of pizzas: ");
 scanf("%d",&numPizzas);
 printf("\nI had a party last night. %d people attended, and weshared %d pizzas.", numPeople, numPizzas);
 return 0;
}
