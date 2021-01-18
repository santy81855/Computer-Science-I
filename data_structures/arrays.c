#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This code is meant to be looked at line by line
// Make sure to look back at it as we learn more about pointers and dynamic memory allocation

int main()
{
    // this is how you create a static int array that can hold 10 integers
    int array1[10];

    // and this is how you fill it with the numbers 1 - 10
    for (int i = 0; i < 10; i++)
    {
        array1[i] = i + 1;
    }

    // this is how you create a dynamic int array that can hold 10 integers
    int *dynamicArray1 = calloc(10, sizeof(int));

    // you fill it the same way
    for (int i = 0; i < 10; i++)
    {
        dynamicArray1[i] = i + 1;
    }

    // this is how you create a static character array that can hold 10 letters
    // since it is not a word, we don't need to know when it ends with the null terminator
    char array2[10];

    // this is how you would create a static character array that will hold a 5 letter word
    char array3[6];

    // this is how you put a word in the array
    strcpy(array3, "hello");

    // you can also scan a word directly into the variable
    scanf("%s", array3);

    // this is how you create a dynamic character array that can hold a 10 letter word
    char *dynamicArray3 = calloc(11, sizeof(char));

    // you put the word in the array the same way
    strcpy(dynamicArray3, "randomword");

    // this is how you create a static list of 10 words where each word can have at most 5 letters
    char listOfWords[10][6];

    // this is how you fill it with words from the user
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", listOfWords[i]);
    }

    // this is how you create a dynamic list of 10 words.
    char **dynamicListOfWords = calloc(10, sizeof(char *));

    // this is how you fill it with actual words
    char buffer[101];
    int length;

    for (int i = 0; i < 10; i++)
    {
        scanf("%s", buffer);
        length = strlen(buffer);
        dynamicListOfWords[i] = calloc(length + 1, sizeof(char));
    }

    return 0;
}