/* 
This program tries to tackle the giant concept of pointers.
I recommend reading it slowly and looking at the print statements and making sure 
you understand each concept before moving on. There are some pointer challenges 
for you to attempt in this same folder so that you can practice using pointers.

Pointers are an extremely important part of this course so I recommend prioritizing 
learning how to use them asap.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // what are pointers?
    // First lets make sure we know a few vocab words: memory address, referencing, and dereferencing

    // lets look at the variable "a" below
    int a = 22;

    // variable "a" has a memory address where we now have the number 22 stored
    //if we want to know the address of variable "a" then we must REFERENCE it using the "address" operator, which is "&"
    printf("1) The address of variable a is: %p\n", &a); //to print an address the correct format specifier is %p

    // if we want to know the value stored at that address, then we can just print out the variable normally
    printf("2) The value at address %p is: %d\n", &a, a); //%d is the format specifier for an integer, but %i also works

    // So lets connect the dots a little here:
    // If referencing a variable will give us the address of that variable, then what is DEreferencing?
    // Dereferencing a memory address will give us the value stored there. So the two concepts are opposites.
    // The dereferencing operator is the asterisk, or *, which is typically read as "value pointed by ..." and we will show a good example below.

    // Also there are a couple of rules to dereferencing:
    // Rule 1) You can only dereference a memory address
    // Rule 2) You can only dereference a variable that has already been given a value, aka it has had memory allocated to it. Otherwise we would be dereferencing a null pointer
    // By following those rules we can avoid crashes.

    // Now lets do something funky just to test this.
    // We know we can reference variable a using the address operator(&) in order to get its address. So "&a" is an address.
    // If we want to see the actual number stored at that address, we can just take off the address operator. So "a" is a value, and it's 22 in this case.
    // If we were feeling particularly nasty, we could print the value at that address by dereferencing the address, which would look like the following:
    printf("3) The value stored at the memory address %p is: %d\n", &a, *&a);

    // In reality there is no need to do that because we have pointers!
    // However it is important to understand the concept: so let's talk through what we did there
    // We used the (*) to DEreference a variable that had just been referenced with the (&). This lead to us getting to the actual integer stored at that address.
    // Practice using those words while you code so that they become less disgusting
    // Since variable "a" is just a value, we referenced it with the address operator "&" to get its address.
    // Once we got the address of variable "a" we could then dereference it using the dereferencing operator "*"
    // Remember we had 2 rules to follow before we could dereference something.
    // We follow rule 1 because &a is a memory address
    // We follow rule 2 because variable a is statically allocated and therefore already has memory allocated to it.
    // if we were to read *&a out loud it would be "Value pointed by address of a". Quite a mouthful.
    // Luckily we almost never need to write weird stuff like that because we have pointers, which we will get into now.

    // Lets start of by declaring a pointer variable
    int *p;

    // The first thing to notice is that to declare a pointer variable, we must put an asterisk before the variable name.
    // This is important to notice because it leads us to our next point, which is: What type of value does a pointer store?
    // Well we know that a normal integer variable like "a" on line 13 will store an integer.
    // However, an integer pointer, like variable "p", will store a MEMORY ADDRESS.
    // So if we wanted to assign a value to "p", it would need to be an address, like so:
    p = &a;

    // We told "p" to store the address of "a". So if we wanted to print the actual number stored at that address we must DEreference the address:
    printf("4) The value stored at the memory address %p is: %d\n", p, *p);

    // Notice how "p" simply points to an address (this is why it's called a pointer), while "*p" points to the value at that address because we dereferenced it.
    // If we wanted to compare "p" to "a" we can say the following 2 things:
    // 1) p = &a (p is the same as &a)
    // 2) *p = a (when we dereference p, we get the value inside of the address it is storing, which is 22 in this case)

    // Do not move on past here until you can fully understand the following 5 statements as it may just confuse you. There is no rush:
    // 1) "a" is an integer variable that has been given an integer value of 22.
    // 2) When we reference it using the address operator(&), we can get its memory address.
    // 3) We can store that memory address in an integer pointer, which we have labeled as "p" in this case.
    // 4) When we print "p" by itself it will give us the address of "a", rather than an integer value, so we have to use the %p format specifier.
    // 5) To get the integer value stored at the address that "p" is storing we must dereference it using the dereferencing operator "*"

    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // The next part of this pointer course will require understanding a couple more vocab words: dynamic memory, static memory, contiguous memory, and memory allocation

    // The example above where we used variables "a" and "p" was an example of using a pointer to store static memory.
    // The reason for this is because variable a, the variable storing the value 22, is a static variable.
    // We never manually needed to allocate memory to it for it to be able to store an integer value.
    // In fact you can only manually allocate memory to pointers, which is what we are about to talk about.
    // Lets again begin by declaring a pointer:
    int *p2;

    /* The following line of code is commented out because it would cause the program to crash
	
	*p2 = 30;

	*/

    // Remember that a pointer will store a memory address, so to store a regular value like 30, we need to dereference it with the "*", which we did by writitg "*p2".
    // So the reason that the program would crash is not because we are assigning a value, but rather because we have not allocated any memory to "p2".
    // The reason that we didn't have a problem earlier with pointer "p" was because we just told "p" to hold the address of "a", which already had a statically allocated integer stored in it.
    // Since we are trying to directly assign a number to our pointer, we need to manually allocate the memory ourselves using either malloc() or calloc()

    // So lets allocate some memory to our pointer so that we can store an array of 5 integers:
    p2 = calloc(5, sizeof(int));

    // We could have used calloc or malloc, but I chose calloc()
    // As you see we said "p2 =" rather than "*p2 ="
    // The reason for that is that calloc returns an address, which is what a pointer stores.
    // Calloc gave "p2" 5 contiguous blocks of integer sized memory addresses for us to store integers in.
    // Contiguous means that they are next to eachother, which will be important since it means we have easy access to any of the 5 integers with only the address of the first one.

    // The value that calloc returned to the "p2" pointer is the memory address of the FIRST of the 5 blocks of memory. IMPORTANT

    // Let's fill up the 5 blocks with actual numbers one by one

    // Let's put a 1 in the first block by dereferencing the pointer using the *
    // So just to be clear p2 = 1 would be incorrect because p2 expects a memory address
    // So we must dereference it to tell it that we want to place a value inside that address
    *p2 = 1;

    // Our program would have crashed from the above line if we had not allocated memory using either calloc or malloc
    // Now lets print the number we just placed there as well as the address that it is stored in.
    printf("5) The address of the first block of memory is %p, and the value stored there is: %d\n", p2, *p2);

    // Now lets add a value to the second block, which is where things get interesting.
    // We have 2 options for our notation to add values to pointers.
    // We will use one way for block 2 and the other way for block 3

    // Lets add the number 2 to the memory address of block 2
    *(p2 + 1) = 2;

    // Lets analyze the above line of code:
    // We need to dereference the pointer to add a value, but since p2 stores the address of the first block, we had to add a 1 to move 1 block over into index 1 (remember indexes start at 0)
    // We are basically saying "we want to add a value to the address of block (1 + 1), which is block 2"
    // keep in mind that (p2 + 1) have to be in parentheses due to syntax
    // This only works because calloc and malloc returned CONTIGUOUS memory to us.

    // Lets print that value now as well as the memory address it is stored in:
    printf("6) The address of the second block of memory is %p, and the value stored there is: %d\n", p2 + 1, *(p2 + 1));

    // Notice that to print the address of block 2 we just said p2 + 1
    // And to get the number stored there we dereferenced it, so it was *(p2 + 1)

    // Now lets add the number 3 to the third block of memory by using the other method, which is much much nicer to look at
    p2[2] = 3;

    // Now before you go crazy telling me how I forgot to dereference "p2", look at the brackets around the 2
    // a pointer can be dereferenced by the "*" and it can also be dereferenced by the brackets []
    // And the added benefit of using the brackets is that you can specify which block you want to put the number in without using the star or having to have parentheses

    // Just to recap before moving on:
    // p2[2] is the same as *(p2 + 2)
    // It would not be p2[3] because that would be block 4, since we start counting at 0. so p2[0]->p2[1]->p2[2]->etc
    // It is not *(p2 + 3) because that would move us 3 blocks over onto block 4

    //Lets print the value at block 3 as well as its memory address
    printf("7) The address of the third block of memory is %p, and the value stored there is: %d\n", &p2[2], p2[2]);

    // Notice we can do the same thing with the address, instead of writing p2 + 2 to get the address of block 3 we can write &p2[2]

    // Lets fill in the last 2 blocks using the nicer method, which I recommend using in your programs for readability and ease
    p2[3] = 4;
    p2[4] = 5;

    // Now we can print all of the numbers we stored using a for loop
    for (int i = 0; i < 5; i++)
        printf("block %d: %d\n", i + 1, p2[i]);

    printf("\n"); // just a newline for formatting the output a little better

    // Now that we are done using p2, we can free it so we don't cause a memory leak
    free(p2);

    // We DO NOT free the first pointer we created, pointer "p", because it stores static memory. You do not free static memory.
    // As a rule of thumb, you should only every have as many free() function calls as you have calloc() and malloc() calls.

    //-------------------------------------------------------------------------------------------------------------------------------------------------

    // Now lets use pointers to dynamically store a word.
    // Since a word is made up of characters, we need to allocate enough space to store it.
    // So to store a word like "hello", we need to allocate 6 characters of space. One for each letter and 1 for the NULL terminator, which ends every string. h e l l o \0
    char *word = calloc(6, sizeof(char));

    // Now we can put the word in using strcpy() which uses the <string.h> header file
    strcpy(word, "hello");

    // We can print the whole word at once using the format specifier %s:
    printf("8) %s\n", word);

    // Or we can print it one character at a time using a for loop
    printf("9) Printing hello one character at a time: ");
    for (int i = 0; i < 5; i++)
        printf("%c", word[i]); // This will print each character at a time

    printf("\n");

    // We are now done using the "word" pointer, so we can free it
    free(word);

    // Storing a word is super useful for a lot of programs, but it can be ever more useful to store several words, like a sentence
    // To store more than 1 word in 1 variable we need to use a double pointer. So let's declare one:
    char **sentence;

    // A double pointer is interesting. We know that a single pointer stores the memory address of a certain value.
    // Well a double pointer stores 2 memory addresses.
    // The first pointer stores the memory address of the value
    // The second pointer stores the memory address of the first pointer
    // Another way to think about it is that with a double pointer you can make an array of single pointers.
    // Since a word requires a single pointer, it makes sense that an array of words like a sentence would require an array of pointers.

    // Lets allocate space to our new pointer so that we can store the sentence "My name is Santy"
    // First we need to allocate enough memory to hold 4 WORDS. Not 4 letters, but 4 words
    sentence = calloc(4, sizeof(char *));

    // The reason we use char * is because that is the data type of a word/string, while char is the data type of a letter.
    // Now we need to individually allocate enough space in each word be able to write our sentence.
    // So looking at our first word "My" we can see that it is 2 letters + 1 extra for the null terminator, so we allocate 3 characters of space
    sentence[0] = calloc(3, sizeof(char));

    // Now we can copy the word "My" into the pointer
    strcpy(sentence[0], "My");

    // Our next word is "name" so we allocate 5 characters of space
    sentence[1] = calloc(5, sizeof(char));
    strcpy(sentence[1], "name");

    // Next word is "is", so we allocate 3 characters of space
    sentence[2] = calloc(3, sizeof(char));
    strcpy(sentence[2], "is");

    // The last word is "Santy" so we allocate 6 characters of space
    sentence[3] = calloc(6, sizeof(char));
    strcpy(sentence[3], "Santy");

    // Now we should have a double pointer called sentence that stores 4 words which are "My" "name" "is" "Santy"
    // Lets print it out using a for loop
    printf("10) Printing a sentence using a double pointer and a for loop:\n");
    for (int i = 0; i < 4; i++)
        printf("%s ", sentence[i]);

    printf("\n");

    // And lastly if I wanted to access only one of those words, like "is" it would look like this:
    printf("11) The 3rd word in my sentence that I created is: %s\n", sentence[2]);

    // Now the last thing to do is to free the double pointer before the program ends
    // A tip for freeing memory is to free it in the reverse order in which you allocated it.
    // So since the first thing we allocated for "sentence" was the number of words that it can hold, we will free that last
    // The second thing that we allocated was how many letters each word would be, so that is what we must free first
    // We can make a loop to go through each of the 4 words to free all of the individual characters that we allocated:
    for (int i = 0; i < 4; i++)
        free(sentence[i]);

    // notice how we are freeing the same format in which we allocated. Ex: we said: sentence[0] = calloc(3, sizeof(char)); so we free(sentence[0]); etc

    // Now we have freed all of the individual characters of each word, but we still need to free the 4 words worth of space that we allocated.
    free(sentence);

    // again we allocated those 4 words worth of space by saying: sencence = calloc(4, sizeof(char *)); so we free it by saying free(sentence);

    // Now that we know how pointers work and can store integers, words, and sentences we should keep the following in mind:
    // 1) Coding in c is not typically this tedious. We are going through it step by step like this to make sure we understand it well.
    // 2) There will usually be more than 1 way to correctly do something, so you can find what you like better.
    // For example I prefer saying p2[0], p2[1], ... instead of *p2, *(p2 + 1), ... even though they mean the same thing
    // 3) The best way to get better is not only to read as much as you can but also to practice as much as you can. Especially the things you don't feel great about
    // because the more you write a certain thing the more sense that it makes to you. Pointers gave me trouble for a while because I avoided them.

    // Look at the files called "pointerChallenge1.c" and "pointerChallenge2.c" in the wordPress site to test your usage of pointers!

    return 0;
}
