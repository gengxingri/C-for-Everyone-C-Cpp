/*
   The ADT List
   This is an example shown by Dr. Pohl
*/

// Full list

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Self-referential structs
typedef struct list {int data; struct list *next;} list;

int is_empty(const list *l){ return (l == NULL);} // is_empty function

// Creat a single node
list* creat_list (int d)
{
   list* head = malloc(sizeof(list)); //dynamical allocate for head
	head -> data = d;
   head -> next = NULL;
   return head;
}

//Add a node to a list
list* add_to_front (int d, list* h)
{
   list* head = creat_list(d);
   head -> next = h;
   return head;

}

//Produce full list from array
list* array_to_list (int d[], int size)
{
   list* head = creat_list(d[0]);
   int i;
   for (i = 1; i < size; i++){
   	head = add_to_front(d[i], head);
   }
   return head;
}

// Print a list
void print_list(list *h, char *title)
{
	printf("%s\n", title );
	while (h != NULL){
		printf("%d: ", h-> data );
		h = h -> next;
	}
}

//Main function
int main()
{
	list list_of_int;
	list *head = NULL;
   int data[6] = {2, 3, 5, 7, 8, 9};

   head = array_to_list(data, 6);
   
   print_list(head, " data[6] made into a 6 element list");
   printf("\n\n");
   return 0;

}