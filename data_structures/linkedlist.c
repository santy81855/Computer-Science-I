#include <stdio.h>
#include <stdlib.h>

// The code below will create a singly linked list and add some values to it.
// This does not represent the typical linked list code because this is mostly to get used to the syntax of linked lists.
// The normal linked list code will be posted in this same folder under the file name singlylinkedlist.c

// the struct of a linked list is called Node
typedef struct Node
{
    // Each node in a list stores an integer value
    int data;
    // Each node also stores a pointer to the next node down the line
    struct Node *next;
} Node;

int main()
{
    // The first element of a linked list is called the head, so we name the first node head.
    Node *head;
    // We set the head = NULL to show that the list is empty when we first create it. This is very important.
    head = NULL;

    // Let's add the value 3 to the first node, aka the head, since it is empty.

    // We first allocate memory for the node
    head = (Node *)calloc(1, sizeof(Node));
    // Then we put the right number inside of it
    head->data = 3;
    // Since this is the only node in the list, it is also the last node in the list
    // We show that a node is last, by setting it's next pointer to NULL to show that there is no node after it
    head->next = NULL;

    // We have just added a node to the list, and we can print it
    printf("The number stored in the head of the list is %d\n", head->data);

    // Let's add another node that will be right after the first node. This is called adding a node to the tail of a linked list, since we are adding it to the end.
    // We first need to allocate memory for another node
    head->next = (Node *)calloc(1, sizeof(Node));
    // head->next is referring to the second node, so we are allocating space into this node

    // Now we put the number 4 inside of this node
    head->next->data = 4;

    // And finally, we show that this is the last node in the list by setting it's next pointer to NULL
    head->next->next = NULL;

    // Now let's print the number in second node to make sure it worked
    printf("The number stored in the second node of the list is %d\n", head->next->data);

    // And now let's get some exposure to traversing a linked list by printing all the elements in the list
    // It is normal to use a temporary variable to move down the list so that we don't lose access to the head of the linked list.
    Node *temp = head;
    // We will be using temp to move down the list so that we don't lose access to the head

    printf("We will now print all the numbers stored in the linked list\n");
    // while temp != null let's us move down the list until we reach the end
    while (temp != NULL)
    {
        // We print the value stored in the current node
        printf("%d\n", temp->data);
        // Then we move down the list into the next node
        temp = temp->next;
    }

    // Again, keep in mind that this is not how linked list code will normally look, and this is just for conceptual help.
    // if you want to see how it will really look, please look at singlylinkedlist.c
}