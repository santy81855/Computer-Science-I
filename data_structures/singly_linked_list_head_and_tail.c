#include <stdio.h>
#include <stdlib.h>

// this code will be of a singly linked list in which we store both the head and the tail of the list so that we can have all O(1) insertions

// the struct of a node in the list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// the struct for storing the head and the tail of the linked list
typedef struct List
{
    struct Node *head;
    struct Node *tail;
} List;

void addEnd(List *listy, int value)
{
    // check if the list is empty
    if (listy->head == NULL)
    {
        // if it is empty then we just create a new node
        Node *new = calloc(1, sizeof(Node));
        // set its data variable to the value we passed in
        new->data = value;
        // set its next variable to null since it is the only element in the list
        new->next = NULL;
        // Since this is the only element in the list it is both the head and the tail so we have to set those
        listy->head = listy->tail = new;
        // exit the function because we already added the element
        return;
    }

    // if the list is not empty then we just create a new node
    Node *new = calloc(1, sizeof(Node));
    // set its data variable to the value we passed in
    new->data = value;
    // set it's next variable to null since it will be the last element in the list
    new->next = NULL;
    // now we have to add this element to the end of our list, so we have to put it after our current tail
    listy->tail->next = new;
    // now we have to make it the official element of the listy
    listy->tail = new;
}

void removeEnd(List *listy)
{
    // if the list is empty there is nothing to remove
    if (listy->head == NULL)
        return;
    // if there is only 1 element in the list we just free it
    if (listy->head == listy->tail)
    {
        // free the element
        free(listy->head);
        // set the head and tail to null since the list is now empty
        listy->head = listy->tail = NULL;
        return;
    }
    // if the list has more than 1 element then we have to iterate to the element right before last
    Node *current = listy->head;

    while (current->next->next != NULL)
        current = current->next;

    // once we exit this while loop current will be storing the element right before the tail
    // we want to remove the tail and make the element that is right before it the new tail
    // so we free the tail
    free(listy->tail);
    // now we make the element stored in current the new tail
    listy->tail = current;
    // now we set the next of the tail to NULL to show that it is the last element
    listy->tail->next = NULL;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main()
{
    // let's create a list which we will call listy, which will have a head and a tail, but they will both be empty initially since the list will have no values inside
    List *listy = calloc(1, sizeof(List));
    // the following line will set both the head and the tail of listy to NULL. You can also just do it in separate lines
    listy->head = listy->tail = NULL;

    // let's add some values to the end of the list
    // We can use void functions without passing in the address because we are never changing listy, we are only changing what is inside of listy
    addEnd(listy, 1);
    addEnd(listy, 2);
    addEnd(listy, 3);

    // let's remove an element from the end
    removeEnd(listy);

    // use the above functions as reference to write the following functions
    // removeHead(listy);
    // addHead(listy);

    // print the list starting from the head
    printList(listy->head);

    // don't forget to free everything before exiting!

    return 0;
}