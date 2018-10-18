/* AssignmentHangman*/ //wrong
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define NUMWORDS 80368
#define MAXLENGTH 25

int showHangman(int i)
{
  switch (i)
  {
    case 0 :
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("____________\n\n");
    break;

    case 1 :
    printf("\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    break;

    case 2 :
    printf("  _______\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    break;

    case 3 :
    printf("  _______\n");
    printf("  |/\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    break;

    case 4 :
    printf("  _______\n");
    printf("  |/ | \n");
    printf("  |  O \n");
    printf("  |\n");
    printf("  |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    break;
    case 5 :
    printf("  _______\n");
    printf("  |/ | \n");
    printf("  |  O \n");
    printf("  |  |\n");
    printf("  |  |\n");
    printf("  |\n");
    printf("__|_________\n\n");
    break;

    case 6 :
    printf("  _______\n");
    printf("  |/ | \n");
    printf("  |  O \n");
    printf("  | \\|\n");
    printf("  |  | \n");
    printf("  |\n");
    printf("__|_________\n\n");
    break;

    case 7 :
    printf("  _______\n");
    printf("  |/ | \n");
    printf("  |  O \n");
    printf("  | \\|/\n");
    printf("  |  | \n");
    printf("  |\n");
    printf("__|_________\n\n");
    break;

    case 8 :
    printf("  _______\n");
    printf("  |/ | \n");
    printf("  |  O \n");
    printf("  | \\|/\n");
    printf("  |  | \n");
    printf("  | /\n");
    printf("__|_________\n\n");
    break;

    case 9 :
    printf("  _______\n");
    printf("  |/ | \n");
    printf("  |  O \n");
    printf("  | \\|/\n");
    printf("  |  | \n");
    printf("  | / \\\n");
    printf("__|_________\n\n");
    break;

    case 10 :
    printf("  _______\n");
    printf("  |/ | \n");
    printf("  |  X \n");
    printf("  | \\|/\n");
    printf("  |  | \n");
    printf("  | / \\\n");
    printf("__|_________\n\n");
    break;
  }
}

int main(void)
{
  int wordNum=0;
  int i;
  char *randWord=NULL;
  char *guessWord=NULL;
  char dictionary[NUMWORDS][MAXLENGTH];
  char wrongLetters[10];
  int numErrors=0, numGuesses=0;
  char guessChar;
  int letterFound;

  //This section of the code reads the contents
  //of Dictionary1.txt into dictionary[][].
  freopen("./Dictionary1.txt", "r", stdin);
  for (i=0; i<NUMWORDS; i++) scanf("%s", &dictionary[i]);
  freopen("CON", "r", stdin);
  fflush(stdin);
  //End of file access section of the program.

  srand(time(NULL));
  wordNum=rand()%NUMWORDS+1;
  randWord=dictionary[wordNum];
  guessWord=malloc(strlen(randWord)*sizeof(char));

  for (i=0; i<strlen(randWord); i++)
  {
    *(guessWord+i)='-';
  }
  *(guessWord+i)='\0';

  /* Printing introduction message */
  printf("Welcome to Hangman!\n");
  printf("Your goal is to guess my random word\n");
  printf("Each time you guess a wrong letter, I add\n");
  printf("one more part to the picture.  If you make\n");
  printf("ten wrong guesses, you will lose.\n");
  printf("Here we go!\n\n\n");

  do{
    printf("Here is your current word: %s (dashes represent unknown letters)\n", guessWord);
	printf("Please enter your next guess:");
	guessChar=getchar();
	fflush(stdin);
	guessChar=tolower(guessChar);

    if(!isalpha(guessChar))
	{
	  printf("Sorry, only letters are allowed.\n\n");
	  continue;
	}

	letterFound=0;
    for (i=0; i< strlen(randWord); i++)
    {
      if ( *(randWord+i) == guessChar)
	  {
        *(guessWord+i) = guessChar;
		     letterFound=1;
      }
    }
	if (letterFound == 0)
	{
	   wrongLetters[numErrors]=guessChar;
      numErrors++;
      printf("\n**************************\n");
      printf("That letter was incorrect.\n");
      printf("**************************\n\n");
	} else {
      printf("\n**************************\n");
      printf("That letter was correct.\n");
      printf("**************************\n\n");
    }
	printf("Your current guess: %s\n", guessWord);

    showHangman(numErrors);
	printf("You have made %d errors so far (", numErrors);

	if(numErrors>0)
	{
      for (i=0; i<numErrors; i++)
	  {
	    printf("%c", wrongLetters[i]);
	  }
	}
	printf(")\n");
	numGuesses++;
   } while((strcmp(randWord,guessWord)!=0) && (numErrors<10));


    printf("\n**************************\n");
    printf("Game Over!.\n");
    printf("**************************\n");


    if(strcmp(randWord,guessWord)==0)
    {
      printf("Congratulations!  You guessed my word, which was %s.\n", randWord);
	  printf("It took you %d guesses, and you had %d incorrect guesses.", numGuesses, numErrors);
    }

	if (numErrors>=10)
	{
	  printf("Sorry, you lost.  You had 10 incorrect guesses out of %d.\n", numGuesses);
      printf("My secret word was %s.\n", randWord);
	}
  free(guessWord);
  return 0;
}
