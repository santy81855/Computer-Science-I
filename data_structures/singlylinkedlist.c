#include <stdio.h>
#include <stdlib.h>

// I recommend you look at linkedlist.c before this if you have not had any linked list practice.
// This will be the code for a singly linked list data structure that uses all recursive functions.
// I will leave some functions blank for you to write with the help of the other functions as reference.

// struct for a singly linked list
typedef struct Node
{
    // the value stored in the node. This can be an int, a char, a string, etc
    int data;
    // The pointer to the next node in the list
    struct Node *next;
} Node;

// This function will create a node and initialize its data to the passed integer, and then return the node
Node *createNode(int);
Node *addToTail(Node *, int);
Node *addToFront(Node *, int);
void printList(Node *);

int main()
{
    // Here we create the linked list and set it equal to null to show that it is empty.
    Node *head = NULL;

    // let's add some values to the end of the list
    head = addToTail(head, 1);
    head = addToTail(head, 2);
    head = addToTail(head, 3);

    // Now let's add some values to the front of the list
    head = addToFront(head, -1);
    head = addToFront(head, -2);
    head = addToFront(head, -3);

    // Now we print the list
    printList(head);

    // functions for you to work on. I will post the completed code if anyone asks.
    // head = deleteTail(head);
    // head = deleteFront(head);
    // freeList(head);

    return 0;
}

Node *createNode(int value)
{
    Node *new = (Node *)calloc(1, sizeof(Node));
    new->data = value;
    new->next = NULL;
    return new;
}

Node *addToTail(Node *head, int value)
{
    // if the list is empty or we reach the end of the list, we return the new node
    if (head == NULL)
        return createNode(value);

    // We use recursion to move to the end of the list.
    head->next = addToTail(head->next, value);

    // we return the head at the end
    return head;
}

Node *addToFront(Node *head, int value)
{
    // if the list is empty, we return the new node
    if (head == NULL)
        return createNode(value);
    // if the list is not empty, then we just create a new node and stick it in front of the head
    Node *new = createNode(value);
    // Since it needs to go in front of the head we make the new node's next point to the head
    new->next = head;
    // and since we want the new node to be the first node, we make it the new head
    head = new;
    // we return the head back to the main function
    return head;
}

void printList(Node *head)
{
    // if we reach the end of the list or if the list is empty, we just return
    if (head == NULL)
        return;

    // we print the current value
    printf("%d\n", head->data);

    // we use recursion to move down the list
    printList(head->next);
}