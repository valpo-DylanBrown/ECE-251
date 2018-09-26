/* Assignment 9a -- structured programming */

#include <stdio.h>


float calcTriangleArea(float x, float y)
{
  float result=0.5*x*y;
  return result;
}

int main()
{
  float width, height;
  int i = 1;

  printf("To stop computation, please enter a width or height of 0\n");

  while(1)
  {
    printf("Please enter triangle #%d's width: ", i);
    scanf("%f", &width);
    if(width == 0) {
		    break;
    }
    printf("Please enter triangle #%d's height: ", i);
    scanf("%f", &height);
    if(height == 0) {
      break;
    }
    printf("The area of triangle #%d is %2.3f\n",i ,calcTriangleArea(width, height));
    i++;
  }
  return 0;
}
