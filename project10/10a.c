/* Program H Checking the dictionary for a word*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMWORDS 80368
#define MAXLENGTH 25
int main (void)
{
 char dictionary[NUMWORDS][MAXLENGTH];
 char inputString[MAXLENGTH];
 int i;
 int wordFound=0;
 float percent;
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
 }
 else {
   percent = (float)i/NUMWORDS*100;
   printf("Yes, that word is in the dictionary.\n");
   printf("It is number #%i out of %d\n",(i+1), NUMWORDS);
   printf("That is %.2f%% of the way through the dictionary\n",percent);
   printf("The word before it is \"%s\"\n",dictionary[i-1]);
   printf("The word after it is \"%s\"\n",dictionary[i+1]);
 }
}
