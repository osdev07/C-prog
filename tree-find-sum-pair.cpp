******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// CPP program to find a pair with
// given sum using hashing

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* NewNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
struct Node* insert(struct Node* root, int key)
{
    if (root == NULL)
        return NewNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
 
int  findpairUtil(struct Node* root, int sum,
                  int *arr, int size)
{
    if (root == NULL)
        return 1;
 
    if (findpairUtil(root->left, sum, arr, size))
        return 0;
    for (int i = 0; i < size; i++) {
         if ((sum - root->data) == arr[i]) {
           printf("Pair is found ( %d %d )",  sum - root->data,root->data );
           return 0;
         }   
    }
   

    return findpairUtil(root->right, sum, arr, size);
}

void findPair(struct Node* root, int sum, int *arr, int size)
{
   
    if (findpairUtil(root, sum, arr, size))
        printf( "Pairs do not exit\n"); 
}
 
// Driver code
int main()
{
   struct  Node* root = NULL;
    int arr[8];
    root = insert(root, 15);
    arr[0] = 15;
    root = insert(root, 10);
    arr[1] = 10;
    root = insert(root, 20);
    arr[2] = 20;
    root = insert(root, 8);
    arr[3] = 8;
    root = insert(root, 12);
    arr[4] = 12;
    root = insert(root, 16);
    arr[5] = 16;
    root = insert(root, 25);
    arr[6] = 25;
    root = insert(root, 10);
    arr[7] = 10;
    int sum = 28;
    findPair(root, sum, arr, 8);
    
    return 0;
}
