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
    *pointer = pow(2,i);
    printf("Element#%d: Address:%#p, Value:%d\n", i,pointer, *pointer);
    pointer++;
  }
  pStart = realloc(pStart, 2*memSize*sizeof(int));
  pointer = pStart;
  for (i=memSize; i<2*memSize; i++){
    *pointer= pow(2,i);
    printf("Element#%d: Address:%#p, Value:%d\n", i, pointer, *pointer);
    pointer++;
  }
  /*
  for(i=0; i<2*memSize; i++){
  printf("Element#%d: Address:%#p Value:%d\n", i, pointer);
  pointer++; //Move pointer to next location.
  }
  */
}
