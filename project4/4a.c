/* PROGRAM 4a */
#include <stdio.h>

int main()
{
	int myFeet = 6;
	int myInches = 0;
	int uFeet;
	int uInches;
	
	printf("Please enter the feet for your height: ");
	scanf("%d", &uFeet);
	printf("Please enter the inches for your height: ");
	scanf("%d", &uInches);
	
	if (uFeet<myFeet){
		printf("You are shorter then me, my height is %d feet %d inches", myFeet, myInches);
	}
	else if (uFeet==myFeet){
		if (uInches<myInches){
			printf("You are shorter then me, my height is %d feet %d inches", myFeet, myInches);
		}
		else if(uInches==myInches){
			printf("We are the same height (%d feet %d inches)",myFeet, myInches);
		}
		else {
			printf("You are taller then me, my height is %d feet %d inches", myFeet, myInches);
		}
	}
	else {
		printf("You are taller then me, my height is %d feet %d inches", myFeet, myInches);
	}
	return 0;
}
