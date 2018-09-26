#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int offset;

void decrypt(char arr[])
{
      int i;
      for(i = 0; i < strlen(arr); i++)
      {
            arr[i] = arr[i] - offset;
      }
}

void encrypt(char arr[])
{
      int i;
      for(i = 0; i < strlen(arr); i++)
      {
            arr[i] = arr[i] + offset ;
      }
}

int main()
{
      char password[40];
      int ch;
      printf("Enter a Password:\t");
      scanf("%s", password);
      printf("\nPassword:\t%s\n",password);
      encrypt(password);
      printf("\nEncrypted Password:\t%s\n", password);
      decrypt(password);
      printf("\nDecrypted Password:\t%s\n", password);
      return 0;
}
