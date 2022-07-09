/ C program to rearrange a linked list in such a
// way that all odd positioned node are stored before
// all even positioned nodes
#include<bits/stdc++.h>
using namespace std;
 
// Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// A utility function to create a new node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// Rearranges given linked list such that all even
// positioned nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head)
{
    // Corner case
    if (head == NULL)
        return NULL;
 
    // Initialize first nodes of even and
    // odd lists
    Node *odd = head;
    Node *even = head->next;
 
    // Remember the first node of even list so
    // that we can connect the even list at the
    // end of odd list.
    Node *evenFirst = even;
 
    while (1)
    {
        // If there are no more nodes, then connect
        // first node of even list to the last node
        // of odd list
        if (!odd || !even || !(even->next))
        {
            odd->next = evenFirst;
            break;
        }
 
        // Connecting odd nodes
        odd->next = even->next;
        odd = even->next;
 
        // If there are NO more even nodes after
        // current odd.
        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenFirst;
            break;
        }
 
        // Connecting even nodes
        even->next = odd->next;
        even = odd->next;
    }
 
    return head;
}
 
// A utility function to print a linked list
void printlist(Node * node)
{
    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}
 
// Driver code
int main(void)
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    cout << "Given Linked List\n";
    printlist(head);
 
    head = rearrangeEvenOdd(head);
 
    cout << "\nModified Linked List\n";
    printlist(head);
 
    return 0;
}
