#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I really recommend making sure you can understand the binary search using just integers before looking at this code****

// keep in mind that whether we pass in the static array or the dynamic array, we woulud still use char ** as the array type
// We used a char * as the target because it is a single word
void binarySearch(char **arr, int size, char *target)
{
    // The first part of the function is still the same as a binary search for an integer array because we just need a low and high index
    int lowIndex = 0;
    int highIndex = size - 1;

    // the while loop is still the same as the integer version of the binary search
    while (lowIndex <= highIndex)
    {
        // finding the midpoint is still the same as the integer version of the binary search
        int mid = (lowIndex + highIndex) / 2;

        // The part that changes with using an array of strings instead of integers is how we compare the values.
        // since we are using strings we have to use strcmp();

        // if the target is the same as the word at the mid index, we just say that we found the word in the array
        if (strcmp(target, arr[mid]) == 0)
        {
            printf("The word is in the array\n");
            // We return because we are done using this function
            return;
        }

        // now we check if the target is smaller than the word at the midpoint
        if (strcmp(target, arr[mid]) < 0)
        {
            // if it is we change the high index as usual
            highIndex = mid - 1;
        }

        // now we check if the target is larger than the word at the midpoint
        else if (strcmp(target, arr[mid]) > 0)
        {
            // if it is then we change the low index as usual
            lowIndex = mid + 1;
        }
    }

    // if we make it out of the loop, then the word is not in the array
    printf("The word is not in the array\n");
}

int main()
{
    // First we create an array of strings. Let's make 5 words that can each be at most 20 characters long.
    // we can do it statically or dynamically.
    // Screw it let's do it both ways.

    // static
    char staticArr[5][21];

    // dynamic
    char **dynamicArr;
    dynamicArr = (char **)calloc(5, sizeof(char *));
    for (int i = 0; i < 5; i++)
        dynamicArr[i] = (char *)calloc(21, sizeof(char));

    // obviously static is a lot simpler, but you want to make sure you can do it both ways for this class.

    // Let's use the dynamic array from now on since it would be the same process for both static and dynamic.
    // Let's put 5 words into the array. Remember that the array must be sorted for the binary search to work.
    // So we will input 5 words in lexicographical order. (This means they are in alphabetical order, but they all have to be lowercase or all uppercase)
    strcpy(dynamicArr[0], "alex");
    strcpy(dynamicArr[1], "brittany");
    strcpy(dynamicArr[2], "carol");
    strcpy(dynamicArr[3], "david");
    strcpy(dynamicArr[4], "elfo");

    // now that our array has 5 entries, we can go ahead and pass it into the binary search function along with its size and a target
    binarySearch(dynamicArr, 5, "brittany");

    return 0;
}