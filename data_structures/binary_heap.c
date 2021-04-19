//min heap code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap
{
    int *arr;     // The array that stores the data in the tree
    int size;     // The current size of the array
    int capacity; // Max number of items we can have
    int type;     // 0 for min heap, 1 for max heap
} Heap;

Heap *createHeap(int, int);
void insert(Heap *, int);
void deleteN(Heap *, int);
int popMin(Heap *);
int popMax(Heap *);
void heapifyMin(Heap *, int);
void heapifyMinTop(Heap *, int);
void heapifyMaxTop(Heap *, int);
void heapifyMax(Heap *, int);
void printHeap(Heap *);
void cleanUp(Heap *);

int main()
{
    // ask what the size of the heap should be before you create it
    // This program also asks what type, since it can handle both min and max heaps
    int capacity, type;
    printf("What is the capacity of the heap?\n");
    scanf("%d", &capacity);
    printf("What is the type of the heap? \n\t0 = min\n\t1 = max\n");
    scanf("%d", &type);
    Heap *heap = createHeap(capacity, type);

    // if the heap type is 0, aka a min heap we will add values from capacity - 1 down to 0
    if (!heap->type)
    {
        for (int i = 0; i < capacity; i++)
        {
            insert(heap, capacity - i);
        }
    }
    // if the heap type is 1, aka max heap we will add values from 0 to capacity - 1
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            insert(heap, i);
        }
    }

    // print the heap after adding all the values
    printHeap(heap);

    int n;
    // ask the user for a value to remove from the heap
    printf("enter a number to remove from the heap\n");
    scanf("%d", &n);

    // remove the value from the heap
    deleteN(heap, n);

    // print the heap now that we have removed a value from it
    printHeap(heap);

    printf("the size of the heap is %d\n", heap->size);
    int size = heap->size;

    // remove every value from the heap and print the heap after each removal
    if (!heap->type)
    {
        for (int i = 0; i < size; i++)
        {
            printf("Removing the min, which is %d\n", popMin(heap));
            printHeap(heap);
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("Removing the max, which is %d\n", popMax(heap));
            printHeap(heap);
        }
    }

    // free the heap
    cleanUp(heap);

    return 0;
}

Heap *createHeap(int capacity, int type)
{
    Heap *ret = (Heap *)calloc(1, sizeof(Heap));
    ret->size = 0;
    ret->type = type;
    ret->capacity = capacity;
    ret->arr = (int *)calloc(capacity, sizeof(int)); //don't need to initialize each entry of the arr since calloc sets them to 0

    return ret;
}

void insert(Heap *heap, int data)
{
    if (heap->size < heap->capacity) //if the size is greater than the capacity we cannot enter the data
    {
        heap->arr[heap->size] = data;
        if (!heap->type)
            heapifyMin(heap, heap->size); //send in the heap as well as the index of the newest entry
        else
            heapifyMax(heap, heap->size);
        heap->size++;
    }
    else
        printf("The maximum size for this heap has already been reached\n");
}

void heapifyMin(Heap *heap, int index)
{
    //the heapify function will make sure that each parent is smaller than any of its children
    int temp;
    int parent_node = (index - 1) / 2; //this formula will always get you the parent of the entry if the starting index is 0

    if (heap->arr[parent_node] > heap->arr[index])
    {
        //swap them if the parent is larger since the min needs to float up
        temp = heap->arr[index];
        heap->arr[index] = heap->arr[parent_node];
        heap->arr[parent_node] = temp;
        //then the recursive call sending in the parent index insteads
        heapifyMin(heap, parent_node);
    }
}

void deleteN(Heap *heap, int data)
{
    for (int i = 0; i < heap->size; i++)
    {
        if (heap->arr[i] == data)
        {
            //replace with the last item in the array
            heap->arr[i] = heap->arr[heap->size - 1];
            heap->size--;
            if (!heap->type)
            {
                heapifyMinTop(heap, i);
            }
            else
            {
                heapifyMaxTop(heap, i);
            }
        }
    }
}

int popMin(Heap *heap)
{
    if (!heap->size)
    {
        printf("this heap is empty\n");
        return -1;
    }

    //replace the first node with the last and then delete the last
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyMinTop(heap, 0);
    return min;
}

int popMax(Heap *heap)
{
    //replace it with the max and then decrease the list size by 1
    if (!heap->size)
    {
        printf("this heap is empty\n");
        return -1;
    }

    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyMaxTop(heap, 0);
    return max;
}

void heapifyMinTop(Heap *heap, int parent)
{
    int leftIndex = parent * 2 + 1;
    int rightIndex = parent * 2 + 2;
    int min;
    // check that the left child index is not out of bounds of the array
    if (leftIndex >= heap->size || leftIndex < 0)
        leftIndex = -1;
    // check that the right child index is not out of bounds of the array
    if (rightIndex >= heap->size || rightIndex < 0)
        rightIndex = -1;
    // initialize the min to be the parent
    min = parent;
    // check if the left child is both valid and smaller than the parent
    if (leftIndex != -1 && heap->arr[leftIndex] < heap->arr[parent])
        min = leftIndex; // if it is we make it the new min
    // now check if the right child is smaller than the current min
    if (rightIndex != -1 && heap->arr[rightIndex] < heap->arr[min])
        min = rightIndex; // if it is we make it the new min
    // if the min is no longer the parent then we need to swap to maintain the property of min heap
    if (min != parent)
    {
        // swap the parent with the smaller child
        int temp = heap->arr[min];
        heap->arr[min] = heap->arr[parent];
        heap->arr[parent] = temp;

        // recursively call the function again, but now on the child node
        heapifyMinTop(heap, min);
    }
}

void heapifyMax(Heap *heap, int index)
{
    int temp;
    int parent = (index - 1) / 2;

    if (heap->arr[parent] < heap->arr[index]) //if the parent is smaller then the child needs to float up
    {
        temp = heap->arr[parent];
        heap->arr[parent] = heap->arr[index];
        heap->arr[index] = temp;

        heapifyMax(heap, parent);
    }
}

void heapifyMaxTop(Heap *heap, int parent)
{
    int left = parent * 2 + 1;
    int right = parent * 2 + 2;
    int max;

    if (left >= heap->size || left < 0)
    {
        left = -1;
    }
    if (right >= heap->size || right < 0)
    {
        right = -1;
    }

    if (left != -1 && heap->arr[left] > heap->arr[parent])
        max = left;
    else
    {
        max = parent;
    }

    if (right != -1 && heap->arr[right] > heap->arr[max])
    {
        right = max;
    }

    if (parent != max)
    {
        //swap them
        int temp = heap->arr[max];
        heap->arr[max] = heap->arr[parent];
        heap->arr[parent] = temp;

        //recur
        heapifyMaxTop(heap, max);
    }
}

void printHeap(Heap *heap)
{
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d->", heap->arr[i]);
    }
    printf("END\n");
}

void cleanUp(Heap *heap)
{
    free(heap->arr);
    free(heap);
}