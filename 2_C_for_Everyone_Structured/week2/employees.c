/*
  Write a struct that has a member that is the name of a business department: HR, Sales, Research, Software, and Executive (use enums for the 4 departments). 
  A second member that is an annual salary as an int. 
  A third member that is a social security number(unsigned).  
  Generate 10 employees with different social security numbers. 
  Invent a salary generator for each department (use some base salary for the department and add in a randomly generated offset).  

  Print out the 10 employees and their values to the screen-one line at a time.
*/



#include<stdio.h>
struct employee{
  int id, age, salary;
  char name[25];
}emp[100];

void main()
{
  int i, n;

  printf("Enter the no of employees\n");
  scanf("%d", &n);

  printf("Enter employee info as id , name , age , salary\n");
  for(i=0; i < n; i++){
    scanf("%d %s %d %d",&emp[i].id,emp[i].name, &emp[i].age, &emp[i].salary);
  }
  printf("\nEMP_NAME\tEMP_NAME\tEMP_AGE\t\tEMP_SAL\n");
    
  for(i=0;i<n;i++){
    printf("%d\t\t%s\t\t%d\t\t%d\n",emp[i].id,emp[i].name,emp[i].age,emp[i].salary);
  }
}