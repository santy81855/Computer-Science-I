#include <stdio.h>

int main()
{
    printf("Hello everyone! My name is Santy, and I will be your SI leader this semester.\n");

    printf("Can you create a static array of names/words yet? This class moves quickly, so you should be getting comfortable with arrays this second week of class\n");

    printf("Here is an example problem with a solution to get you started.\n");

    /* Create a static array that can store 15 names. The names will be at most 20 characters long */

    /* background: 
	 - A name is a word. A word is made of characters. So each name will be an array of characters.
	 - Since we need to store multiple names, we need to create an array of names. This means we need an array of an array of characters.
	 - This is called a 2-D array because it is an array of an array. 
	*/

    // Answer:
    char listOfNames[15][21];
    /* Important Question to answer:
	- Can you explain why I gave each name a total of 21 characters if the problem said they will be 20 characters long at most?
	*/

    // The answer to this question is that, in C, all strings need to end with a null terminator '\0' so that we know when the word ends.
    // This adds an extra character to each word, meaning if the word is 20 letters long, we need to account for 21 letters total incluning the null terminator.

    // To step this problem up a bit, let's work on the VERY important skill of being able to fill up the arrays with information given by the user.

    /* CHALLENGE: 
        - Ask the user to input 15 names and place each name into a spot in the array. In the end, print out the list of names in reverse order of how they were input.
    */
    /* Tips: I recommend that you are careful making sure your loop only runs 15 times and that you are properly using the scanf function to intake the names */

    return 0;
}