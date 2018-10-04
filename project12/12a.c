#include <stdio.h>
#include <string.h>

int main()
{
  	char straight[100], temp, rev[100];
  	int i, j, len;

  	printf("Please Enter any String :  ");
    gets(straight);
    printf("Your Original String is : %s", straight);
    strcpy(rev, straight);
  	len = strlen(rev) - 1;

  	for (i = 0; i < strlen(rev)/2; i++)
  	{
  		temp = rev[i];
  		rev[i] = rev[len];
  		rev[len--] = temp;
  	}

  	printf("\nString after Reversing = %s\n", rev);

    if (strcmp(straight, rev) == 0){
      printf("This string is a palindrome\n");
    }
    else {
      printf("The string is not a palindrome\n");
    }

  	return 0;
}
