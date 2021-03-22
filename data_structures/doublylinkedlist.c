#include <stdio.h>
#include <stdlib.h>

// struct for a doubly linked list
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// struct to store the head and tail
typedef struct List
{
    Node *head;
    Node *tail;
} List;

// create the doubly linked list
List *createList();
// create a node
Node *createNode(int);

void addHead(List *, int);
void addTail(List *, int);
void removeHead(List *);
void removeTail(List *);
void printList(List *);
void freeList(Node *);

int main()
{
    // create the doubly linked list
    List *dll = createList();

    // add some values to the list
    addHead(dll, 1);
    addHead(dll, 2);
    addHead(dll, 3);
    addTail(dll, 1);
    addTail(dll, 2);
    addTail(dll, 3);
    // print the list
    printList(dll);
    // remove some values
    removeHead(dll);
    removeTail(dll);

    printList(dll);

    // free the nodes of the list
    freeList(dll->head);
    // free the list
    free(dll);

    return 0;
}

List *createList()
{
    List *ret = calloc(1, sizeof(List));
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}

Node *createNode(int value)
{
    // create the new node
    Node *newNode = calloc(1, sizeof(Node));
    // initialize the next and prev pointers to null
    newNode->next = newNode->prev = NULL;
    // put the value in the node
    newNode->data = value;
    // return the new Node
    return newNode;
}

void addHead(List *dll, int value)
{
    // create a new node
    Node *newNode = createNode(value);
    // check if list is empty
    if (dll->head == NULL)
    {
        // if the list is empty then just add the value to the head and the tail, since it is the only value
        dll->head = dll->tail = newNode;
        // return to end the function
        return;
    }
    // if the list is not empty just add the value at the front by making the head come after it
    newNode->next = dll->head;
    // make the current head point back to the new node
    dll->head->prev = newNode;
    // then make it the head
    dll->head = newNode;
}

void addTail(List *dll, int value)
{
    // create a new node
    Node *newNode = createNode(value);
    // check if list is empty
    if (dll->head == NULL)
    {
        // if the list is empty then we just add a value and make it head and tail
        dll->head = dll->tail = newNode;
        return;
    }
    // if the list is not empty then we just add the newNode after the tail
    dll->tail->next = newNode;
    // make the newNode point back at the current tail
    newNode->prev = dll->tail;
    // make the new node the new tail
    dll->tail = newNode;
}

void removeHead(List *dll)
{
    // check if the list is empty, in which case remove nothing
    if (dll->head == NULL)
    {
        return;
    }
    // if we have only 1 value in the list we just free it and set it to null
    if (dll->head == dll->tail)
    {
        free(dll->head);
        dll->head = dll->tail = NULL;
    }
    // if the list has more than 1 value just store what comes after the head and then free it
    Node *temp = dll->head->next;
    free(dll->head);
    // set whatever was after head to be the new head
    dll->head = temp;
    // set the prev pointer of the new head to null so that it is the first node
    dll->head->prev = NULL;
}

void removeTail(List *dll)
{
    // check if the list is empty
    if (dll->head == NULL)
    {
        // nothing to remove
        return;
    }
    // if the list has only 1 value
    if (dll->head == dll->tail)
    {
        free(dll->head);
        dll->head = dll->tail = NULL;
        return;
    }
    // if the list has more than 1 node then store whatever comes right before the current tail
    Node *temp = dll->tail->prev;
    // delete the current tail
    free(dll->tail);
    // make temp the new tail
    dll->tail = temp;
    // set its next equal to null to show it is the tail
    dll->tail->next = NULL;
}

void printList(List *dll)
{
    // store the head in a temp variable so we don't mess up the list
    Node *current = dll->head;
    // print while the head is not null
    while (current != NULL)
    {
        // print the value
        printf("%d\n", current->data);
        // move into the next node
        current = current->next;
    }
}

void freeList(Node *head)
{
    if (head == NULL)
        return;
    freeList(head->next);
    free(head);
}