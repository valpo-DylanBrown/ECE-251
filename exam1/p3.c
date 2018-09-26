/*PROGRAM 3 CODE
Dylan Brown
ECE-251 EXAM
*/
#include <stdio.h>
#include <math.h>

int main()  //main function
{
  int startNum; //starting number (user input)
  int prime; //variable to print primes
  char answer; //to check if user wants 5 more
  int i,j; //for loop iterators, i for main loop, j for primes
  int c = 1; //count for primes
  int iteration; //sets last prime to the main FOR loop, allows for new loops when prompted
  printf("Where would you like to start searching for prime numbers? ");
  scanf("%d",&startNum); //scans for start number
  iteration = startNum; //sets iteration to start number to begin
  while(1){ //while true
    for (i=iteration; c<=5; i++){ //starts at iteration, stops when c=5
      prime=1; //prime set to 1 default. NOT PRIME = 0
      for (j=2; j<=sqrt(iteration);j++){ //checks for primes
        if(i % j == 0){ //start if
          prime = 0; //prime set to zero if not prime
          break;
        } //end if
      } //end j for loop
    if(prime==1){ //if prime is equal to 1
      printf("%d is prime\n", i); //print that number
      c++; //increase count
      iteration = i; //set iteration again
      } //end if
    } //end i for loop
    if (c=5){ //if count is five
      printf("Would you like another five? (y/n) "); //prompt user for 5 more
      scanf(" %c", &answer); //scan input
      if (answer == 'y'){ //if user inputs 'y', show five more
        c=1; //set count to 1
        iteration++; //add one to the iteration to avoid repeats
        continue; //countine while(1)
      } //end if
      else if (answer == 'n'){ //if user answers 'n'
        printf("Thanks!"); //thank them
        break; //break while loop END
      } //end else if
      else{ //if user input != y or n
        printf("ERROR"); //print error
        return 1; //return error
      } //close else
    } //close if
  } //close while
  return 0;
}//close main
