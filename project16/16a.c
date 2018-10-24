#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringComp();
int tOrF=0;
int main(int argc, char *argv[]){
  /*int i;
  for(i =1; i<argc; i++){
    printf("Argument %d: %s\n", i, argv[i]);
  }*/
  stringComp(argv[1], argv[2]);
  if(tOrF == 1){
    printf("Good News, Everyone. The string \"%s\" and \"%s\" are the same!\n", argv[1], argv[2]);
  }
  else{
    printf("Good News, Everyone. The string \"%s\" and \"%s\" are NOT the same!\n",argv[1], argv[2]);
  }
  return 0;
}

int stringComp(char *s, char *d){
  if (strcmp(s,d) == 0){
    return tOrF = 1;
  }
  else{
      return tOrF = 0;
  }
}
