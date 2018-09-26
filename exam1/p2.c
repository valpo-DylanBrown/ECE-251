/*PROGRAM 2 CODE
Dylan Brown
ECE-251 EXAM
*/
#include <stdio.h>
#include <math.h>
/*DEFINITIONS */
#define PI 3.14159265 //PI CONSTANT
#define C 300000000 //SPEED OF LIGHT
/*MAIN*/
int main(){
  /*VARS */
  float transPow; //Pt
  float freq; //frequency
  float maxRange; //maxRange
  float recievedPowerWatts; //Pr
  float rpwToRpdbm; //Pr to dBm
  float gains = 2; //Gt and Gt
  float wavelength; //Wavelength lambda
  float i; //for loop iteration
  float stepSize; //stepping size
  //end vars
  printf("What is the power at the transmitter in Watts? ");
  scanf("%f", &transPow); // scans for user-input for Pt
  //printf("%f\n", transPow); //For debug
  printf("What is the carrier frequency in Hz? ");
  scanf("%f", &freq); //scans for user-input frequency
//  printf("%f\n", freq); // for debug
  printf("What is the maximum range in meters? ");
  scanf("%f", &maxRange); //scans for user-input maxmimum range
  //printf("%f\n", maxRange); // for debug
  wavelength = C/freq; //calculates wavelength for loop
  //printf("%f", wavelength); // for debug
  stepSize = maxRange/30; //sets stepping size for for loop
  printf("Range(m)\t  Pr[W]\t\t Pr[dBm]\n");
  for (i=stepSize;i<=maxRange;i+=stepSize){
    /*i increases by stepsize until max range*/
    recievedPowerWatts = ((transPow*gains*gains*pow(wavelength,2))/(pow((4*PI*i),2))); //calculates Pr
    rpwToRpdbm = 10*log10(recievedPowerWatts)+30; //converts Pr[W] to Pr[dBm]
    printf("%8.2f\t%8.4e\t%8.2f\n",i, recievedPowerWatts, rpwToRpdbm);
    //prints final values
  } //end for
  return 0;
} //end main
