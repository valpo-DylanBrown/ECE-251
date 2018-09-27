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
 int j;
 int wordFound=0;
 char temp[MAXLENGTH];
 //This section of the code reads the contents
 //of Dictionary1.txt into dictionary[][].
 freopen("./Dictionary1.txt", "r", stdin);
 for (i=0; i<NUMWORDS; i++) scanf("%s", &dictionary[i]);
 freopen("CON", "r", stdin);
 fflush(stdin);
 //End of file access section of the program.

 printf("Please enter a word, with unknown letters as '-':");
 scanf(" %s", &inputString);

 for (i=0; i<NUMWORDS; i++) //search through all words in the dictionary
 {
   if (strlen(inputString) == strlen(dictionary[i]))
   {
     strcpy(temp,inputString);
     for (j=0; j<=strlen(temp);j++)
     {
       if (temp[j] == '-'){
          temp[j] = dictionary[i][j];
       }
     }
     if(strcmp(dictionary[i],temp)==0)
    {
      printf("%s\n", dictionary[i]);
    }
    else{
      continue;
    }
   }
 }
 return 0;
}
