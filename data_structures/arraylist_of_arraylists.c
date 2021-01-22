/*
Program of an arraylist that is holding an array of arraylists.
The concept behind this program is as follows:
- There is 1 school (big array list)
- That school has an array of students inside, which makes the school an arraylist (we will ask the user how many students)
- Each student has a list of classes that they have taken in the past, which makes each student an arraylist
- We will start with an empty school, and ask the user to input how many students they want to put in. 
- The user will then input a name followed by the name of a class, ex: josh calculus
- Our job is to properly add josh to the school (big list) and to add calculus to his list of classes (smaller arraylist)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the initial cap for the number of students we can have in our school can be anything. I will use 3
#define INITIAL_CAP 3
// the max length for a name or class will be 100 characters, so we make it 101 to account for the null terminator
#define MAX_LENGTH 101

// We will call the arraylist that holds the smaller arraylists School for clarity
typedef struct School
{
    // All arraylists have to have a variable to keep track of the size as well as to keep track of the current cap
    int size, cap;
    // The school has an array of students inside of it, which is why the school is an arraylist.
    // We could make the array either a single or double pointer, but I will go with a double pointer.
    // The reason I chose to go with a double pointer will be highlighted in relevant functions.
    struct Student **studentArray;
} School;

// We will call the smaller arraylists Student, since every student has a list of classes that they've taken
typedef struct Student
{
    int size, cap;
    // Each student has a name as well, which we need to store
    // I decided to make name a pointer, so that we can practice dynamic memory allocation.
    char *name;
    // Each student has an array of classes that they have taken, which is why student is an arraylist
    char **classes;
} Student;

// Start by looking at the main function, since every function below will be talked about when we get to it.

// Since we are returning an initialized School pointer into ucf in the main, we make the return type (School *)
School *initializeSchool();

// Since we don't need to return anything, it has a void return type. The only parameter we pass is the school pointer
void addStudent(School *);

int main()
{
    // The first thing we want to is create the school. We can't have students taking classes if there is no school.
    // We will call the school ucf.
    School *ucf;

    // Now that we declared the school, we need to initialize all of the variables inside of it.
    // We will use a function to initialize it for us so that we don't clutter up the main function.
    // Look for the function prototype above the main function to see info on how we declare this function.
    // Look for the function under the main to see the code inside of it.
    ucf = initializeSchool();
    // Once we come back from the initializeSchool function, ucf now has enough space to store the initial cap number of students.

    // Now we have an initialized school with 0 students inside so we can ask the user how many students they want to put in. We will store that number in 'n'.
    int n;
    printf("How many students do you want to put into your school?\n");
    scanf("%d", &n);

    // Now that we know how many students, we can ask the user to input the name of each student followed by the class they want to add.
    printf("Enter the name of each student followed by a class.\n");
    // We will use a for loop to let the user input all the students.
    // We will need to create a function that will add each student and their class to their respective arraylists
    for (int i = 0; i < n; i++)
    {
        addStudent(ucf);
    }

    // now we check to see if the students have been added correctly by printing the name of all the students we have so far
    for (int i = 0; i < ucf->size; i++)
        printf("Name #%d = %s\n", i + 1, ucf->studentArray[i]->name);

    // Now we can ask the user to enter a name and we will print out all of the classes that student is taking
    printf("Enter a name to see all classes that student is taking\n");
    char name[MAX_LENGTH];
    scanf("%s", name);

    // We can linearly search through the arraylist to see if the name is in the list. We can use a variable called index to keep track of where it is if we find it.
    int index = -1;
    for (int i = 0; i < ucf->size; i++)
        if (strcmp(name, ucf->studentArray[i]->name) == 0)
            index = i;

    // if we find the name the index will not be -1 anymore
    if (index != -1)
    {
        // We just have to print the list of classes of this student now using another for loop
        for (int i = 0; i < ucf->studentArray[index]->size; i++)
            printf("Class #%d: %s\n", i + 1, ucf->studentArray[index]->classes[i]);
    }
    // if we did not find the name then there is nothing to print
    else
        printf("That name is not in the list\n");

    // Now to end this crazy program all we have to do is free everything so we don't have a memory leak
    // Normally we would free it in another function to save space, but I will just do it in the main because it's getting late
    // The main thing to remember while freeing something is: "Will I be losing access to something else if I free it?" if the answer is yes then you're freeing in the wrong order
    // Remember to free in reverse order, so we need to free all of the classes of each person as well as the name of each person and the classes list of each person and finally the student pointer of that student
    for (int i = 0; i < ucf->size; i++)
    {
        for (int j = 0; j < ucf->studentArray[i]->size; j++)
        {
            free(ucf->studentArray[i]->classes[j]);
        }
        free(ucf->studentArray[i]->name);
        free(ucf->studentArray[i]->classes);
        free(ucf->studentArray[i]);
    }

    // Now we free the list of student pointers
    free(ucf->studentArray);

    // and finally we free the school pointer
    free(ucf);

    return 0;
}

School *initializeSchool()
{
    // we start by creating a school pointer that we will name ret since we will return it at the end
    // we will allocate 1 school struct into it, since we only need 1 school.
    School *ret = (School *)calloc(1, sizeof(School));
    // We set the initial size of the school to 0 since it is empty at first
    ret->size = 0;
    // We set the inital cap to be whatever we defined at the top of the code
    ret->cap = INITIAL_CAP;
    // we initialize the double pointer inside to be able to hold as many students as whatever we set the initial cap to be
    ret->studentArray = (Student **)calloc(INITIAL_CAP, sizeof(Student *));
    // We are now ready to return this initialized school pointer back to the main function under the name ucf
    return ret;
}

void addStudent(School *ucf)
{
    // We start by taking in the name of the student as well as the name of the class the student is taking.
    // We defined max length at the top to be 101, meaning that the student name and class can be at most 100 characters.
    char name[MAX_LENGTH];
    scanf("%s", name);
    char class[MAX_LENGTH];
    scanf("%s", class);

    // We get the length of the name and the classes so that we can allocate appropriately
    int name_size = strlen(name);
    int class_size = strlen(class);

    // Now that we have the name, we can put it into the arraylist at the appropriate place, which is the part that confuses people the most.
    // Let's talk it out.
    // We know that we are keeping track of how many students we have so far by using the variable called size inside of the school struct.
    // As an example, if we have 3 students total, that means they occupy indexes 0, 1, and 2.
    // - This means that the current size of the arraylist also tells us the correct index in which to place a new student.
    // Before we add the student however, we should check that we haven't added them already so we don't create a duplicate.
    // We can do this using a for loop to look through all the students we have already and comparing them to the name that we have just scanned.
    // we can also use a variable called index to store the index of the name if we find it. If we don't find it then we have to add the name.
    int index = -1;
    for (int i = 0; i < ucf->size; i++)
    {
        // if the name of the current student in the loop is the same as the name then we update the index variable so we know where it is.
        if (strcmp(name, ucf->studentArray[i]->name) == 0)
            index = i;
    }

    // if the name is not new then we just add the class to the appropriate index, which we got from the for loop
    if (index != -1)
    {
        // We first check to see if the student's classes arraylist is currently at its cap
        // if it is then we have to expand it with realloc
        if (ucf->studentArray[index]->size == ucf->studentArray[index]->size)
        {
            // a good way to expand a cap is by multiplying it by 2 to reduct the frequency at which we need to expand it.
            ucf->studentArray[index]->cap *= 2;
            // We then use realloc to make the number of classes the student can have equal to the new cap we just doubled
            ucf->studentArray[index]->classes = realloc(ucf->studentArray[index]->classes, sizeof(char *) * ucf->studentArray[index]->cap);
        }
        // Now that we know we have space to add the class we need to allocate enough space for this particular classes name at the right index
        ucf->studentArray[index]->classes[ucf->studentArray[index]->size] = (char *)calloc(class_size + 1, sizeof(char));
        // Then we can copy it in that spot we just allocated for it
        strcpy(ucf->studentArray[index]->classes[ucf->studentArray[index]->size], class);
        // Then we finally update the size of the classes arraylist by 1 since we just added a class to this students list.
        ucf->studentArray[index]->size++;
    }

    // if the name is a new name then we have to add it to the school
    else
    {
        // Before we can add it though, we have to make sure that the list is not at the current cap.
        // if it is then we have to first update the cap and then use realloc to make the array as large as the new cap
        if (ucf->size == ucf->cap)
        {
            ucf->cap *= 2;
            ucf->studentArray = realloc(ucf->studentArray, sizeof(Student *) * ucf->cap);
        }
        // Before we can add a student's info to this student struct pointer, we have to allocate 1 student struct into it
        ucf->studentArray[ucf->size] = (Student *)calloc(1, sizeof(Student));
        // Now that we know that we have space in the list for this student, we add the name to his struct right after we allocate enough space for the specific name
        ucf->studentArray[ucf->size]->name = (char *)calloc(name_size + 1, sizeof(char));
        // Remember that the index of this student is ucf->size, since we are adding them to the first open spot in the list
        strcpy(ucf->studentArray[ucf->size]->name, name);
        // Now that we have added the name, we can create this new student's smaller arraylist so that we can add the class to it.
        // We first allocate the initial cap number of spots to this new students class arraylist.
        ucf->studentArray[ucf->size]->classes = (char **)calloc(INITIAL_CAP, sizeof(char *));
        // Then we set the initial size of the classes arraylist to 0 since we haven't added any classes to this new student
        ucf->studentArray[ucf->size]->size = 0;
        // Then we set the cap of this student's classes arraylist to the initial cap
        ucf->studentArray[ucf->size]->cap = INITIAL_CAP;
        // We now have to allocate the right number of characters for this specific class (gross line)
        // All this line is saying is:
        // - We are allocating space for the class at the correct index inside of the student at the correct index inside of the school
        ucf->studentArray[ucf->size]->classes[ucf->studentArray[ucf->size]->size] = (char *)calloc(class_size + 1, sizeof(char));
        // Now we can copy the class into the student's classes list at the appropriate index
        strcpy(ucf->studentArray[ucf->size]->classes[ucf->studentArray[ucf->size]->size], class);
        // finally we update the size of the student's classes arraylist
        ucf->studentArray[ucf->size]->size++;
        // and we also update the size of the list of students since we just added this new student
        ucf->size++;
    }
}