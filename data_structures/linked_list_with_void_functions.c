#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void addEnd(Node **head, int value)
{
    // if the list is empty, then create a new node, set its data to value, set its next to null, and make it the head. Then exit the function
    if (*head == NULL)
    {
        Node *new = calloc(1, sizeof(Node));
        new->data = value;
        new->next = NULL;
        *head = new;
        return;
    }

    // iterate to the last node using a temp variable named current so we don't lose access to the head
    Node *current = *head;

    while (current->next != NULL)
        current = current->next;

    // once we exit the while loop, current will be storing the last node, whether the list has 1 node or 100000 nodes
    // since we are adding a node to the end, we can create a new node and then set its data to value, set its next to null, and make it the head
    Node *new = calloc(1, sizeof(Node));
    new->data = value;
    new->next = NULL;

    // now we add this new node to the end of our list by making it current->next
    current->next = new;
}

void printList(Node *head)
{
    // here we can use head to move down the list because we are only using a copy of our list, so we won't be affecting our original list
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void addFront(Node **head, int value)
{
    // create a new node and initialize its variables
    Node *new = calloc(1, sizeof(Node));
    new->data = value;
    // set it's next to point to the current head so that it can now be the first element in the list
    new->next = *head;
    // now that we have the new node at the front we have to make it the head so that our program knows that it is there
    *head = new;
}

void removeHead(Node **head)
{
    // if the list is empty then we can't remove anything
    if (*head == NULL)
        return;

    // otherwise you can just create a temp to store whatever the second node is
    Node *temp = (*head)->next;
    // free the head
    free(*head);
    // make the second node the new head
    *head = temp;
}

void removeTail(Node **head)
{
    // if it is empty then we can't remove anything
    if (*head == NULL)
        return;
    // if the list has only 1 element we just free it
    if ((*head)->next == NULL)
    {
        // free the head
        free(*head);
        // set it equal to NULL so we know it is empty
        *head = NULL;
        return;
    }
    // if the list has more than 1 item then we have to get to the element right before last
    // we create a temp variable called current that will be used to move down the list so we don't lose access to the head
    Node *current = *head;
    while (current->next->next != NULL)
        current = current->next;
    // when we exit this while loop current will be storing the element right before the last one

    // we want to free the last element
    free(current->next);
    // then we set the current->next = NULL so that we know this is the new last element
    current->next = NULL;
}

int main()
{
    Node *head = NULL;

    // add a value to the end of the list using a void function because we hate ourselves
    addEnd(&head, 1);
    addEnd(&head, 2);
    addEnd(&head, 3);

    // add a 0 to the front of the list
    addFront(&head, 0);

    // remove the head
    removeHead(&head);

    // remove the tail
    removeTail(&head);

    // we don't need to pass in the address of the head because we aren't changing our list in a print function
    printList(head);

    return 0;
}