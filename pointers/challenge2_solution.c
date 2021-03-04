#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Please enter a number from 0 to 10\n");
    int n;
    scanf("%d", &n);

    // allocate enough space in teh double pointer for n names
    char **names = calloc(n, sizeof(char *));

    char temp[101]; // assuming the longest name will be 100 characters since it wasn't specified
    int len;
    // scan all of the names
    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        len = strlen(temp);
        names[i] = calloc(len + 1, sizeof(char));
        strcpy(names[i], temp);
    }

    // print the list of names
    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    // free the memory used
    for (int i = 0; i < n; i++)
        free(names[i]);
    free(names);

    return 0;
}