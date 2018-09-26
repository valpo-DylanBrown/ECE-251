
/*PROGRAM 6b */
#include <stdio.h>

int main()
{
int year;
int month;
int day;

printf("Please enter the year you were born: ");
scanf("%d", &year);
printf("Please enter the month you were born (1=January...12= December): ");
scanf("%d", &month);
printf("Please enter the day you were born: ");
scanf("%d", &day);
printf("You were born on ");
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
printf(", %d", year);
return 0;
}
