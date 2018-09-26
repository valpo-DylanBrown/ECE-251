#include <stdio.h>

int main()
{
  int numRows;
  int i,j;


  printf("Please enter the amount of rows you want in your triangle: ");
  scanf("%d", &numRows);

  for(i =0; i<numRows; i++)
  {
    for(j=0; j < i+1; j++)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
