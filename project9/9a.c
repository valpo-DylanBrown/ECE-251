#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void arraySort(int array[], int n){ //function to sort
  int i, j;
  int t=0;

  for (i=0; i<n; i++){
    for (j=0; j<n-1; j++){
      if(array[j]>array[j+1]){
        t=array[j];
        array[j]=array[j+1];
        array[j+1]=t;
      }
    }
  }
}
float calcMean(int array[], int n){ //function to calculate mean
  float avg;
  int i;
  float sum;
  for (i=0; i<n; i++){ //add every number in array
    sum+=array[i];
  }
  avg = sum/(n); //return average (MEAN)
  return avg;
}
float calcMedian(int array[], int n){ //function to calc median
  float median = 0;

  if (n%2 == 0){ //if n is a factor of 2
    median = ((array[(n-1)/2]+array[n/2])/2.0); //use the average of mid terms
  }
  else { //if n is NOT a factor of 2
    median = array[n/2]; //divide n by two
  }

  return median; //return median out
}
float calcStdDev(int array[], float m, int n){ //function to calc std dev
  float stdDev =0;
  int i;
  for (i=0; i<n; i++){ //calculate sigma(xi-xbar)^2
    stdDev += pow((array[i]-m),2);
  }
  return sqrt(stdDev/(n-1)); //return the sqrt(stdDev)/n-1(STD equation)
}
int main(){
  srand(time(NULL)); //seed rand

  int arraySize;
  int i, j, n;
  float median = 0;
  float mean = 0;
  float standDev = 0;

  printf("Please enter the size of your random array: ");
  scanf("%d",&arraySize);

  int values[arraySize]; //sets values to array of size arraySize

  for(i=0;i<arraySize;i++){ //sets random numbers to array
    values[i]=rand()%100+1;
  }

  arraySort(values, arraySize); //sort
  median = calcMedian(values, arraySize); //calc median
  mean = calcMean(values, arraySize); //calc mean
  standDev = calcStdDev(values, mean, arraySize); //calc stdDev
  /*for(i=0;i<arraySize;i++){
    printf("Number #%d: %d\n", i, values[i]);
  }*/
  //This shows numbers for manual debugging

  printf("The mean of your array is %.2f.\n",mean);
  printf("The median of your array is %.2f.\n",median);
  printf("The standard deviation of your array is %.2f.\n",standDev);

return 0;

}
