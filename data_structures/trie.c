#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// watch the first 4 minutes of this video before looking at this code if you've never seen a trie before
// Link: https://www.youtube.com/watch?v=giiaIofn31A

// define the length of your alphabet, we use english so 26 letters
#define ALPHABET 26

// the struct of a trie
typedef struct Node
{
    // this lets you know if the current letter is the end of a word in our trie
    int endOfWord;
    // Each node will have 26 children that are initially set to null
    struct Node *children[ALPHABET];
    // Note that we don't store actual letters in the node
} Node;

Node *createTrie();
void insertWord(Node *, char *);
int search(Node *, char *);

int main()
{
    // create the root of the trie
    Node *root = createTrie();

    // add some words to the trie
    insertWord(root, "hello");
    insertWord(root, "helicopter");
    insertWord(root, "hi");

    // look up a word
    int found = search(root, "hell");
    if (found == 1)
        printf("The word 'hell' is in the trie\n");
    else
        printf("The word 'hell' is not in the trie\n");

    // look up another word
    found = search(root, "hello");
    if (found == 1)
        printf("The word 'hello' is in the trie\n");
    else
        printf("The word 'hello' is not in the trie\n");

    return 0;
}

Node *createTrie()
{
    Node *ret = calloc(1, sizeof(Node));
    ret->endOfWord = 0;
    // initialize every child to null when you create a new node
    for (int i = 0; i < ALPHABET; i++)
        ret->children[i] = NULL;
    return ret;
}

void insertWord(Node *root, char *word)
{
    // Since each index from 0 - 25 represents a letter, this will keep track of which letter we need to check
    int index;
    // Get the length of the word so we know how many letters to check for
    int len = strlen(word);

    // use a temporary variable to traverse the tree so we don't mess anything up
    Node *currentNode = root;

    // go through each letter in the word using a for loop
    for (int i = 0; i < len; i++)
    {
        // determine what index the current letter should correspond to
        index = word[i] - 'a';

        // check if the child at that index is currently null or not
        // if it is null, it means we need to allocate space for that child since we haven't used it yet
        if (currentNode->children[index] == NULL)
            currentNode->children[index] = createTrie();

        // Now that the child is for sure allocated we can move into it so we can check the next letter
        currentNode = currentNode->children[index];
    }

    // Finishing the for loop means we have moved our way down the trie to the last letter in the word
    // So we need to make sure that we specify that this is the end of a word
    currentNode->endOfWord = 1;
}

// it returns an int so that we can return 0 if we don't find the word and return 1 if we do find the word
int search(Node *root, char *word)
{
    // This function runs very similarly to the insert function
    int index;
    int len = strlen(word);

    Node *currentNode = root;

    for (int i = 0; i < len; i++)
    {
        index = word[i] - 'a';
        // if at any point we have not allocated the child that corresponds to a certain letter in the word, it means the word is not in the trie, so return 0
        if (currentNode->children[index] == NULL)
            return 0;
        // otherwise we keep going to each letter's corresponding index
        currentNode = currentNode->children[index];
    }
    // if we make it to the end of the for loop, it means that so far the word we are looking for is in the trie, but we have to make sure that it isn't just part of another word by checking the endOfWord
    // so if it is in fact the end of a valid word we return 1, otherwise we return 0
    if (currentNode->endOfWord == 1)
        return 1;
    else
        return 0;
}