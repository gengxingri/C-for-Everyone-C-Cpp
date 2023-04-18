/*
   The ADT List deletion
   This is an example shown by Dr. Pohl
*/

// Full list

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Self-referential structs
typedef struct list {int data; struct list *next;} list;


// Use <ctype.h> here
int is_empty(const list *l){ return (l == NULL);} 

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
		printf("%d ", h-> data );
		h = h -> next;
	}
}

// Count the number of the list
int count(list *h)
{
   int cnt = 0;
   while ( h!= NULL){
      cnt++;
      h = h -> next;
   }
   return cnt;
}

//Delete
void delete (list *elem, list **prev, list **hd)
{
   if (*hd == *prev)
      *hd = elem -> next;
   else
      (*prev) ->next = elem -> next;
   free(elem);          // deallocate memory 
}


//Delete the whole list
void delete_list(list *h)
{
   list *temp;
   if (h != NULL){
      temp = h;
      delete_list(h = h -> next);
      free(temp);
   }
}

// Concatenate two lists
void concat(list *h1, list *h2)
{
   if (h1 == NULL)
      h1 = h2;
   else if (h1 -> next == NULL)
      h1 -> next = h2;
   else
      concat(h1 -> next, h2);
}



// Main function
int main()
{
	list list_of_int;
	list *head1 = NULL, *head2 = NULL;
   int data[6] = {2, 3, 5, 7, 8, 9};
   int data2[] = {17, 6, 99};
   
   head1 = array_to_list(data, 6);
   head2 = array_to_list(data2, 3);

   print_list(head1, "\ndata[6] made into a 6 element list");
   printf("\n\n");
   print_list(head2, "\ndata2[3] made into a 3 element list");
   printf("\n\n");

   concat(head1, head2);

   print_list(head1, "concatenated list");
   printf("\nSize of concat is %d\n", count(head1));

   delete(head1, &head1, &head1);
   //delete_list(head1);
   //head1 = NULL;

   print_list(head1, "\ndelete from list");
   delete(head1 -> next -> next, &head1 -> next, &head1);


   print_list(head1, "\ndelete from list");
   printf("\n\n");
   return 0;

}