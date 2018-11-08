#include <stdio.h>

int main(){
  FILE *fp = NULL;
  int i, j;
  char inputCh = 0;
  char ch[500];
  fp = fopen("test.txt", "r");
  while((inputCh = fgetc(fp)) != EOF){
    //printf("%c", inputCh);
    ch[i]=inputCh;
    i++;
  }
  fclose(fp);
  fp = NULL;

  fp = fopen("test.txt", "a");
  for(j=0; j<=i;j++){
    fprintf(fp, "%c", ch[i-j]);
  }
  fclose(fp);
  fp = fopen("test.txt", "r");
  while((inputCh = fgetc(fp)) != EOF){
    printf("%c", inputCh);
  }
  printf("\n");
return 0;
}
