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

void findNthNodeFromLast(struct node *head, int n) {
    struct node *temp  = head;
    int count  = 1;
    while (count  < n && head != NULL) {
        head  = head->next;
        count++;
    }
    if(head == NULL) {
        cout << "n is greater than number of nodes in a LinkedList \n";
        return;
    }

    while (head != NULL && head->next != NULL) {
        temp =  temp->next;
        head = head->next;
     
    }
    cout  <<   n << " node from last linked list  " << temp->data << std::endl;

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
   
    findNthNodeFromLast(head, 1);
    findNthNodeFromLast(head, 2);
    findNthNodeFromLast(head, 3);
    findNthNodeFromLast(head, 4);
    findNthNodeFromLast(head, 7);
    findNthNodeFromLast(head, 6);
    findNthNodeFromLast(head, 8);
    return 0;
}
