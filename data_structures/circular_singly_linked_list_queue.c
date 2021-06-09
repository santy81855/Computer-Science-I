#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// struct for the queue, which stores the front and end of the list
typedef struct Queue
{
    Node *front;
    Node *end;
} Queue;

// function to create and return a new node
Node *createNode(int value)
{
    Node *ret = calloc(1, sizeof(Node));
    ret->next = NULL;
    ret->data = value;
    return ret;
}

// enqueue adds a node to the back of a queue
void enqueue(Queue *curQueue, int value)
{
    // check if queue is empty
    if (curQueue->front == NULL)
    {
        // the front and the end will be the same
        curQueue->front = curQueue->end = createNode(value);
        // make the end point end to the front
        curQueue->end->next = curQueue->front;
        return;
    }

    // if queue has is not empty then we add a new node at the end
    curQueue->end->next = createNode(value);
    // make the new node the end of the list
    curQueue->end = curQueue->end->next;
    // make the new node point to the front to keep it circular
    curQueue->end->next = curQueue->front;
}

// dequeue removes and returns the value that was at the front of the queue
int dequeue(Queue *curQueue)
{
    // check if the queue is empty
    if (curQueue->front == NULL)
    {
        // there is nothing to remove so we can just return a crazy number
        return -987654321;
    }
    // if the queue is not empty we store the number at the front so we don't lose it
    int numToReturn = curQueue->front->data;

    // if the queue has only 1 value in it then we just remove it
    if (curQueue->front == curQueue->end)
    {
        // remove the only node
        free(curQueue->front);
        // set the front and end to null to show the queue is now empty
        curQueue->front = NULL;
        curQueue->end = NULL;
        // return the number that used to be in that node
        return numToReturn;
    }

    // if the queue has more than 1 node then we just remove the front node
    // store the second node in a temp node so we don't lose access to it when we free the first node
    Node *temp = curQueue->front->next;
    // free the first node
    free(curQueue->front);
    // make the second node the new first node
    curQueue->front = temp;
    // make the last node point to the new first node
    curQueue->end->next = curQueue->front;
    // return the value that was on the first node
    return numToReturn;
}

// print the queue
void printQueue(Queue curQueue)
{
    if (curQueue.front == NULL)
    {
        printf("This queue is empty\n");
        return;
    }

    Node *temp = curQueue.front;

    while (temp != curQueue.end)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    printf("%d\n-------------------------------------\n", temp->data);
}

int main()
{
    // we allocated enough space to store an array of 5 queues
    Queue *queueArr = (Queue *)calloc(5, sizeof(Queue));

    // set the front and end of all 5 queues to NULL to show they are all empty
    for (int i = 0; i < 5; i++)
    {
        queueArr[i].front = NULL;
        queueArr[i].end = NULL;
    }

    // we can access the 3rd queue with queueArr[2]
    // we can access the front of the 3rd queue with queueArr[2].front
    // queueArr[0], queueArr[1], queueArr[2], queueArr[3], queueArr[4]

    // let's add some values to the third queue
    // we pass in the address of the queue so that we aren't just passing in a copy of our queue
    enqueue(&queueArr[2], 4);
    enqueue(&queueArr[2], 5);
    enqueue(&queueArr[2], 6);
    // below are some concepts about referencing and dereferencing
    // queueArr = Queue struct pointer (Queue *)
    // queueArr[2] = Queue struct (Queue ) (dereferencing removes a star)
    // &queueArr[2] = Queue struct pointer (Queue *) (referencing adds a *)

    // print the queue to make sure the enqueue function works
    printQueue(queueArr[2]);

    // let's remove some values from the third queue
    dequeue(&queueArr[2]);
  
    // print to make sure the dequeue worked
    printQueue(queueArr[2]);

    return 0;
}
