
/* PROGRAM 6c */
#include <stdio.h>
#include <math.h>
int main()
{
int fYear;
int eYear;
int month;
int day;
int dOfWeek;

printf("Please enter the first two digits of your birthyear: ");
scanf("%d", &fYear);
printf("Please enter the last two digits of your birthyear: ");
scanf("%d", &eYear);
printf("Please enter the month you were born (1=January...12= December): ");
scanf("%d", &month);
printf("Please enter the day you were born: ");
scanf("%d", &day);
printf("You were born on ");

dOfWeek = (int)(day+(month+1)*2.6+eYear+(eYear/4)+(fYear/4)-(2*fYear))% 7;
  switch(dOfWeek)
  {
    case 0:
      printf("Satuday, ");
      break;
    case 1:
      printf("Sunday, ");
      break;
    case 2:
      printf("Monday, ");
      break;
    case 3:
      printf("Tuesday, ");
      break;
    case 4:
      printf("Wednesday, ");
      break;
    case 5:
      printf("Thursday, ");
      break;
    case 6:
      printf("Friday, ");
      break;
    default:
      printf("ERROR");
      break;
  }
      switch(month)
      {
        case 1:
          printf("January");
          break;
        case 2:
          printf("February");
          break;
        case 3:
          printf("March");
          break;
        case 4:
          printf("April");
          break;
        case 5:
          printf("May");
          break;
        case 6:
          printf("June");
          break;
        case 7:
          printf("July");
          break;
        case 8:
          printf("August");
          break;
        case 9:
          printf("September");
          break;
        case 10:
          printf("October");
          break;
        case 11:
          printf("November");
          break;
        case 12:
          printf("December");
          break;
        default:
          printf("Invalid Month Entered!");
          break;
      }

    printf(" ");

      if ((day > 0) && (day < 31) )
      {
        switch(day)
        {
          case 1:
          case 21:
          case 31:
            printf("%dst",day);
            break;
          case 2:
          case 22:
          case 32:
            printf("%dnd", day);
            break;
          case 3:
          case 23:
          case 33:
            printf("%drd", day);
            break;
          default:
            printf("%dth", day);
            break;
          }
        }
      else
      {
        printf("ERROR");
      }

printf(", %d%d\n", fYear, eYear);
//printf("%d", dOfWeek);
return 0;
}
