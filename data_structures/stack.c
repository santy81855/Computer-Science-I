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

Node *push(Node *top, int value)
{
    // create the node
    Node *newNode = createNode(value);

    // Put the node in front of (on top) of the top
    newNode->next = top;

    // return the newNode as the new top element
    return newNode;
}

// top is Node ** because we passed in the address of the top so that we can edit the original
int pop(Node **top)
{
    // check if hte stack is empty
    // We have to use *top because we have to dereference the address we passed in to get to the top node
    if (*top == NULL)
    {
        printf("There is nothing to print\n");
        return -1;
    }
    // if the stack is not empty then we start by storing the value of the top node
    int ret = (*top)->data;
    // Now we store the node below the top node
    Node *temp = (*top)->next;
    // Now we free the top
    free(*top);
    // set the next value as the new top
    *top = temp;
    // return the value of the old top
    return ret;
}

int topFunction(Node *top)
{
    // check if the stack is empty so we don't dereference null
    if (top == NULL)
        return -1;
    // if the stack is not empty then return the top value without altering it
    return top->data;
}

void printStack(Node *top)
{
    while (top != NULL)
    {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main()
{
    // create the stack, we will use top instead of head so that it makes more sense in terms of a stack
    Node *top = NULL;

    // add values to the stack
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    // print the stack and note that the most recently added item should be at the top
    printStack(top);

    // remove elements from the stack while printing their value
    for (int i = 0; i < 4; i++)
    {
        // check if there are any values to pop before printing
        if (topFunction(top) != -1)
            printf("The value we just popped is %d\n", pop(&top)); // notice that the values get popped starting from the top
        else
            printf("There are no values in the stack\n");
    }

    return 0;
}