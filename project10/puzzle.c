/* Program I Word Search*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define WIDTH 21 //Need extra column to hold null character.
#define HEIGHT 20
int main (void)
{
   char puzzle[HEIGHT][WIDTH];
   char inputString[2*WIDTH];
   int i,j,k;
   int wordFound, rowFound, colFound;
   char possibleWord[2*WIDTH];

  //This section of the code reads the contents
  //of puzzle1.txt into puzzle[][].
   freopen("./Puzzle1.txt", "r", stdin);
   for (i=0; i<HEIGHT; i++) scanf("%s", &puzzle[i]);
   freopen("CON", "r", stdin);
   fflush(stdin);
  //End of file access section of the program.
  //print out initial puzzle
   for(i=0; i<HEIGHT; i++)
   {
     j=0;
      while(puzzle[i][j])
      {
         printf(" ");
         printf("%c", puzzle[i][j]);
         j++;
      }
      printf("\n");
   }
   //ask user for a word to find
   printf("\nPlease enter a word:");
   scanf("%s", &inputString);
   fflush(stdin);

   do
   {
     wordFound=0;
     //search for words horizontally
     for(i=0; i<HEIGHT; i++) //Loop through rows
       {
         for(j=0; j<WIDTH-strlen(inputString); j++) //Loop through columns.
       //(Don't run off right end of puzzle, so subtract word length from right edge.)
        {
          for(k=0; k<strlen(inputString); k++) //loop through length of input string.
         {
            possibleWord[k]=puzzle[i][j+k];
          }
          possibleWord[k]='\0';
          if(strcmp(possibleWord,inputString)==0)
          {
            printf("Word found! Row=%d Column=%d\n\n", i,j);
            wordFound=1;
            rowFound=i;
            colFound=j;
          }
        }
     }
     if(wordFound==0)
     {
      printf("Word not found.");
    }
    else
    {
      for(k=0; k<strlen(inputString); k++)
      {
        puzzle[rowFound][colFound+k]=toupper(puzzle[rowFound][colFound+k]);
      } //Make found word upper case
      //print out revised puzzle
      for(i=0; i<HEIGHT; i++)
      {
        j=0;
        while(puzzle[i][j])
        {
          printf(" ");
          printf("%c", puzzle[i][j]);
          j++;
        }
        printf("\n");
      }
    }
   printf("\nNext word (END to end)");
   scanf("%s", &inputString);
   fflush(stdin);
   } while (strcmp(inputString,"END")!=0);
   return 0;
 }
