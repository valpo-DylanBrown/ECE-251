/*ASSIGNMENT 3a*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main ()
{
	int radius;
	int n1 = 3;
	int n2 = 4;
	int n3 = 5;
	int n4 = 6;
	int n5 = 10;
	int n6 = 20;
	int n7 = 30;
	
	
	printf("Please enter the radius of your circle: ");
	scanf("%d", &radius);
	printf("The area of a polygon with %d sideswith radius %d is %.2f \n", n1, radius, (.5*(n1*sin((2*PI)/n1))*pow(radius, 2)));
	printf("The area of a polygon with %d sideswith radius %d is %.2f \n", n2, radius, (.5*(n2*sin((2*PI)/n2))*pow(radius, 2)));
	printf("The area of a polygon with %d sideswith radius %d is %.2f \n", n3, radius, (.5*(n3*sin((2*PI)/n3))*pow(radius, 2)));
	printf("The area of a polygon with %d sideswith radius %d is %.2f \n", n4, radius, (.5*(n4*sin((2*PI)/n4))*pow(radius, 2)));
	printf("The area of a polygon with %d sideswith radius %d is %.2f \n", n5, radius, (.5*(n5*sin((2*PI)/n5))*pow(radius, 2)));
	printf("The area of a polygon with %d sideswith radius %d is %.2f \n", n6, radius, (.5*(n6*sin((2*PI)/n6))*pow(radius, 2)));
	printf("The area of a polygon with %d sideswith radius %d is %.2f \n", n7, radius, (.5*(n7*sin((2*PI)/n7))*pow(radius, 2)));
	printf("The area of a circle of radius %d is %.2f", radius, PI*pow(radius,2));
}




