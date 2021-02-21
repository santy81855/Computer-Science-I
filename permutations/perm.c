#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the longest string that can be input
#define MAX 100

// the code below will give all of the permutations of an array of words
// This code does not account for duplicate words, so if there are duplicate words in the array it could give duplicate permutations
// In other words this code does not give distinct permutations.
// You don't need distinct permutations if you are just trying to find a certain permutation.
// You only really need distince permutations when you are literally trying to find how many distinct permutations there are for a certain array.

// swap function to swap two words in an array of words
void swap(char **arr, int a, int b)
{
    // store word a into a temp variable
    int aLen = strlen(arr[a]);
    char temp[aLen + 1];
    strcpy(temp, arr[a]);
    // store word b into word a
    int bLen = strlen(arr[b]);
    arr[a] = realloc(arr[a], sizeof(char) * (bLen + 1));
    strcpy(arr[a], arr[b]);
    // store word a into word b using the temp variable
    arr[b] = realloc(arr[b], sizeof(char) * (aLen + 1));
    strcpy(arr[b], temp);
}

// perm the string array
void perm(char **arr, int index, int size)
{
    // if index reaches size then we have reached a valid permutation
    if (index == size)
    {
        // This is where you would check if the current permutation is the one you need.
        // We will just print each permutation here, since this code doesn't do anything special
        for (int i = 0; i < size; i++)
            printf("%s ", arr[i]);
        printf("\n");
        return;
    }

    // this for loop will take you through array of words generating new permutations each time.
    // This code makes more sense if you trace it on paper.
    for (int i = index; i < size; i++)
    {
        swap(arr, index, i);
        perm(arr, index + 1, size);
        swap(arr, index, i);
    }
}

int main()
{
    // how many words will be in the array
    int n;
    // create an array of strings
    char **arr;

    // call the permutation function. It won't work until you fill the above array with n words.
    perm(arr, 0, n);

    return 0;
}