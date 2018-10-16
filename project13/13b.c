#include <stdio.h>
#include <stdlib.h>

int main(){
  int memSize = 10;
  int i;
  int *pStart;
  int *pointer;

  pStart = malloc(memSize*sizeof(int));
  pointer = pStart;

  for(i=10; i>0;i--){
    *pointer = i*10;
    printf("Element#%d: Value:%d\n", 10-i, *pointer);
    //pointer++;
  }
  int *pointer2 = pointer;
  //printf("Pointer 1: %p\nPointer 2: %p\n", pointer, pointer2);

  for(i=0; i<10; i++){
    printf("%i\n", *(pointer2+i));
  }


}
