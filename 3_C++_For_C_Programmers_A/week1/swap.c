/*
   This is an example shown by Dr. Pohl in class
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j)
{
    int temp = *i;  
    *i = *j;
    *j = temp;
}

void swap_double(double *i, double *j)
{
    double temp = *i;  
    *i = *j;
    *j = temp;
}


int main()
{   
	int m = 5, n = 10;
  double x = 5.3, y = 10.6;

	printf("int input %d, %d\n", m, n);
  swap(&m, &n);
  printf("output %d, %d\n", m, n);
  printf("\n");

  printf("double input %lf, %lf\n", x, y);
  swap_double(&x, &y);
  printf("output %lf, %lf\n", x, y);
  return 0;
}



