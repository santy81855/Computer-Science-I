#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We did not get to finish this challenge problem during 01/20/20 session, so here is the finished code to it.

typedef struct Dog
{
    int age;
} Dog;

typedef struct Shelter
{
    Dog **arr;
} Shelter;

int main()
{
    Shelter *orlandoShelter;
    // allocate enough space for 10 dogs to fit into this shelter

    // Since the Dogs are inside of the Shelter struct, we first have to allocate enough space for 1 shelter
    orlandoShelter = (Shelter *)calloc(1, sizeof(Shelter));

    // Nwo we need to allocate enough space for 10 dogs into the Dog struct that we have inside of the shelter struct
    // We access the variable inside of the struct using the (->) because orlandoShelter is a pointer
    orlandoShelter->arr = (Dog **)calloc(10, sizeof(Dog *));

    // Now that we have allocated enough space for 10 dogs we are technically done with what the question asked.

    // We can take it a step further by allocating memory for 1 dog into each of the dog pointers that we created.
    // We can do this with a for loop that will run 10 times since there are 10 dogs
    // We will access each dog pointer by dereferencing with the brackets.
    for (int i = 0; i < 10; i++)
        orlandoShelter->arr[i] = (Dog *)calloc(1, sizeof(Dog));

    // Now that we have allocated 1 dog struct into each dog struct pointer, we can actually fill in the ages of each of the dogs.
    // This is where a really important concept comes up.
    // We have a total of 10 dog struct pointers that each have enough space for a single Dog struct.
    // Since they are Dog pointers we access the members inside using the (->) rather than the (.)

    // let's make the age of the first dog be 5 years
    orlandoShelter->arr[0]->age = 5;

    // Now we print just to make sure that it worked and that we don't get a seg fault
    printf("%d\n", orlandoShelter->arr[0]->age);

    // As a follow up, try to alter the code to where each Dog pointer can actually store 2 dogs each, and then try to
    // assign the age of the two dogs inside of the first dog pointer be 3 years and 7 years, respectively.

    return 0;
}
