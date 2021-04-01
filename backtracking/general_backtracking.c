#include <stdio.h>
#include <stdlib.h>

int BackTracking()
{
    // base case - return a 1 if we have reached a valid solution
    // in n queens we return a 1 when the number of queens to place reaches 0 because there are no more queens to place
    // in sudoku, we return a 1 when all of the spots on the board are filled (have a function that finds any blank boxes)

    // since we have not found a solution yet, we can try another possibility using the isValid function
    // in n queens that means we find the next safe place to put a queen and place a queen there
    // in sudoku we find the next empty spot, and then try one of the 1-9 numbers we can place on it

    // call the recursive step and see if it returns a 1
    // return a 1 to show that we found a solution

    // if the recursive call returns a 0, it means we did not find a solution with the value we placed, so we just remove it (BACKTRACK)

    // say we were using a for loop to go from box to box, and we make here out of the for loop without having a found a solution
    // return 0  to show that there is no solution for this problem
}

int main()
{
    // basic backtracking program

    // its going to return either 0 and 1 to show if successful (solution) or unsuccessful (no solution)
    int backTracking()

        return 0;
}