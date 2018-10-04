#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char string[50];
  char* pString = NULL;
  char arithmeticOp = 0;
  char* pArithmeticOp = NULL;
  char operator = 0;
  char* numberOne = NULL;
  char* numberTwo = NULL;
  float num1;
  float num2;

  fgets(string, 20, stdin);
  pString = string;
  for (operator=42; operator < 46; operator++){
    if(operator!=44){
        pArithmeticOp = strchr(pString, operator);
        if (pArithmeticOp != NULL){
          break;
        }
    }
  }
  printf("The function is: %c\n", operator);
  numberOne = strtok(pString, " +-*/");
  printf("number one: %s\n", numberOne);
  numberTwo = strtok(pString-numberOne, " +-*/");
  printf("number 2: %s", numberTwo);
  num1 = atof(numberOne);
  num2 = atof(numberTwo);

  switch(operator)
  {
    case '+':
      printf("The result is %.2f\n", num1+num2);
      break;
    case '-':
      printf("The result is %.2f\n", num1-num2);
      break;
    case '*':
      printf("The result is %.2f\n", num1*num2);
      break;
    case '/':
      printf("The result is %.2f\n", num1/num2);
    default:
      printf("ERROR");
  }
return 0;
}
