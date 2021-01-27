#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Topics to cover:

// we don't need to name the parameters in the prototype
int binarySearch(char[][22], char *, int);

int main()
{
    char arr[5][22]; // static so we don't need to allocate

    // put 5 words into the array in alphabetical order
    for (int i = 0; i < 5; i++)
        scanf("%s", arr[i]);

    // if we wanted to store last names, we could create separate first and last name variables

    // binary search using strings

    int result = binarySearch(arr, "lasagna", 5);

    // It should print 0 if the word is not found and 1 if the word is found.
    printf("%d\n", result);

    // alex, james, lasagna, mike, santy

    // strcmp() only accounts for lexicographical order
    // strcasecmp() accounts foro alphabetical order

    return 0;
}

int binarySearch(char arr[][22], char *target, int size)
{
    int lowIndex = 0;
    // the size - 1 will always give us the last index
    int highIndex = size - 1;

    // this makes sure that we only do the while loop while we have a valid array and that includes when there is only 1 item in the array
    while (highIndex >= lowIndex)
    {
        // the mid will be an index, so to get to the value inside we have to access that index
        int mid = (highIndex + lowIndex) / 2;

        if ((strcmp(arr[mid], target) == 0))
        {
            return 1;
        }

        // check if the target is smaller than the word at the midpoint
        if (strcmp(target, arr[mid]) < 0)
        {
            highIndex = mid - 1;
        }
        // check if the target is larger than the word at the midpoint
        else if (strcmp(target, arr[mid]) > 0)
        {
            lowIndex = mid + 1;
        }
    }
    // if we exit the while loop it means we did not find the word
    return 0;
}
