//
// LINKED lIST PROGRAMS @auther-osDev07
// this program will add and delete nodes in LL
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
//
// create a linked list: insert element at start
//
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
//
// create a linked list: insert element at end of LL
//
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
//
// create a linked list: insert element after specified node
//
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
//
// Delete linked list: Delete perticular node
// Handle del from start of LL
// From end of LL
// and handle anything in between
//
void deleteNode(struct node **head, int data) {
    
    struct node *temp = (*head);
    //
    // If it is first node
    // then change the head pointer
    //
    if (temp->data == data) {
        struct node *toDelHead = temp;
        (*head) = temp->next;
        free(toDelHead);
        toDelHead = NULL;
        return;
        
    }
    while (temp->next && temp->next->data != data) {
        temp = temp->next;
    }

    struct node *toDel = temp->next;
    //
    // If its a last node then point previous
    // node to NULL
    if (toDel->next == NULL) {
        temp->next = NULL;
    } else {
        temp->next = temp->next->next;
    }
    // free node
    free(toDel);
    // ensure no zombie
    toDel = NULL;
}
//
// Delete whole LL
//
void deleteList(struct node **head) {
    
    if ((*head) == NULL) {
        cout << "linked list is empty " << std::endl;
        return;
    }
    
    struct node *temp = *head;
    struct node *toDel = NULL;
    while (temp != NULL) {
        toDel = temp;
        temp = temp->next;
        (*head) = temp;
        free(toDel);
        toDel = NULL;
       
    }
    return;
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
    cout << "Insert node after 78 and linked list is " << std::endl;
    printLinkedList(head);
    // insert at end
    insertAtEnd(&head,100);
    cout << "Insert after last node and linked list is " << std::endl;
    printLinkedList(head);
    //
    // Delete Utilities
    //
    cout << "Delete 72 node " << std::endl;

    deleteNode(&head, 72);
    printLinkedList(head);

    cout << "Delete last node " << std::endl;
    deleteNode(&head, 100);
    printLinkedList(head);

    cout << "Delete first node " << std::endl;
    deleteNode(&head, 99);
    printLinkedList(head);
    
    cout << "Delete whole list" << std::endl;
    deleteList(&head);
    printLinkedList(head);
    
    return 0;
}
