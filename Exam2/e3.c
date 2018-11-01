#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int gcd (int a, int b){ //LCM can be found using GCD
  if (a==0){ //if a = 0
    return b; //return b, which is the GCD
  }
  return gcd(b%a, a); //function is recursive, loops through until a == 0
}

int lcm(int a, int b, int c){ //calculates the LCM
  int math = a/c*b; //calculates (a*b)/c,where a&b are integers and c is the GCD
  return math; //returns the function
}

int main(int argc, char *argv[]){ //main function allocated to take in args
  /*int i; //the next 4 lines are for debugging arguments from CMD Line
  for(i =1; i<argc; i++){
    printf("Argument %d: %s\n", i, argv[i]);
  }*/
  int a,b; //creates two integers
  a = atoi(argv[1]); //sets string from arg to int
  b = atoi(argv[2]); //sets string from arg to int
  //printf("gcd of %d and %d = %d\n", a, b, gcd(a,b)); //debug gcd
  printf("The LCM of %d and %d = %d\n",a, b, lcm(a, b, gcd(a,b))); //print lcm

  return 0;
}
