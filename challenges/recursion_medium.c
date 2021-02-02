#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Challenge: Finish the recursive function below so that it will return the sum of an array.
*/

int recSum(int *arr, int size)
{
}

int main()
{
    int *arr = calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        if (i % 2)
            arr[i] = i;
        else
            arr[i] = i + 5;
    }
    // The array stored in arr is = 5, 1, 7, 3, 9, so the sum should be 25.
    printf("The sum of the array is: %d\n", recSum(arr, 5));

    return 0;
}