/* PROGRAM 6a */
#include <stdio.h>
int main()
{
    char hexa[32]; //reads hex as an array of chars, max 32 bits
    int i = 0;

    printf("Please enter a 32-bit hexadecimal number: ");
    scanf("%s", hexa);
    printf("\nIn binary, that number is ");
      while (hexa[i]) //loops through all of the bits of the hex number
      {
          switch (hexa[i])
          /*each case represents a char from the string, which translates
          the hex bit into binary.*/
          {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011"); break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
            default: //for invalid hex digits
                printf("not real.\n%c is not a valid hex digit.", hexa[i]);
          }

          i++;
      }
    return 0;
}
