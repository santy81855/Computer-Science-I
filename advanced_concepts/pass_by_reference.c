/*
This program will demonstrate the difference between passing by value and passing by reference using struct pointers.
This will be important knowledge very soon as we come across arraylists, linked lists, and binary trees and other data structures.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    int age;
    char name[21];
} Person;

// We pass by value in this one
void changePerson(Person);
// We pass by reference in this one
void changePersonByReference(Person *);

void changePointer(Person *);
void changePointerByReference(Person **);

int main()
{
    // Let's declare a Person struct called person1
    Person person1;
    // It is static since I did not declare a person struct pointer.
    // Let's initialize the variables inside
    // This person is 20
    person1.age = 20;
    // Her name is Angela
    strcpy(person1.name, "Angela");

    // Let's create a function that can alter the values of this person and pass in the person1 struct
    changePerson(person1);

    // now let's print to see if the changes took effect
    printf("1) The name of this person is %s and their age is %d\n", person1.name, person1.age);

    // Notice how the function did not actually change the values of the struct we passed in.
    /* 
    The reason for this is that we passed in a copy of our struct, rather than the real thing, so 
    any changes made inside the function 'changePerson' do not actually affect person1. We have passed-by-value.
    */

    // Now let's try again with another function, but this time we will pass-by-reference.
    changePersonByReference(&person1);
    // Notice that the only difference is that we passed in the address of the struct.

    // Now we print to see if the changes take effect.
    printf("2) The name of this person is %s and their age is %d\n", person1.name, person1.age);

    // We can see that the changes did take effect this time because we didn't edit a copy, but rather we edited the real thing.

    // This leads us to why it can be a good idea to use dynamic memory (pointers) when we use structs and other variables.
    // Let's demonstrate by declaring a Person struct pointer called personPointer and allocating 1 person struct into it
    Person *personPointer = (Person *)calloc(1, sizeof(Person));

    // Let's put the age and name inside
    personPointer->age = 100;
    strcpy(personPointer->name, "betty");

    // If we want to edit the name and age of this person, we can pass it into the same function we used above
    changePersonByReference(personPointer);
    // Notice that we did not have to put the address of (&) symbol in front of it.
    // The reason for this is that the personPointer is already storing the address of the struct.
    // Let's print the person just to make sure that it worked
    printf("3) The name of this person is %s and their age is %d\n", personPointer->name, personPointer->age);

    // We can see that it did indeed work.

    // Now let's craete a function that will set our pointer to NULL, making us lose the address of the struct we had stored in there
    changePointer(personPointer);

    // since we just set the pointer to null, we can expect the program to crash from the following line that tries to dereference null
    printf("4) The age of this person is %d\n", personPointer->age);

    // But the program doesn't crash, and it even prints the right age.
    // the reason for this is that while we can edit what is inside of the struct when passing in the pointer, we can't edit the pointer itself.
    // This means that we can change the values inside the address that the pointer is storing, but we can't change the address that is being stored itself.
    // The only way for us to change the pointer itself would be to pass in the pointer by reference.
    changePointerByReference(&personPointer);

    // Since we added the address of (&) symbol in front of the pointer, this means we are passing in an address of an address, which is the equivalent of a double pointer.
    // This is why the parameter in the function below is a double pointer.
    // Let's see if we were able to change the pointer into a null pointer by uncommenting the next printf line and running the code.
    // If it crashes with a seg fault it means we successfully changed the address inside of the pointer to NULL;

    // printf("5) The age of this person is %d\n", personPointer->age);

    /* 
    This is a very important concept that will be applied when we get into data structures like linked lists and binary trees,
    so I recommend going over this now and practicing passing in different variables by value and by reference and seeing 
    what things you can and can't do with one method or the other.
    */

    /* 
    CHALLENGE: 
    
    I will declare a variable below called "personArr" and fill it with stuff. 
    Create a function that will change the name and age of the 3rd person only. 
    Change the name to "mike".
    change the age to 50.
    You can only pass in the struct of the 3rd person, aka personArr[2], you cannot pass in the entire personArr variable. 
    You can of course pass in the address of the struct of the 3rd person if you need to.

    */

    Person *personArr = (Person *)calloc(5, sizeof(Person));

    personArr[2].age = 10;
    strcpy(personArr[2].name, "alex");

    return 0;
}

void changePerson(Person p)
{
    // let's make the age of the person be 30
    p.age = 30;
    // Let's make the name be 'bob'
    strcpy(p.name, "bob");
}

void changePersonByReference(Person *p)
{
    // Since we passed in the address of a struct, we must use the arrow (->) now to get to the values inside the address
    // let's make the age of the person be 30
    p->age = 30;
    // Let's make the name be 'bob'
    strcpy(p->name, "bob");
}

void changePointer(Person *p)
{
    p = NULL;
}

void changePointerByReference(Person **p)
{
    // Since we passed in the pointer by reference, we have to dereference it to get to the address inside
    *p = NULL;
}