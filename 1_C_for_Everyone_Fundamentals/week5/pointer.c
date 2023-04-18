// Use of pointers

#include <stdio.h>

int main(void)
{
   const int SIZE = 5;

   int grades[SIZE] ={78, 67, 92, 83, 88};
   double sum = 0;
   double *ptr_to_sum = &sum;
   int i;

   printf("my grades are:\n ");

   for (i = 0; i < SIZE; i++)
   	 printf("%d\t", grades[i]);
   
   printf("\n\n");

   for (i = 0; i < SIZE; i++)
   	  sum = sum +grades[i];
   printf("my average grades are %.2f\t", sum/SIZE);
   printf("\n\n");

   printf("sum is at %p, or %lu and is %lf\n ", 
         ptr_to_sum, 
         ptr_to_sum, 
         *ptr_to_sum);
   printf("grades are at %lu to %lu\n", grades, grades+5);
   return 0;
}