#include <iostream>
#include <cstring>

using namespace std;

#define IPV4 0
#define IPV6 1

/* linked list for storing ip address */
struct node {
   char        *data;
   bool        l3type;
   struct node *next;
};
/* Base class for printing node of linked list */
class print {
    public:
      virtual void printLinkedList(struct node *temp) {
          return;
      }
};
/* Print V4 address derived class */
class printV4 : public print {
    public:
        void printLinkedList(struct node *temp) {
            cout << "\n V4 linked list data = " << temp->data ;
           
        }
};
/* Print V6 address derived class */
class printV6 : public print {
    public:
        void printLinkedList(struct node *temp) {
           
            cout << "\n V6 linked list data = " << temp->data;
        }
};
/* Populate Linked list */
struct node *createList(char data[], int l3type)
{
    struct node *head = (struct node *)malloc(sizeof(struct node *));
    if (head == NULL)
        return NULL;
    int n = strlen(data);  
    head->data = new char[(n * sizeof(char))];
    head->data = data;
    
    head->l3type = l3type;
    return head;
}
int main()
{
    char addv4[] = "10.10.10.1";
    char addv6[] = "FE80:CD00:0:CDE:1257:0:211E:729C";
   
    char addv41[] = "200.200.30.10";
    char addv61[] = "2345:0425:2CA1:0000:0000:0567:5673:23b5";
 
    /* Create Linked list */
    struct node *head = createList(addv4, IPV4);
    head->next = createList(addv6, IPV6);
    head->next->next = createList(addv41, IPV4);
    head->next->next->next = createList(addv61, IPV6);
    head->next->next->next->next = NULL;
  
    /*IPV4 obj */
    print *ptrv4;
    
    /*IPV6 obj */
    print *ptrv6;
    
    printV4 v4Ptr;
    printV6 v6Ptr;
    
    ptrv4 = &v4Ptr;
    ptrv6 = &v6Ptr;
    
    struct node *temp = head;
    
    while (temp != NULL) {
        /* if its v4 address then invoke v4 class member */
        if (temp->l3type == IPV4) {
            ptrv4->printLinkedList(temp);
        /* if its v6 address then invoke v6 class member */
        } else if (temp->l3type == IPV6) {
            ptrv6->printLinkedList(temp);
        }   
        temp = temp->next;
    }
 
}


/* ouput from onlinegdb

 V4 linked list data = 10.10.10.1
 V6 linked list data = FE80:CD00:0:CDE:1257:0:211E:729C
 V4 linked list data = 200.200.30.10
 V6 linked list data = 2345:0425:2CA1:0000:0000:0567:5673:23b5
    
    ...Program finished with exit code 0
      Press ENTER to exit console.
*/
