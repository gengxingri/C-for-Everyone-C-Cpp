/*
   I/O Printing program
   This is an example shown by Dr. Pohl
*/

#include <stdio.h>

int main(void)
{
   double x = 0.123456789;
   printf("general printing ideas\n");
   printf("x is %-12.5e and %e and %10.5f and %10d\n\n", x, x, x, (int)x);
   return 0;
}