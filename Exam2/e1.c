#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMWORDS 80368
#define MAXLENGTH 25
int main (int argc, char *argv[])
{
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

 if (player % 2 != 0){
   printf("Player 1\n");
   player1 = 1;
   n=1;
 }
 else if (player %2 ==0){
   printf("Player 2\n");
   player2 =1;
   n=2;
 }
 printf("POSSIBLE WORDS\n");
 printf("--------------------\n");
 for (i=0; i<NUMWORDS; i++) //search through all words in the dictionary
 {
   dictTemp = strlen(dictionary[i]);
   //printf("dict temp = %d\n", dictTemp);
   if (dictTemp % 2 == 0){
     //printf("DIVISBLE");
     dictCase = 1;
   }
   else if(dictTemp % 2 != 0){
     //printf("INDVISIBLE");
     dictCase = 0;
   }
   switch(n){
     case 1:
       if ((dictCase == 0) && (player1 = 1)){
         strcpy(temp, dictionary[i]);
         //printf("ENTERED");
         //printf("temp: %s\n", temp);
         for(j = 0; j<player;j++){
           //printf("ENTERED");
           //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
           if(temp[j] == argv[1][j]){
             //printf("ENTERED");
             //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
             if (j == (player-1)){
               //printf("entered\n");
               //printf("odd");
               printf(" %s\n", temp);
               wordsFound++;
             }
           }
           else{
             break;
           }
         }
       }
       break;
     case 2:
       if ((dictCase == 1) && (player2 = 1)){
         strcpy(temp, dictionary[i]);
         //printf("ENTERED");
         //printf("temp: %s\n", temp);
         for(j = 0; j<player;j++){
           //printf("ENTERED");
           //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
           if(temp[j] == argv[1][j]){
             //printf("ENTERED");
             //printf("temp: %c \t iS: %c\n", temp[j], argv[1][j]);
             if (j == (player-1)){
               //printf("entered\n");
               //printf("even");
               printf(" %s\n", temp);
               wordsFound++;
             }
           }
           else{
             break;
           }
         }
       }
       break;
      default:
        return 1;
        break;
   }
}
 printf("--------------------\n");
 printf("I found %d words to use.\nGoodbye!\n",wordsFound  );
 return 0;
}
