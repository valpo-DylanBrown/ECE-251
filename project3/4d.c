/*Program 4d*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int offset;

void encrypt(char arr[])
{
  int i;
  for(i=0; i < strlen(arr); i++)
  {
    arr[i] += offset;
  }
}

void decrypt(char arr[])
{
  int i;
  for(i=0; i < strlen(arr); i++)
  {
    arr[i] -= offset;
  }
}




int main()
{
  char text[50];
  printf("Please input the offset you wish to use to encrypt your message: ");
  scanf("%d", &offset);
  printf("\nPlease enter the text you wish to encrypt: ");
  scanf("%s", &text);
  printf("\nThe originial text is: \"%s.\"", text);
  encrypt(text);
  printf("\nThe encrypted text with offset %d is: \"%s.\"", offset, text);
  decrypt(text);
  printf("\nThe decrypted text with offset %d is: \"%s.\"", offset, text);

  return 0;

}
