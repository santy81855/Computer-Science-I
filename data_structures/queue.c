#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// using a linked list to implement a queue
typedef struct Node
{
  int data;
  struct Node * next;
} Node;

// the queue needs a front and an end node to know where to add and where to remove
typedef struct Queue
{
  Node * front;
  Node * end;
} Queue;

Queue * createQueue()
{
  // allocate enough space for 1 queue
  Queue * newQueue = (Queue *) calloc(1, sizeof(Queue));
  // initialize front and end to NULL because it is empty and so that we can check for emptiness properly
  newQueue->front = NULL;
  newQueue->end = NULL;
  return newQueue;
}

void enqueue(Queue * qq, int value)
{
  // check if its empty
  if (qq->front == NULL)
  {
    Node * newNode = calloc(1, sizeof(Node));
    // initialize the values of a node
    newNode->next = NULL;
    // add the value to the data variable of the node
    newNode->data = value;
    // make this new node the head/front of our list
    qq->front = newNode;
    // make this new node the end/tail of our list as well
    qq->end = newNode;

    return;
  }
  // if the queue is not empty then we just add a new value after the current end
  Node * newNode = calloc(1, sizeof(Node));
  newNode->next = NULL;
  newNode->data = value;
  // set the new node to come after the current end
  qq->end->next = newNode;
  // make the new node the new end of the list
  qq->end = newNode;
}

void dequeue(Queue * qq)
{
  // check if list is empty
  if (qq->front == NULL)
  {
    // there is nothing to remove if the list is empty
    return;
  }
  // if the list is not empty, then we store the second item in the list in a temp variable
  Node * temp = qq->front->next;
  // next we free the current head of the list
  free(qq->front);
  // now we make the second value the new head of the list
  qq->front = temp;
}

void printQueue(Node * head)
{
  // print while there are nodes to print
  while(head != NULL)
  {
    // print the current node data
    printf("%d\n", head->data);
    // move into the next node in the list
    head = head->next;
  }
}

int peek(Queue * qq)
{
  // check if list is empty
  if (qq->front == NULL)
  {
    // return crazy value if we don't have a valid number to return 
    return -123456789;
  }
  // if not empty we just return the value of the head
  return qq->front->data;
}

// this is the general formula for freeing a linked list
// keep in mind that this frees the list inside the queue but you still need to free the Queue * inside the main function
void freeQueue(Node * head)
{
  if (head == NULL)
    return;
  
  freeQueue(head->next);
  free(head);
}

int main()
{
  // we want to create the queue
  Queue * qq = createQueue();

  // enqueue some values to this queue
  enqueue(qq, 3);
  enqueue(qq, 6);
  enqueue(qq, 8);
  enqueue(qq, 9);

  // print the queue to make sure the values are added properly
  // we can pass in just the first node since we have access to the entire list from there
  printQueue(qq->front);

  printf("-----------------------------------\n");

  // remove some values from the queue (remember you always remove from the front on a queue)
  dequeue(qq);
  dequeue(qq);

  // print again to make sure we removed the first couple of value
  printQueue(qq->front);

  printf("-----------------------------------\n");

  // Now we take a peek at the first value using the Peek function
  int firstValue = peek(qq);
  // we will return a crazy number if the queue is empty so that we don't print it
  if (firstValue != -123456789)
  {
    printf("The first node is %d.\n", firstValue);
  }

  // finally we free the linked list inside the queue
  freeQueue(qq->front);
  // free the Queue pointer
  free(qq);


  return 0;
}   
