#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int memSize = 10;
  int i;
  int *pStart;
  int *pointer;

  pStart = malloc(memSize*sizeof(int));
  pointer = pStart;

  for(i=0; i<memSize;i++){
    *(pointer+i) = pow(2,i);
  }
  pStart = realloc(pStart, 2*memSize*sizeof(int));
  pointer = pStart;
  for (i=memSize; i<2*memSize; i++){
    *(pointer+i)= pow(2,i);
  }

  for(i=0; i<2*memSize; i++){
  printf("Element#%d: Address:%#p Value:%d\n", i, pointer+i, *(pointer+i));
  }
  return 0;
}
