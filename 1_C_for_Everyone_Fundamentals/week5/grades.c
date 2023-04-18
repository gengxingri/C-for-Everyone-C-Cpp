// initializaton of array

#include <stdio.h>

int main(void)
{
   const int SIZE = 5;

   int grades[SIZE] ={78, 67, 92, 83, 88};
   double sum = 0;
   int i;

   printf("my grades are:\n ");

   for (i = 0; i < SIZE; i++)
   	 printf("%d\t", grades[i]);
   
   printf("\n\n");

   for (i = 0; i < SIZE; i++)
   	  sum = sum +grades[i];
   
   printf("my average grades are %.2f\t", sum/SIZE);
   


}