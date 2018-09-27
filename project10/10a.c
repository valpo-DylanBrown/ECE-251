/* Program H Checking the dictionary for a word*/
#include <stdio.h>
#include <time.h>
#define NUMWORDS 80368
#define MAXLENGTH 25
int main (void)
{
 char dictionary[NUMWORDS][MAXLENGTH];
 char inputString[MAXLENGTH];
 int i;
 int wordFound=0;

 //This section of the code reads the contents
 //of Dictionary1.txt into dictionary[][].
 freopen("./Dictionary1.txt", "r", stdin);
 for (i=0; i<NUMWORDS; i++) scanf("%s", &dictionary[i]);
 freopen("CON", "r", stdin);
 fflush(stdin);
 //End of file access section of the program.

 printf("Please enter a word:");
 scanf(" %s", &inputString);

 for (i=0; i<NUMWORDS; i++) //search through all words in the dictionary
 {
 if(strcmp(dictionary[i],inputString)==0)
{
 wordFound=1;
 break;
}
 }

 if(wordFound==0)
 {
 printf("Sorry, that word is not in the dictionary.");
 } else {
 printf("Yes, that word is in the dictionary.");
 }
 re
