#include <stdio.h>
<<<<<<< HEAD
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
=======
#include <stdlib.h>

#define MAXLENGTH 30
#define FILENAME "books.txt"
#define ANSI_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"

struct book{
  char title[MAXLENGTH];
  char authorLast[MAXLENGTH];
  char authorFirst[MAXLENGTH];
  long int isbn;
  int onLoan;

};

int printbook(struct book book1);

int main(){
  struct book bookA, bookB, bookC, bookD;
  int numBooks;

  scanf("%d", &numBooks);
  scanf("%ld, %[a-zA-Z], %[a-zA-Z], %d, ", &bookA.isbn, bookA.authorLast, bookA.authorFirst, &bookA.onLoan);
  gets(bookA.title);
  scanf("%ld, %[a-zA-Z], %[a-zA-Z], %d, ", &bookB.isbn, bookB.authorLast, bookB.authorFirst, &bookB.onLoan);
  gets(bookB.title);
  scanf("%ld, %[a-zA-Z], %[a-zA-Z], %d, ", &bookC.isbn, bookC.authorLast, bookC.authorFirst, &bookC.onLoan);
  gets(bookC.title);
  scanf("%ld, %[a-zA-Z], %[a-zA-Z], %d, ", &bookD.isbn, bookD.authorLast, bookD.authorFirst, &bookD.onLoan);
  gets(bookD.title);
  /*
  printf("ISBN: %ld\n", bookA.isbn);
  printf("Last Name: %s\nFirst Name: %s\n", bookA.authorLast, bookA.authorFirst);
  printf("On Loan = %d\n", bookA.onLoan);
  printf("Title: %s\n", bookA.title);
  */
  printf("=========================================\n");
  printf("      Welcome to the Library System!   \n\n");
  printf("We have %d books on hand. They are: \n", numBooks);
  printbook(bookA);
  printbook(bookB);
  printbook(bookC);
  printbook(bookD);
  printf("=========================================\n");
  printf(" Thank you for using the library system! \n");
}
int printbook(struct book book1){
    static int i = 1;
    printf("Book #%d\n", i);
    printf("\"%s\" is written by %s %s.", book1.title, book1.authorFirst, book1.authorLast);
    if(book1.onLoan == 1){
      printf(ANSI_RED"The book is currently %s.\n"ANSI_RESET, book1.onLoan ? "on loan" : "available");
    }
    else{
      printf("The book is currently %s.\n", book1.onLoan ? "on loan" : "available");
    }
    i++;
    return 0;
>>>>>>> 1e686fd395f10441581e89db290923cf1504338a
}
