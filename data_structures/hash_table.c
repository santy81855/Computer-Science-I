#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// usually keep the size about 50 % larger than the number of values you have to store
int tableSize;

// this is the struct for an entry in the hash table
typedef struct Entry
{
    // we will store the key, which is a string
    char *key;
    // we will store the value, which is also a string
    char *value;
    // We store a next pointer, since we will make a linked list on any indexes that have more than 1 value
    struct Entry *next;
} Entry;

// this is the struct for the hash table
typedef struct Table
{
    // the hash table is made of a list of entries
    Entry **entries;
} Table;

Table *createTable(int);
Entry *keyValuePairToEntry(char *key, char *value);
void placeEntry(Table *hashtable, char *key, char *value);
int hash(char *key);
char *findEntry(Table *hashtable, char *key);
void printEntries(Table *hashtable);

int main()
{
    // ask the user how many entries they want to input
    int numEntries;
    printf("Enter the number of entries\n");
    scanf("%d", &numEntries);

    // create the table keeping in mind the number of values they want to input
    Table *ht = createTable(numEntries);

    // allocate an array to be able to scan in the keys
    char **key = calloc(numEntries, sizeof(char *));
    // allocate an array to be able to scan in the values that correspond to the keys
    char **value = calloc(numEntries, sizeof(char *));
    // buffer is used to scan in the words so we can allocate just enough space for them
    char buffer[101];

    for (int i = 0; i < 5; i++)
    {
        // ask for the key
        printf("Key #%d: ", i + 1);
        // scan the key
        scanf("%s", buffer);
        // allocate enough space for the key
        key[i] = calloc(strlen(buffer), sizeof(char));
        // place the key in the key array
        strcpy(key[i], buffer);
        // ask for the value
        printf("value #%d: ", i + 1);
        // scan the value
        scanf("%s", buffer);
        // allocate enough space for the value
        value[i] = calloc(strlen(buffer), sizeof(char));
        // place the value in the value array
        strcpy(value[i], buffer);
        // place the key value pair entry into the hash table
        placeEntry(ht, key[i], value[i]);
    }
    // ask for a key to lookup in the table
    printf("Enter a key: \n");
    // scan the key the user wants
    scanf("%s", buffer);
    // print the value for the given key
    printf("The value is: %s\n", findEntry(ht, buffer));

    // print all of the entries in the hash table
    printEntries(ht);

    return 0;
}

void printEntries(Table *hashtable)
{
    // go through all of the indexes in the table
    for (int i = 0; i < tableSize; i++)
    {
        // place the current entry into a temp variable
        Entry *entry = hashtable->entries[i];
        // if the entry is null we don't print it so continue
        if (entry == NULL)
            continue;
        // print the index
        printf("index[%d]: ", i);

        // use an infinite loop to traverse any entries that are on the same index in the form of a linked list
        for (;;)
        {
            // print the key and value of each entry
            printf("%s=%s ", entry->key, entry->value);
            // if there are no more keys then exit the loop
            if (entry->next == NULL)
                break;
            // keep moving down the forever loop
            entry = entry->next;
        }
        printf("\n");
    }
}

// function to create the base table
Table *createTable(int numEntries)
{
    // A common way to determine how big to make the table is to make it 50% larger than the number of entries
    tableSize = numEntries * 1.5;

    // allocate table
    Table *hashtable = calloc(1, sizeof(Table));

    // allocate numEntries number of table entries
    hashtable->entries = calloc(tableSize, sizeof(Entry));

    // set each entry to null to show that they are empty
    for (int i = 0; i < tableSize; i++)
        hashtable->entries[i] = NULL;

    return hashtable;
}

char *findEntry(Table *hashtable, char *key)
{
    // use the hash function and the key to find the index on the table
    int index = hash(key);

    // place the entry at that index in a temp variable
    Entry *entry = hashtable->entries[index];

    // in case there are multiple entries in the same index, we will search for the one with the correct key
    while (entry != NULL)
    {
        // if we find the entry with the correct key we can return the value stored there
        if (!strcmp(entry->key, key))
            return entry->value;

        // if we get here, then there must be more entries to look at so move down one
        entry = entry->next;
    }

    // this means that the current key is not present so return NULL
    return NULL;
}

Entry *keyValuePairToEntry(char *key, char *value)
{
    // allocate space for a new entry
    Entry *entry = calloc(1, sizeof(Entry));
    // allocate space for the key and value in the entry
    entry->key = calloc(strlen(key) + 1, sizeof(char));
    entry->value = calloc(strlen(value) + 1, sizeof(char));

    // copy the key and value into the entry
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // set the next to null since we don't know what comes after
    entry->next = NULL;

    // return the new entry
    return entry;
}

void placeEntry(Table *hashtable, char *key, char *value)
{
    // determine which index the key gives when hashed
    int index = hash(key);

    // place the contents of the entry at that index into a temp variable
    Entry *entry = hashtable->entries[index];

    // if the entry is null that means the index is empty, so we put the new entry there
    if (entry == NULL)
    {
        // put the key and value in an entry struct
        hashtable->entries[index] = keyValuePairToEntry(key, value);
        return;
    }
    // if we get past the if statement above, it means there is already at least 1 entry at the index

    // create a temp entry to be able to store the value before where we place the entry
    Entry *prev;

    // since entry is also a linked list in case of collisions
    // we check if the key has already been stored, in which case we just update the value
    while (entry != NULL)
    {
        // if we find the key stored already
        if (strcmp(entry->key, key) == 0)
        {
            // update the value after freeing the current value
            free(entry->value);
            entry->value = calloc(strlen(value) + 1, sizeof(char));
            strcpy(entry->value, value);
            return;
        }

        // move down the linked list of the current entry
        // without losing access to the last entry in case we reach the end
        prev = entry;
        entry = prev->next;
    }

    // if we get here it's because we reached the end of the linked list and can now add the item
    prev->next = keyValuePairToEntry(key, value);
}

// this is the hash function
int hash(char *key)
{
    // this function will turn a key that is a string into a valid index in our table
    long long int value = 0;
    int key_len = strlen(key);

    // generic hash function that will give us a very large number potentially
    for (int i = 0; i < key_len; i++)
        value = value * 37 + key[i];

    // make sure the key is between 0 and tableSize
    value = value % tableSize;

    // return the value as an integer
    return (int)value;
}