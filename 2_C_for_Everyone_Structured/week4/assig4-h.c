/*
    Assignment 4 (honour) - Bruce Geng

    Open and read a file of integer pairs into an array 
    that is created with the first integer telling you how many to read.  
    4 9  11  4  5 mean create an integer array size 4 and read into data[].   
    Write a routine that places these values into a binary tree structure. 
    Walk the tree “inorder” and print these values to the screen.   
*/

#include <stdio.h>
#include <stdlib.h>

// Use an integer as the data type for this Binary tree
typedef int DATA;

typedef struct node{
    DATA d;
    struct node  *left;
    struct node *right;
}Node;

// Define a tree as a pointer to a node 
typedef Node *BTree;

// Print a binary tree innorder traversal
void inorder(BTree root){
    if(root == NULL)
        return;
    else{
        inorder(root->left);
        printf("%d\n", root->d);
        inorder(root->right);
    }
}

// Create a new node
Node *new_node(void){
    return malloc(sizeof(Node));
}

// Initialize a new node
Node *init_node(DATA d, Node *left, Node *right){
    Node *t;
    t = new_node();
    t->d = d;
    t->left = left;
    t->right = right;
    return t;
}

// Creat a new tree recursively  
BTree create_tree(DATA a[], int i, int size){
    if (i>=size)
        return NULL;
    else
        return init_node(a[i], 
                         create_tree(a, i*2+1, size), 
                         create_tree(a, i*2+2, size));
    
}


// Read data from the file into the array
void read_file(FILE *ifp, int d[], int size){
    
    int i; 
    for(i = 0; i < size; i++){
        fscanf(ifp, "%d", &d[i]);
    }
}


// Main function
int main(int argc, char *argv[]){
    
    FILE *ifp; // Input file
    int n; // Size of the array

    
    if(argc != 2){
        printf("Please specify only input file\n");
        exit(1);
    }
    

    ifp = fopen(argv[1], "r");

    // First consider empty file
    if(fscanf(ifp, "%d", &n) != 1){
        printf("File is empty!\n");
        exit(1);
    }
    int data[n];

    // Rewind before that point
    read_file(ifp, data, n);    
    
    BTree bt;
    bt = create_tree(data, 0, n);
    inorder(bt);
    fclose(ifp);
    return 0;
}