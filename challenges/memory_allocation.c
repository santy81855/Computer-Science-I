#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dog
{
    int age;
};

typedef struct Cat
{
    char name[101];
};

int main()
{
    // DIFFICULTY = easy
    int *a;
    // allocate enough space to store the number 5 in variable 'a' using calloc

    // store the number 5 in the variable a

    // DIFFICULTY = medium
    char *name;
    // allocate enough memory to store the name jakeston using malloc

    // store the name jakeston in the 'name' variable using the appropriate string function

    // DIFFICULTY = hard
    struct Dog *dogList;
    // allocate 60 Dog structs inside of dogList using malloc

    // Set the age of every dog in the list as 5.

    // DIFFICULTY = harder
    struct Cat **catList;
    // allocate 4 Cat struct pointers inside of catList using calloc

    // Set the name of the 4 cats to be alice, bob, carol, david using the appropriate string functions.

    return 0;
}
