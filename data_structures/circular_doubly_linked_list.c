#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value)
{
    Node *ret = calloc(1, sizeof(Node));
    ret->data = value;
    ret->next = NULL;
    ret->prev = NULL;
    return ret;
}

Node *addEnd(Node *tail, int value)
{
    // create a node
    Node *newNode = createNode(value);

    // check if the list is empty
    if (tail == NULL)
    {
        // make the newNode point to itself both forwards and backwards
        newNode->next = newNode;
        newNode->prev = newNode;
        // return the newNode as the new tail of the list
        return newNode;
    }

    // if the list is not empty then we want to add this node right after the tail, but we want to make the new Node point to the head first
    // make the newNode point to the head
    newNode->next = tail->next;
    // make the head point back at the newNode
    tail->next->prev = newNode;

    // make the newNode point back at the old tail
    newNode->prev = tail;
    // make the newNode come after the tail
    tail->next = newNode;
    // return the new Node as the tail of the list
    return newNode;
}

Node *removeHead(Node *tail)
{
    // check if list is empty
    if (tail == NULL)
        return NULL;
    // check if there is just 1 node
    if (tail->next == tail)
    {
        // free the node
        free(tail);
        // return NULL to show the list is now empty
        return NULL;
    }
    // if there are more than 1 nodes we want to make sure we don't lose access to either of the nodes on either side of the head
    // So let's store the node that comes after the head, since that will be the new head once we remove hte current head
    Node *newHead = tail->next->next;
    // Now we can free the head
    free(tail->next);
    // Now we have to make the tail point towards the newHead
    tail->next = newHead;
    // and make the newHead point back at the tail
    newHead->prev = tail;
    // return the tail
    return tail;
}

void printList(Node *tail)
{
    // check if the list is empty
    if (tail == NULL)
        return;
    // We want to print from head to tail, so let's store the tail in a temp var
    Node *lastNode = tail;
    // Now we can move into the head so we can print from the beginning
    tail = tail->next;
    // while loop that will run until we reach the last node
    while (tail != lastNode)
    {
        // print each node
        printf("%d\n", tail->data);
        // move to the next node
        tail = tail->next;
    }
    // Once we exit the while loop tail will be on the last node, which we still have to print
    printf("%d\n", tail->data);
}

int main()
{
    Node *tail = NULL;
    tail = addEnd(tail, 1);
    tail = addEnd(tail, 2);
    tail = addEnd(tail, 3);

    printList(tail);

    tail = removeHead(tail);
    printList(tail);
    tail = removeHead(tail);
    printList(tail);
    tail = removeHead(tail);
    printList(tail);

    return 0;
}