#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int stringComp();
int tOrF=0;

int main(int argc, char *argv[]){
  int i=0;
  char temp1[100];
  char temp2[100];
  strcpy(temp1, argv[1]);
  strcpy(temp2, argv[2]);
  for (i = 0; i<strlen(temp1); i++){
    temp1[i] = toupper(temp1[i]);
  }
  for (i = 0; i<strlen(temp2); i++){
    temp2[i] = toupper(temp2[i]);
  }
  stringComp(temp1, temp2);
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
