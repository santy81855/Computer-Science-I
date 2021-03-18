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
Node *deleteTail(Node *);
Node *deleteFront(Node *);
void freeList(Node *);

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
    head = deleteTail(head);
    printList(head);
    head = deleteFront(head);
    printList(head);
    freeList(head);

    return 0;
}

Node *createNode(int value)
{
    Node *new = (Node *)calloc(1, sizeof(Node));
    new->data = value;
    new->next = NULL;
    return new;
}

void freeList(Node *head)
{
    // freeing a linked list is one of the times where using recursion makes the code a whole lot easier
    // if the list is empty or we reach the end of the list
    if (head == NULL)
    {
        // we go ahead and return to end the current recursive call
        return;
    }

    // we do the recursive call to move to the end of the list since you want to free from tail to head
    freeList(head->next);
    // Since we want to free from tail to head we call free() after the recursive call
    free(head);
}

Node *deleteTail(Node *head)
{
    // if the tree is empty then there is nothing to remove
    if (head == NULL)
        return NULL;

    // Since getting to the node right before the tail requires us to use cur->next->next in the while loop, we have to first make sure that there are at least 2 nodes in the list
    if (head->next == NULL)
    {
        // if there is only 1 node in the list we can just remove it
        free(head);
        return NULL;
    }
    // when removing the tail of a linked list we want to traverse first to the node right before it
    // We can do that with the following while loop
    Node *cur = head;
    while (cur->next->next != NULL)
        cur = cur->next;

    // now cur is storing the node right before the tail
    // we can now remove the tail safely
    free(cur->next);
    // and set cur->next to null to show that it is the new tail
    cur->next = NULL;
    // return the head back to main
    return head;
}

Node *deleteFront(Node *head)
{
    // Deleting the head of a linked list is super straightforward
    // We first check to see if the list is empty
    if (head == NULL)
        return NULL; // if it is empty theen there is nothing to remove

    // Next we store whatever comes next in the list after head
    Node *temp = head->next;
    // We free the head
    free(head);
    // We set head to be the node we had stored, since that will be the new head
    head = temp;
    // we return the head back to main
    return head;
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