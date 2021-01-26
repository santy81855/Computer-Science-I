#include <stdio.h>
#include <stdlib.h>

void linearSearch(int *arr, int size, int target)
{
    // Linear search is pretty simple.
    // You just create a for loop that will compare each number in the array to the target.
    // Once you find the correct number, you can print that the number was found.
    // If we make it out of the for loop it means we never found the number
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            // print that we found it
            printf("We found the number in the array\n");
            // And then return to exit the function so we don't keep iterating
            return;
        }
    }
    // If we make it out of the loop, we print that we didn't find the number in the array
    printf("We did not find the number in the array\n");
}

int main()
{
    // first, I will create a dynamic array that can store 30 numbers.
    // I could make it static, but it's good to practice allocating whenever possible
    int *arr = (int *)calloc(30, sizeof(int));

    // I will then put the numbers 1 - 30 in the array
    for (int i = 0; i < 30; i++)
    {
        // the i + 1 makes the array have 1 - 30 rather than 0 - 29 inside of it
        arr[i] = i + 1;
    }

    // Now we just create a function to find a certain number in the array using a linear search
    // I am passing in the array, the size, and the target we are looking for
    linearSearch(arr, 30, 5);

    return 0;
}