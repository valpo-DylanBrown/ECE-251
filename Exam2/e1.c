#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMWORDS 80368
#define MAXLENGTH 25
int main (int argc, char *argv[])
{
  //start vars
 char dictionary[NUMWORDS][MAXLENGTH];
 int i;
 int j;
 int n;
 char temp[MAXLENGTH];
 int player1=0;
 int player2=0;
 int player = strlen(argv[1]);
 int dictTemp;
 int dictCase = 0;
 int wordsFound = 0;
 //end vars
 //This section of the code reads the contents
 //of Dictionary1.txt into dictionary[][].
 freopen("./Dictionary1.txt", "r", stdin);
 for (i=0; i<NUMWORDS; i++) scanf("%s", &dictionary[i]);
 freopen("CON", "r", stdin);
 fflush(stdin);
 //End of file access section of the program.

 /*for(i =1; i<argc; i++){
   printf("Argument %d: %s\n", i, argv[i]);
 }*/

 printf("Finding words that will fall on\n");

 if (player % 2 != 0){ //chooses player 1 when odd
   printf("Player 1\n");
   player1 = 1;
   n=1;
 }
 else if (player %2 ==0){ //chooses player 2 when even
   printf("Player 2\n");
   player2 =1;
   n=2;
 }
 printf("POSSIBLE WORDS\n");
 printf("--------------------\n");
 for (i=0; i<NUMWORDS; i++) //search through all words in the dictionary
 {
   dictTemp = strlen(dictionary[i]); // look for dictionary odd/even
   //printf("dict temp = %d\n", dictTemp);
   if (dictTemp % 2 == 0){ //choose even
     //printf("DIVISBLE");
     dictCase = 1;
   }
   else if(dictTemp % 2 != 0){ //choose odd
     //printf("INDVISIBLE");
     dictCase = 0;
   }
   switch(n){ //sets up cases for odd or even
     case 1: //odd
       if ((dictCase == 0) && (player1 = 1)){ //if dict case and player 1 is selected
         strcpy(temp, dictionary[i]); //copy temp string
         //printf("ENTERED");
         //printf("temp: %s\n", temp);
         for(j = 0; j<player;j++){ //loops letters
           //printf("ENTERED");
           //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
           if(temp[j] == argv[1][j]){ //if the letter are equal
             //printf("ENTERED");
             //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
             if (j == (player-1)){ // and the length is the same
               //and the characters are not a suffix
               if((strchr(temp, 'e') && strchr(temp, 'd')) || (strchr(temp, 'l') && strchr(temp, 'y')) || (strchr(temp, 'i') && strchr(temp, 'e'))) {
                 break;
               }
               else{ //print words and increment wordFound count
                 printf("%s\n", temp);
                 wordsFound++;
               }
             }
           }
           else{
             break; //if the letters are not equal break
           }
         } //end for loop
       } //end main if
       break; //end case
     case 2: //even
       if ((dictCase == 1) && (player2 = 1)){//if dict case and player 2 is selected
         strcpy(temp, dictionary[i]);//copy temp string
         //printf("ENTERED");
         //printf("temp: %s\n", temp);
         for(j = 0; j<player;j++){ //check letters
           //printf("ENTERED");
           //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
           if(temp[j] == argv[1][j]){ //if letters are the same
             //printf("ENTERED");
             //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
             if (j == (player-1)){ //and length is the same
               //and there are no suffixes
                 printf("%s\n", temp);
                 wordsFound++;
             } //end if
           } //end if
           else{
             break;
           }
         } //end for
       } //end main if
       break; //leave case
      default: //if neither odd or even
        return 1; //error
        break; //leave
   }
}
 printf("--------------------\n");
 printf("I found %d words to use.\nGoodbye!\n",wordsFound);
 return 0;
}
