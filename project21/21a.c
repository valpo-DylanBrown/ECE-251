#include <stdio.h>
#include <time.h>
#include <windows.h>
int i, j;
int k;
void codeRain(){
  char a = 'a'+rand() % (('z'-'a')+1);
  char b = 'a'+rand() % (('z'-'a')+1);
  char c = 'a'+rand() % (('z'-'a')+1);
  k = rand() % 100;
  j = rand() % 100;
  printf("\t\t%i", j);
  printf("\t\t\t\t%c", a);
  printf("\t\t\t%c", b);
  printf("\t\t\t\t\t%c", a);
  printf("\t\t\t%i", j);
  printf("\t\t%i", k);
  printf("\t\t\t%c", b);
  printf("\t\t%i", j);
  printf("\t\t%c", c);
  printf("\t\t\t%i", j);
  printf("\t\t%c", a);
  printf("\t\t%c", c);
  printf("\t\t%i", j);
  printf("\t\t\t%c", b);
  printf("\t\t%i", j);
  printf("\t\t\t\t%c", a);
  return codeRain();
}

int main(){
  srand(time(NULL));

  int foreColor;
  int backColor;
  int color, red, blue, green, inten;
  HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

  printf("Please Choose a Foreground Color: \n");
  printf("Green = 1, Blue = 2, Red = 3 Random = 4\n");
  scanf("%d", &foreColor);
  if(foreColor==1){
    SetConsoleTextAttribute(screen, FOREGROUND_GREEN);}
  else if(foreColor==2){
    SetConsoleTextAttribute(screen, FOREGROUND_BLUE);}
  else if(foreColor==3){
    SetConsoleTextAttribute(screen, FOREGROUND_RED);}
  else if(foreColor==4){
    red = rand() % 2;
    blue = rand() % 2;
    green = rand() % 2;
    inten = rand() % 2;
    color=8*inten+4*red+2*green+1*blue;
    SetConsoleTextAttribute(screen, color);}

  codeRain();

  return 0;
}
