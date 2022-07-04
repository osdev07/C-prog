/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// LINKED lIST PROGRAMS

#include <iostream>
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
void reverseLinkedList(struct node **head);
struct node {
    int data;
    struct node *next;
};
bool isCompareList(struct node *a, struct node *b) {
    while (a && b) {
        if (a->data != b->data) {
            return 0;
        }
        a = a->next;
        b = b->next;
    }
    if (a == NULL && b == NULL)
        return 1;
        
    return 0;
}
bool isPalindrome1st(struct node *head)  {
    
    struct node *slow = head, *fast = head;
    struct node *prev = NULL, *mid =  NULL, *prev_slow = NULL;
    
    while  (fast && fast->next) {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
        
    }
    // if list is odd then fast->next will be null else fast will be null
    if (fast && fast->next == NULL) {
        mid = slow;
        slow = slow->next;
    }
    prev_slow->next = NULL;
    reverseLinkedList(&slow);
    bool isPal = false;
    isPal = isCompareList(head,slow);
    reverseLinkedList(&slow);
    if (mid) {
        prev_slow->next = mid;
    } else {
        prev_slow->next = slow;
    }
    return isPal;
}
bool isPalindrome(struct node **left,  struct node *right) {
    
    if (right == NULL)
        return 1;
        
    bool isPal = isPalindrome(left, (right)->next);
    if  (!isPal) 
         return 0;
         
    bool isPal1 = (((*left)->data) == (right->data)) ? 1 : 0;
    
    *left = (*left)->next;
    return isPal1;
}

void reverseLinkedList(struct node **head) {
    
    struct node *temp = (*head);
    struct node *prev = NULL;
    struct node *cur = temp;
    struct node  *next = NULL;
    //
    // next will reach to null in even linked list
    // next->next will reach to null in odd linked list
    // So add these two null checks else code will crash
    //
    while (cur != NULL) {
        //next will point to next of curr node
        next = cur->next;
        // curr next should point to prev node, in first pass its null
        cur->next  = prev;
        // prev node is updated to curr/next node to itself
        prev = cur;
        // cur should point to next node.
        cur = next;
    }
    // in the end , prev will be the first node of LL
    // so point head to prev node
    (*head) = prev;
    
}
void createLinkedList(struct node **head, int data) {
    struct node *temp = (struct  node *) malloc(sizeof(struct node *));
    
    if (temp == NULL) {
        cout << "malloc failed" << std::endl;
        return;
    }
    

    temp->data = data;
  
    //insert at first position
    temp->next = (*head);
    
    (*head) = temp;
    
    
}
void insertAtEnd(struct node **head, int data) {
    
    struct node *temp = *head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    struct node *newNode = (struct  node *)malloc(sizeof(struct node));
    if (newNode == NULL){
        cout << "Failed to allocated new node" << std::endl;
    }
    temp->next = newNode;

    newNode->data = data;
    newNode->next = NULL;
    
}
void insertAfterNode(struct node **head, int after, int data) {
    struct node *temp = *head;
    
    while (temp->data != after) {
        temp = temp->next;
    }
    struct node *newNode = (struct  node *)malloc(sizeof(struct node));
   if (newNode == NULL){
        cout << "Failed to allocated new node" << std::endl;
    }
    newNode->next = temp->next;
    newNode->data = data;
    temp->next = newNode;
}


void printLinkedList(struct node *Node) {
    
    if (Node == NULL) {
        cout << "list is empty" << std::endl;
        return;
    }
    while (Node != NULL) {
        cout << Node->data << "-->";
        Node = Node->next;
    }
    cout << "NULL" <<std::endl;
}
int main() {
    struct node *head = NULL;
    //
    // ADD Utilities
    //
    createLinkedList(&head, 1);
    createLinkedList(&head, 2);
    createLinkedList(&head, 3);
    createLinkedList(&head, 3);
    createLinkedList(&head, 2);
    createLinkedList(&head, 1);
    cout << "created linked list " << std::endl;
    printLinkedList(head);
    // insert after specific node
    if (isPalindrome1st(head)) {
        cout << "list is Palindrome from 1st method" << std::endl;
    
    } else {
        cout << "list is not Palindrome" << std::endl;
    }
    if (isPalindrome(&head, head)) {
        cout << "list is Palindrome" << std::endl;
    
    } else {
        cout << "list is not Palindrome" << std::endl;
    }
 

       printLinkedList(head);
    
    return 0;
}
