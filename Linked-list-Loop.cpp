// LINKED lIST PROGRAMS
// this program detects and remove loop in a LL
// There are multiple ways for solving this problem
// 1. we can add flag in a struct definition, and keep traversing the list. set the flag with each traversal. If the flag is already set for any
//.    node then there is a loop.
// 2. Using unorderd map. keep storing nodes in a map and check if node is already there in a map or not. loop is there if node is present in map
// 3. Using two pointers problems. below is the implmentation of the same,
//
#include <iostream>
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void detectLoopRemoveLoop(struct node *head) {
    
    struct node *first = head;
    struct node *second = head;
    
    while (first && second && second->next)  {
        first = first->next;
        second = second->next->next;
      // If there is no loop then it has to be null checked else code will core
        if (second == NULL)
            break;
        if (first == second->next) {
           cout << "found loop in a LinkedList data " << first->data << " " << second->data <<  std::endl;
           break;
        }
    
    }
    // two checks for even and odd no linked list
    if (second == NULL || second->next == NULL ) {
        cout << "loop free LinkedList \n";
        return;
    }
  // count the nos of node in a loop
    second = first->next;
    int count = 1;
    while(second->data != first->data) {
        count++;
        second = second->next;
    }
    cout << "no of nodes in a loop = " << count << std::endl;
    // use count to remove loop in a linked list
  
    first = head;
    second = head;
    int i = 0;
    // move second pointer to count's distance from head
    while (i < count) {
        second = second->next;
        i++;
    }
    // now move both pointers. It will meet at start of a loop
    while (first->next != second->next) {
        first = first->next;
         second = second->next;
    }
    // Make it loop free
    second->next = NULL;

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
    createLinkedList(&head, 34);
    createLinkedList(&head, 55);
    createLinkedList(&head, 78);
    createLinkedList(&head, 99);
    cout << "created linked list " << std::endl;
    printLinkedList(head);
    struct node *loop = head;
    // insert after specific node
    insertAfterNode(&head, 78, 72);
   // struct node *loop = head;
    createLinkedList(&head, 100);
 
    cout << "Insert node after 78 and linked list is " << std::endl;
    printLinkedList(head);
    head->next->next->next->next->next->next = head->next->next->next->next->next;
    detectLoopRemoveLoop(head);
    printLinkedList(head);
    return 0;
}
