#include <stdio.h>

int main(){
  int array[10];
  int i;
  for(i=0; i<10;i++){
    array[i] = (i+1)*10;
    //printf("array: %d\n", array[i]);
  }
  int *pointer = array;

  for(i=0; i<10;i++){
    *(pointer+i) *= 2;
    //printf("pointer: %i\n", *(pointer+i));
  }
  for(i=0; i<10;i++){
    printf("Array Element #%d: Address=%p, Value= %i\n", i, (pointer+i), *(pointer+i));
  }
}
