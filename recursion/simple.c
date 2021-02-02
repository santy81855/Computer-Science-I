#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For our first recursive function we should go as simple as possible:
// So let's make 2 functions. 1 to print the array in normal order and another to print it backwards.

// Notice that this will be a void function because we don't need to return anything. We are just printing.
void printArray(int *arr, int size)
{
    // Something that you need in every recursive function is a base case.
    // This is what gives the recursion a point at which to stop, which prevents infinite function calls and segfaults.
    // In this case since we just have an array and its size, we will use the size to keep track of when we finish printing everything

    // So when the size reaches 0 we know we are done and we can just end the recursion.
    if (size == 0)
        return;

    // Another necessary part of any recursive function is a recursive call, where the function will call itself
    // Since we want to print the array in normal order, we have to go to the first value before we print
    // We can do this by just calling the function and subtracting 1 from the size each time.
    printArray(arr, size - 1);

    // Now, once we reach the first value, we can go ahead and print it.
    // Notice that we use size - 1 because we have 10 numbers in indexes 0 - 9.
    printf("%d\n", arr[size - 1]);
}

// Now we can print it forwards again using a different approach.
void printArray2(int *arr, int current, int size)
{
    // We know we want to print from index 0 all the way up to index (size - 1)
    // This is why we passed in a third parameter called 'current', which will keep track of our current index
    // We want the program to stop printing once we have already printed the last number, which is at index (size - 1)
    if (current == size)
        return;

    // Now we can just print the current index as we go through the array, starting from 0
    printf("%d\n", arr[current]);

    // then we recur to go through the array using our recursive call.
    // This time we change the "current" rather than the size
    printArray2(arr, current + 1, size);
}

// Now we print it in reverse order, which is actually easier when all we have in an array and its size
void printArrayReverse(int *arr, int size)
{
    // Our base case should end the recursion when our size reaches 0
    if (size == 0)
        return;

    // Since we are printing in reverse order, we just print each value as we get to it from the end.
    // We use size - 1 as the index because our array indexes are 0 - 9
    printf("%d\n", arr[size - 1]);

    // Finally we use the recursive call to go through the array in reverse order
    printArrayReverse(arr, size - 1);
}

int main()
{
    // Let's create an array of 10 integers
    int *arr = (int *)calloc(10, sizeof(int));
    // Let's put the numbers 1 - 10 in the array
    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;
    // Let's pass it to the function that will print it for us

    // This function will print it backwards, so 10, 9, 8, 7, etc.
    printf("This is the array in reverse order:\n");
    printArrayReverse(arr, 10);

    // This function will print it forwards, so 1, 2, 3, 4, etc.
    printf("This is the array in normal order:\n");
    printArray(arr, 10);
    // This function will also print it forwards using a different method
    printf("This is the array in normal order using a different approach:\n");
    printArray2(arr, 0, 10);

    return 0;
}
