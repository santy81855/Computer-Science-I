#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAP 3

typedef struct ArrayList
{
    // size = current size
    // cap = current cap
    int size, cap;
    // arr = the array of values that are being stored in the array list. In this case they are integers.
    int *arr;
} ArrayList;

// This function returns an ArrayList pointer and takes in no parameters
ArrayList *ArrayList_initialize();
// This function will add a number to the arraylist and not return anything
// It takes in an arraylist pointer and an integer as parameters
void ArrayList_add(ArrayList *, int);

int main()
{
    // before you can use a data structure you have to declare it.
    // I will be making our arraylist a pointer just because it is harder this way and it is good practice.
    ArrayList *al;

    // I have just declared an arraylist called 'al', but I still have to allocate memory for it.
    // Typically you only need one arraylist struct since the array is inside of the struct, as you can see in line 12
    al = (ArrayList *)calloc(1, sizeof(ArrayList));

    // Now that we have allocated 1 arraylist struct, we have to initialize the values inside the struct to something.
    // Since the arraylist is currently empty, we can set the size to 0. We use the arrow because 'al' is a pointer
    al->size = 0;

    // we can initialize the cap to any number that we want, and it is typically #defined at the top, so let's make it 3
    al->cap = INITIAL_CAP;
    // it is called initial cap because as the list grows, we will keep increasing the cap

    // Now we have to initialize our array to be able to store 3 numbers, which is our initial cap
    // We need to use dynamic memory allocation for this since the array needs to be able to expand when full
    al->arr = (int *)calloc(al->cap, sizeof(int));

    // Noticet that the typecast is just (int *) because that is what the variable is declared as in the struct
    // In the first parameter of the calloc function we put 'al->cap' because that stores the initial_cap

    // We have finished initializing everything inside of our arraylist
    /* 
    TIP: You would normally want to do everything we did after declaring al
    inside of a function so that you don't clutter the main function 
    */

    // I will create another arraylist to demonstrate how to put it in a separate function
    ArrayList *al2 = ArrayList_initialize();

    // We now have 2 arraylists but we will only use 'al' from now on

    // Now that we have initialized our arraylist we can put numbers inside of it!
    // This means we need to create an add function
    // Since we will only be changing the stuff inside of the struct rather than the struct itself we don't have to return anything
    // Let's add the numbers 1, 2, 3, and 4 to our arraylist
    ArrayList_add(al, 1);
    ArrayList_add(al, 2);
    ArrayList_add(al, 3);
    ArrayList_add(al, 4);

    // Now we print the arraylist to make sure everything was added correctly
    // we print only the number of items we have by using the size variable inside of the arraylist
    for (int i = 0; i < al->size; i++)
    {
        printf("%d\n", al->arr[i]);
    }

    // Now I have a couple of challenges for you to practice

    // Challenge 1 (medium): Create a function that will remove the current last element of the arraylist
    // challenge 2 (hard): Create a function that will take in a certain number as a parameter and removes it from the arraylist

    // TIP: Remember to update the size when you remove or add items from a list. Good Luck!

    return 0;
}

ArrayList *ArrayList_initialize()
{
    // it is common to name the variable that will be returned at the end of the function 'ret' or 'res'
    // Everything I write down here will be the same as what we did at the start of the main function to
    // initialize everything inside of the arraylist
    ArrayList *ret = (ArrayList *)calloc(1, sizeof(ArrayList));
    ret->size = 0;
    ret->cap = INITIAL_CAP;
    ret->arr = (int *)calloc(ret->cap, sizeof(int));
    // we then return this newly created arraylist back into the main function into 'al2'
    return ret;
}

void ArrayList_add(ArrayList *al, int data)
{
    // The first thing you need to do before adding a number to an arraylist is check if it is full.
    /* 
    The reason for this is that if it is already full and we add a number to it, we will go out of bounds of
    the memory we have allocated for the array
    */
    // we check if it is full by comparing the size to the current cap
    if (al->size == al->cap)
    {
        // if it is full then we have to increase the cap and then expand the array
        // If the array is full, we multiply the cap by 2 so we don't slow down our program by expanding too often
        al->cap *= 2;
        // Then we expand the array using realloc
        al->arr = realloc(al->arr, sizeof(int) * al->cap);
        // The first parameter of realloc is the array that we want to expand
        // The second parameter is the number of elements we want to be able to store
    }

    // Once we get here we know that the array is for sure not full because we got past the above if statement
    // Once we are here, we just have to add the number to the array since we know we have enough space
    // The index that we add it into is just the current size, since when we have 0 items we want to add the first number to index 0, etc.
    int index = al->size;
    // Now add the nmuber to that index in the array
    al->arr[index] = data;
    // Last thing we need to do is increase the size by 1 since we just added a number
    al->size++;
}