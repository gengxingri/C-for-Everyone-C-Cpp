/*
   Assignment 3

   Use the linear linked list code to store a randomly generated set of 100 integers. 
   Use bubble sort to rearrange the list in sorted order. 
   Print these values in rows of 5 on the screen.

*/


#include <stdio.h>
#include <stdlib.h>


#define SIZE 100


// Define a struct list
typedef struct list{ int data; struct list *next; }list;

// Return 1 or 0 based on whether or not argument list is empty
int is_empty(const list *l){ return (l == NULL);}

// Creat a single node(head)
list *create_list(int d){
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

// Add a node(head) to a list
list *add_to_front(int d, list *h){
    list *head = create_list(d);
    head -> next = h;
    return head;
}

// Make a full list from array
list *array_to_list(int d[], int size){
    list *head = create_list(d[0]);
    int i;
    for(i = 1; i< size; i++){
        head = add_to_front(d[i], head);
    }
    return head;
}

// Print a list by 
void print_list(list *h, char *title){
    printf("%s\n", title);
    int i = 0;
    while(h != NULL){

        // If we are at the last element in the list no need for ',' and '\t'
        if(i != SIZE-1)
            printf("%d\t", h->data);
        else
            printf("%d ", h->data);

        // Break line for every five elements
        if ((i % 5) == 4){
            printf("\n");
        }
        // Move h to the next node, increment i.
        h = h -> next;
        i++;
    }
    printf("\n");
}


// Swap the data of two pointers 
void swap_nodes(list *p1, list *p2){
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
    return;
}


// Bubble sort 
void sort_list(list *h)
{
    int i, j;
    list *p1, *p2;

    // Consider two adjacent pointers for each iteration 
    // Starting at the beggining of the list. 
    // represent the number of times we will move the pointers one step ahead decreasing as we bubble more and more element to the end of the list
    
    for(i = SIZE-2; i >= 0; i--){
        p1 = h;
        p2 = p1->next;
        for(j = 0; j <= i; j++){
            if(p1->data > p2->data)
                swap_nodes(p1, p2);
            p1 = p2;
            p2 = p2->next;
        }
    }

}



int main(void){

    // Random number
    list *l = create_list(rand()%1000);
    
    // Add (size-1) new elements to the list with a random number
    int i;
    for(i = 0; i < SIZE-1; i++){
        l = add_to_front(rand()%1000, l);
    }
    print_list(l, "Random numbers: ");
    sort_list(l);
    print_list(l, "After sorting: ");
    return 0;
    
}