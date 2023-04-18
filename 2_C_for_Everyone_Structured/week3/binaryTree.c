/*
   The ADT Binary Tree
   This is an example shown by Dr. Pohl
*/

// List of an element
#include <stdio.h>
#include <stdlib.h>


typedef char DATA; 
struct node{ 
	DATA d; 
	struct node *left;
	struct node *right;
};

typedef struct node NODE;
typedef NODE        *BTREE;



void inorder(BTREE root)
{
	if ( root != NULL){
		inorder(root ->left);
		printf("%c ", root->d);
		inorder(root ->right);
	}
}


//Creat node
BTREE new_node(void)
{return (malloc(sizeof(NODE)));}

BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
	BTREE t;
	t = new_node();
	t -> d = d1;
	t -> left = p1;
	t -> right = p2;
	return t;
}


// Creat binaryTree
BTREE creat_tree(DATA a[], int i, int size){
	if (i >= size)
		return NULL;
	else 
	   return(init_node(a[i],
	   	             creat_tree(a, 2*i + 1, size),
	   	             creat_tree(a, 2*i + 2, size)
	   	             ));

}


int main()
{
	char d[] = {'a', 'b', 'c', 'd', 'e'};
	BTREE b;
	b = creat_tree(d, 0, 5);
	inorder(b);
	printf("\n\n");
   return 0;
}














