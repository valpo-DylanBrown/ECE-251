#include <stdio.h>
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
}
