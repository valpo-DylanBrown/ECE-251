#include <stdio.h>
#include <math.h>
#include <time.h>

void arraySort(int array[], int n){
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
float calcMean(int array[], int n){
  float avg;
  int i;
  float sum;
  for (i=0; i<n; i++){
    sum+=array[i];
  }
  avg = sum/(n);
  return avg;
}
float calcMedian(int array[], n){
  float median = 0;

  if (n%2 == 0){
    median = ((array[(n-1)/2]+array[n/2])/2.0);
  }
  else {
    median = array[n/2];
  }

  return median;
}
float calcStdDev(int array[], float m, int n){
  float sum, stdDev;
  int i;
  printf("%f",m);
  for (i=0; i<n; i++){
    stdDev += pow((array[i]-m),2);
  }
  return sqrt(stdDev/(n-1));
}
int main(){
  srand(time(NULL));

  int arraySize;
  int i, j, n;
  float median = 0;
  float mean = 0;
  float standDev = 0;

  printf("Please enter the size of your random array: ");
  scanf("%d",&arraySize);

  int values[arraySize];

  for(i=0;i<arraySize;i++){
    values[i]=rand()%100+1;
  }

  arraySort(values, arraySize);
  median = calcMedian(values, arraySize);
  mean = calcMean(values, arraySize);
  standDev = calcStdDev(values, mean, arraySize);
  for(i=0;i<arraySize;i++){
    printf("Number #%d: %d\n", i, values[i]);
  }
  printf("The median of your array is %.2f.\n",median);
  printf("The mean of your array is %.2f.\n",mean);
  printf("The standard deviation of your array is %.2f.\n",standDev);


}
