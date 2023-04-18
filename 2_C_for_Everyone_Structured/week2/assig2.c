/*
  Assignment 2

  Write enumerated types that supports dates—such as december 12. 
  Then add a function that produces a next day. So nextday(date) of december 12 is december 13. 
  Also write a function printdate(date) that prints a date legibly.
  The function can assume that February has 28 days and it most know how many days are in each month. 
  Use a struct with two members; one is the month and the second  is the day of the month—an int (or short).
  
  Do this for the following dates:  February 28, March 14, October 31, and  December 31.
*/

#include <stdio.h>

// Define enum types for months 
typedef enum month{ 
  jan, feb, march, apr, may, jun, jul, aug, sep, oct, nov, dec
} month;

// Define strcut types for days
typedef struct date{ 
  month m; 
  int day; 
}date;

// Print date when getting a struct date as a parameter.
void printdate(date d){
  
  // Consider months case by case because days are different in each month
  switch(d.m){
    case jan:
      if (d.day < 1 || d.day > 31){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("January %d\n", d.day);
      break;
    case feb:
      if (d.day < 1 || d.day > 28){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("February %d\n", d.day);
      break;
    case march:
      if (d.day < 1 || d.day > 31){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("March %d\n", d.day);
      break;
    case apr:
      if (d.day < 1 || d.day > 30){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("April %d\n", d.day);
      break;
    case may:
      if (d.day < 1 || d.day > 31){
        printf("Wrong input!\nPlease input the right date:\n");
                break;
      }
      printf("May %d\n", d.day);
      break;
    case jun:
      if (d.day < 1 || d.day > 30){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("June %d\n", d.day);
      break;
    case jul:
      if (d.day < 1 || d.day > 31){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("July %d\n", d.day);
      break;
    case aug:
      if (d.day < 1 || d.day > 31){
        printf("Wrong input!\nTPlease input the right date:\n");
        break;
      }
      printf("August %d\n", d.day);
      break;
    case sep:
      if (d.day < 1 || d.day > 30){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("September %d\n", d.day);
      break;
    case oct:
      if (d.day < 1 || d.day > 31){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("October %d\n", d.day);
      break;
    case nov:
      if (d.day < 1 || d.day > 30){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("November %d\n", d.day);
      break;
    case dec:
      if (d.day < 1 || d.day > 31){
        printf("Wrong input!\nPlease input the right date:\n");
        break;
      }
      printf("December %d\n", d.day);
      break;
  }
}


date *nextday(date d){

  static date next;

  // Again, consider months case by case because days are different in each month
  switch(d.m){
    case jan:
      next.day = d.day + 1;
      if(next.day == 32){next.day = 1; next.m = feb;}
      return &next;
    case feb:
      next.day = d.day + 1;
      if(next.day == 29){next.day = 1; next.m = march;}
      return &next;
    case march:
      next.day = d.day + 1;
      if(next.day == 32){next.day = 1; next.m = apr;}
      return &next;
    case apr:
      next.day = d.day + 1;
      if(next.day == 31){next.day = 1; next.m = may;}
      return &next;
    case may:
      next.day = d.day + 1;
      if(next.day == 32){next.day = 1; next.m = jun;}
      return &next;
    case jun:
      next.day = d.day + 1;
      if(next.day == 31){next.day = 1; next.m = jul;}
      return &next;
    case jul:
      next.day = d.day + 1;
      if(next.day == 32){next.day = 1; next.m = feb;}
      return &next;
    case aug:
      next.day = d.day + 1;
      if(next.day == 32){next.day = 1; next.m = sep;}
      return &next;
    case sep:
      next.day = d.day + 1;
      if(next.day == 31){next.day = 1; next.m = oct;}
      return &next;
    case oct:
      next.day = d.day + 1;
      if(next.day == 32){next.day = 1; next.m = nov;}
      return &next;
    case nov:
      next.day = d.day + 1;
      if(next.day == 31){next.day = 1, next.m = dec;}
      return &next;
    case dec:
      next.day = d.day + 1;
      if(next.day == 32){next.day = 1; next.m = jan;}
      return &next;
  }
  return &next;
}

// February 28, March 14, October 31, and  December 31
int main(void)
{
  date d1;
  d1.day = 1;
  d1.m = jan;
  printdate(d1);
  printdate(*(nextday(d1)));

  date d2;
  d2.day = 28;
  d2.m = feb;
  printdate(d2);
  printdate(*(nextday(d2)));

  date d3;
  d3.day = 14;
  d3.m = march;
  printdate(d3);
  printdate(*(nextday(d3)));

  date d4;
  d4.day = 31;
  d4.m = oct;
  printdate(d4);
  printdate(*(nextday(d4)));

  date d5;
  d5.day = 31;
  d5.m = dec;
  printdate(d5);
  printdate(*(nextday(d5)));

  return 0;
}


