#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *name;
    int id;
    struct Node *next;
} Node;

/* 
Fill in the following functions until the program prints the right output

Node *addTail(Node *head, char *name, int id)
{
}

void addTail2(Node **head, char *name, int id)
{
}
*/
void printList(Node *head)
{
    if (head == NULL)
        return;
    printf("Name: %s | Id: %d\n", head->name, head->id);
    printList(head->next);
}

int main()
{
    Node *head = NULL;

    head = addTail(head, "jason", 819);
    head = addTail(head, "alexa", 387);
    addTail2(&head, "michelle", 392);

    printList(head);

    return 0;
}