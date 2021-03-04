#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *ret = calloc(1, sizeof(Node));
    ret->data = value;
    ret->next = NULL;
    return ret;
}

Node *addFront(Node *tail, int value)
{
    // we will create a node no matter what
    Node *newNode = createNode(value);
    if (tail == NULL)
    {
        // make the node point to itself if it is the only node since circular linked list
        newNode->next = newNode;
        // return the newNode to be the tail of the linked list
        return newNode;
    }
    // if the list is not empty then we just make the newNode point to the current head, which is tail->next
    newNode->next = tail->next;
    // now we make the current tail point to this newNode
    tail->next = newNode;
    // Now we return this new node to be the tail of the list
    return newNode;
}

Node *removeEnd(Node *tail)
{
    // check if empty
    if (tail == NULL)
        return NULL;

    // check if there is only 1 element
    if (tail->next == tail)
    {
        free(tail);
        return NULL;
    }

    // if there are 2 or more elements we have to traverse the list to get to the node right before last
    Node *cur = tail;
    while (cur->next != tail)
        cur = cur->next;
    // once we exit this while loop cur will be storing the node before last
    // we want to go ahead and free the last node, but we don't want to lose access to the head
    // so we need to store the head
    Node *head = tail->next;

    // Now we can go ahead and free the last node
    free(cur->next);
    // and now we go ahead and link up the new last node with the head
    cur->next = head;
    // Now we return the last node to be the tail of the list
    return cur;
}

void printList(Node *tail)
{
    // we check if the list is empty
    if (tail == NULL)
        return;
    // Now we store the tail
    Node *temp = tail;
    // if the list is not empty we start by moving to the head so we print in the right order
    tail = tail->next;
    // We will print each node until we reach the tail
    while (tail != temp)
    {
        printf("%d\n", tail->data);
        tail = tail->next;
    }
    // We still need to print the tail so we use 1 more print statement
    printf("%d\n", tail->data);
}

// the easiest way to free the memory is to just call removeEnd or removeFront over and over until all nodes have been removed
void freeList(Node *tail)
{
    while (tail != NULL)
        tail = removeEnd(tail);
}

int main()
{
    Node *tail = NULL;

    tail = addFront(tail, 3);
    tail = addFront(tail, 2);
    tail = addFront(tail, 1);
    tail = addFront(tail, 0);

    printf("List after adding 4 values\n");
    printList(tail);

    tail = removeEnd(tail);
    tail = removeEnd(tail);

    printf("List after removing the tail twice\n");
    printList(tail);

    // free the list
    freeList(tail);

    return 0;
}