#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fill in the function below so that it will return the sum of the numbers in the array
int sumRecursive(int *arr, int size)
{

}
// fill in the function below so that it will return the smalls number in the array
int smallestRecursive(int *arr, int size)
{
    
}
// fill in the function below so that it will search for a particular number in the array
// return 1 if found and return 0 if not found
int findNum(int *arr, int size, int target)
{

}

int main()
{
    // The variable below has the numbers 1 - 10 stored inside of it
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }
    // fill in the following functions above using recursion
    int sum = sumRecursive(arr, 10);
    printf("sum = %d\n", sum);
    
    int smallest = smallestRecursive(arr, 10);
    printf("smallest = %d\n", smallest);
    
    int find = findNum(arr, 10, 5);
    printf("find = %d\n", find);

    return 0;
}
