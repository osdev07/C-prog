// LINKED lIST PROGRAMS

#include <iostream>
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

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
    createLinkedList(&head, 34);
    createLinkedList(&head, 55);
    createLinkedList(&head, 78);
    createLinkedList(&head, 99);
    cout << "created linked list " << std::endl;
    printLinkedList(head);
    // insert after specific node
    insertAfterNode(&head, 78, 72);
    createLinkedList(&head, 100);
    cout << "Insert node after 78 and linked list is " << std::endl;
    printLinkedList(head);
    cout << "after reverse LinkedList" << std::endl;
    reverseLinkedList(&head);
       printLinkedList(head);
    
    return 0;
}
