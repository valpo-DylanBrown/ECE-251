/*ASSIGNMENT 3b*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main ()
{
	float a;
	float b;
	float x;
	float y;
	
	printf("Please enter the one side of your triangle (in inches): ");
	scanf("%f", &a);
	printf("Please enter another side of your triangle (in inches): ");
	scanf("%f", &b);
	printf("Please enter the angle between those two sides (in degrees): ");
	scanf("%f", &x);
	
	y = x*(PI/180);
	//printf("%f", y);
	
	printf("The area of your triangle is %.3f square inches", (.5*a*b*sin(y)));
	
}