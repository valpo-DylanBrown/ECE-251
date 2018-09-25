#include <stdio.h>
#include <math.h>

#define E0 8.854e-12
#define PI 3.1415926

int main()
{
  const float q = 0.01e-9;
  const int numRows = 9;
  const int numCols = 9;
  int i,j;
  float distance;
  float eField[numRows][numCols];

  for(i=0; i<numRows; i++){
    for(j=0; j<numCols; j++){
      distance = sqrt(pow((0.04-(0.01*i)),2)+pow((0.04-(0.01*j)),2));
      eField[i][j]=q/(4*PI*E0*pow(distance,2));
      if (distance == 0){
        printf(" ----  ");
      }
      else {
        printf("%5.1f ",eField[i][j]);
      }
    }
    printf("\n");
  }
return 0;
}
