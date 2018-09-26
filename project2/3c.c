/*ASSIGNMENT 3c*/

#include <stdio.h>
#include <math.h>

//#define PI 3.14159265359
#define SALESTAX 0.07

int main ()
{
	float a;
	float b;
	float c;
	float d;
	float e;
	float subtotal;
	float tax;
	float total;
	
	
	printf("Please enter the price of the first item (in dollars and cents: ");
	scanf("%f", &a);
	printf("Please enter the price of the second item (in dollars and cents: ");
	scanf("%f", &b);
	printf("Please enter the price of the third item (in dollars and cents: ");
	scanf("%f", &c);
	printf("Please enter the price of the fourth item (in dollars and cents: ");
	scanf("%f", &d);
	printf("Please enter the price of the fifth item (in dollars and cents: ");
	scanf("%f", &e);
	
	subtotal = a+b+c+d+e;
	tax = subtotal*SALESTAX;
	total = subtotal+tax;
	
	printf("===================\n");
	printf("===Sales Invoice===\n");
	printf("===================\n");
	
	printf("Item #1: %7.2f\n", a);
	printf("Item #2: %7.2f\n", b);
	printf("Item #3: %7.2f\n", c);
	printf("Item #4: %7.2f\n", d);
	printf("Item #5: %7.2f\n", e);
	printf("Subtotal: %6.2f\n",subtotal);
	printf("Tax: %11.2f\n", tax);
	printf("Total: %9.2f\n", total);
	
}