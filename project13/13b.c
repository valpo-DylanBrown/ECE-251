#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 10
int main(){
  int* array = (int*)malloc(ARRAYSIZE*sizeof(int));
  int i, j;
  int *pArray = NULL;
  pArray = array;

  for(i =0, j=100; i<ARRAYSIZE; ++i,j-=10){
    *(pArray+i)=j;
  }
  for(i=0; i<ARRAYSIZE; ++i){
    *(pArray+i) += 5;
  }
  for(i=0; i<ARRAYSIZE; ++i){
    if(*(pArray+i) > 70){
      *(pArray+i)*=-1;
    }
  }
  for(i=0; i<ARRAYSIZE; ++i){
    printf("Element #%d:, Address=%p, Value =%d\n", i, pArray+i, *(pArray+i));
  }
  return 0;
}
