#include <stdio.h>
#include <stdlib.h>

// I have a video recording from a session where we talked about binary searches.
// Look in ucfsi.wordpress.com

void binarySearch(int *arr, int size, int target)
{
    // We first need to identify the first index and the last index of our array so we know where the numbers start and end
    int lowIndex = 0;
    // high index is size - 1 because if the array has 40 integers, the last index will be 39
    int highIndex = size - 1;

    // We loop while we have a valid array to look through.
    while (lowIndex <= highIndex)
    {
        // we calculate what index would be right at the middle of the array.
        // Don't worry about if the array has an even or odd amount of numbers, as this will always work.
        int midPoint = (lowIndex + highIndex) / 2;

        // If the number at the midpoint index is the target we were looking for, then we have found the number.
        if (arr[midPoint] == target)
        {
            printf("The number is in the array\n");
            // We return because we have finished the purpose of this function
            return;
        }
        // now we check to see if the target is smaller than the number at the midpoint
        if (target < arr[midPoint])
        {
            // if this is the case, then we know that we need to look to the left of the midpoint.
            // This means we have to change our highIndex to be the number right to the left of the midpoint
            highIndex = midPoint - 1;
        }
        // now we check to see if the target is larger than the number at the midpoint
        else if (target > arr[midPoint])
        {
            // if this is the case, then we know that we need to lok to the right of the midpoint.
            // This means we need to change the lowIndex to be the number to the right of the midpoint
            lowIndex = midPoint + 1;
        }
    }
    // if we make it out side of the while loop, it means we never found the number in the array, so we can print that
    printf("The number is not in the array\n");
}

int main()
{
    // first we create an array of 40 integers
    int *arr = (int *)calloc(40, sizeof(int));

    // Now we put the numbers 1 - 40 in the array
    for (int i = 0; i < 40; i++)
    {
        arr[i] = i + 1;
    }

    // Now we use a binary search to see if the number 33 is in the array
    // We pass in the array, the size, and the target number
    binarySearch(arr, 40, 33);

    return 0;
}