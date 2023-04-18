// Use of pointers

#include <stdio.h>

int foobar(int* n){
     *n = *n +1;
     return *n;
}

int main(void)
{
   // int a = 1;
   // int *p = &a;
   // printf("\n%p",&a);  //①
   // printf("\n%p",p);   //②
   // printf("\n%p",&p);   //③
   int k = 6;
   printf("foobar(k) = %d,",foobar(&k) );
   printf(" k = %d\n", k);
}