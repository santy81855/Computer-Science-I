#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dog
{
    int age;
} Dog;

int main()
{
    Dog *dogArr = (Dog *)calloc(5, sizeof(Dog));

    for (int i = 0; i < 5; i++)
        dogArr[i].age = i + 1;

    // Find the dog in the array of dog structs that has an age of 2.
    // Create a function in which you will change that age from 2 to 10.
    // The only restriction is that you cannot just pass in the entire array of dog structs.
    // You can only pass in the struct of dog with an age of 2.
    // You may pass it by reference as well.

    return 0;
}