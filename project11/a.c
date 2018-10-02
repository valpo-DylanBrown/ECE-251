#include <stdio.h>
int main()
{
float arr[]={1.0, 2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7};
float *ptr1;
ptr1 = &arr[2];
printf("%f\n", *ptr1);
return 0;
}
