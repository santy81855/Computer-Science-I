#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char **nameList;
    int nameListLength;
    struct Node *next;
} Node;

/* 
Fill in the following function until the program prints the right output.
The goal of this program is to add 2 nodes to the tail of an empty linked list. Each node will store an entire list of names.

Node *addHead(Node *head, char **list, int listLength)
{
}

*/
void printList(Node *head)
{
    if (head == NULL)
        return;
    for (int i = 0; i < head->nameListLength; i++)
    {
        printf("%d\n", head->nameListLength);
        printf("%s\n", head->nameList[i]);
    }
    printList(head->next);
}

int main()
{
    Node *head = NULL;

    char **nameList1 = calloc(10, sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        nameList1[i] = calloc(3, sizeof(char));
        strcpy(nameList1[i], "hi");
    }

    char **nameList2 = calloc(15, sizeof(char *));
    for (int i = 0; i < 15; i++)
    {
        nameList2[i] = calloc(6, sizeof(char));
        strcpy(nameList2[i], "hello");
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", nameList1[i]);
        printf("%s\n", nameList2[i]);
    }

    head = addTail(head, nameList1, 10);
    head = addTail(head, nameList2, 15);

    printList(head);

    return 0;
}