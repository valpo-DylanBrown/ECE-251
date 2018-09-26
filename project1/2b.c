/*ASSIGNMENT 2B*/

#include <stdio.h>

int main ()
{
	int fahren;
	
	printf("Please enter your temperature to the nearest degree Fahrenheit: ");
	
	scanf("%d", &fahren);
	int celsius;
	celsius = .556*(fahren-32);
	
	printf("That temperature corresponds to %d degrees Celsius.\n", celsius);
	
	return 0;
	
}