/*
   The ADT List
   This is an example shown by Dr. Pohl
*/

// List of an element

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list {int data; struct list *next;} list;

int is_empty(const list *l){ return (l == NULL);}

void print_list(list *h, char *title){
	printf("%s\n", title);
	while (h != NULL){
		printf("%d :", h -> data);
		h = h -> next;
	}

}

int main()
{
	list list_of_int;
	list *head = NULL;
   head = malloc(sizeof(list)); //dynamic memory allocation

   printf("sizeof(list) = %lu\n", sizeof(list));//lu for unsigned long
   head -> data = 5;
   head -> next = NULL;
   print_list(head, " single element list");
   printf("\n\n");
   return 0;

}