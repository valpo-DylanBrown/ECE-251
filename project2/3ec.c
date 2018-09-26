/*ASSIGNMENT 3 EXTRA CREDIT*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main ()
{
	float a;
	float b;
	float x;
	float y;
	float c;
	float s;
	float area;
	
	printf("Please enter the one side of your triangle (in inches): ");
	scanf("%f", &a);
	printf("Please enter another side of your triangle (in inches): ");
	scanf("%f", &b);
	printf("Please enter the angle between those two sides (in degrees): ");
	scanf("%f", &x);
	
	y = x*(PI/180);
	//printf("%f", y);
	c = sqrt(pow(a,2)+pow(b,2)-(2*a*b*cos(y)));
	s = .5*(a+b+c);
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	
	
	printf("The area of your triangle is %.6f square inches\n", (.5*a*b*sin(y)));
	printf("The area of your triangle using Heron's formula %.6f square inches", area);
	
}