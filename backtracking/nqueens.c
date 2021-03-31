#include <stdio.h>
#include <stdlib.h>

int isSafe(int **board, int row, int column, int n)
{
    // check if there is a queen on the same row.
    // if there is then this box is not safe
    for (int i = 0; i < n; i++)
        if (board[row][i] == 1)
            return 0; // return 0 to show that this row is not safe

    // check if there is a queen on the same column
    // if there is then this box is not safe
    for (int i = 0; i < n; i++)
        if (board[i][column] == 1)
            return 0; // return 0 to show that this column is not safe

    // check the diagonal going from top left to bottom right to see if there is a queen on this line
    // get to the index of the top left value of that diagonal line
    // Ex: if the board is 4x4 and the box you are checking is (1,2), then the top left box on the diagonal would be (0, 1)
    // The bottom right box on that same diagonal line would be (2,3), so that would be where we stop.
    // Notice that the bottom right limit will always be when either the row or the column are equal to (n - 1)
    int tempRow = row;
    int tempCol = column;
    // We know we have reached the top left limit of the diagonal when either one of the row or the column is 0.
    while (tempRow != 0 && tempCol != 0)
    {
        tempRow--;
        tempCol--;
    }
    // Now we check each box to see if there is a queen on the same diagonal until we reach the bottom right limit.
    // We know we have reached the bottom right limit when either one of the row or column = n - 1, but since we still want to check that box, we use just n in the conditional
    while (tempRow != n && tempCol != n)
    {
        // if we find a queen on this line we return 0 to show it is not safe
        if (board[tempRow][tempCol] == 1)
            return 0;
        // move diagonally down and to the right
        tempRow++;
        tempCol++;
    }

    // Now we check the diagonal going from bottom left to top right
    // Let's start at the bottom left and work our way up to the top right
    tempRow = row;
    tempCol = column;
    // We know we have reached the bottom left of a particular diagonal when either the column is 0 or the row is n - 1
    while (tempRow != n - 1 && tempCol != 0)
    {
        // we increase the row by 1
        tempRow++;
        // we decrease the column by 1
        tempCol--;
    }
    // that we have reached the bottom left limit of the diagonal we work our way up and to the right while checking if there is a queen in any box
    // We know we have reached the top right of a diagonal line when either the row is 0 or the column is n - 1.
    // Since we still want to check that box, we use -1 and n in the conditional
    while (tempRow != -1 && tempCol != n)
    {
        // if we find a queen on this line we return 0 to show it is not safe
        if (board[tempRow][tempCol] == 1)
            return 0;
        // move diagonally up and to the right
        tempRow--;
        tempCol++;
    }
    // if we make it past all of the above that means that the box we are looking at is in fact safe, so we return 1
    return 1;
}

int nQueens(int **board, int n, int numQueens)
{
    // first check that we have a valid board
    if (n == 0)
    {
        // if the board is 0x0 we return false because there is no solution for this
        return 0;
    }
    // check if there are 0 queens to place
    if (numQueens == 0)
    {
        // return 1 because that means we have placed all queens
        return 1;
    }

    // if we have to place any more than 1 queens then we can use backtracking
    // We start by going from box to box and checking if we can place a queen there
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            // if the current box is not a safe place to put a queen, then we skip it
            if (isSafe(board, i, j, n) == 0)
                continue;
            // if we get past the above if statement it means the current box is safe, so we place a queen on it.
            // We signify placing a queen on a box by putting a 1 in that box.
            board[i][j] = 1;
            // This is the part where we backtrack:
            // This will be different than typical recursion because our placement of a queen above may or may not be part of the final solution.
            // We will see if we find a solution by making our recursive call in an if statement.
            // If our recursive call returns 1, it means that we have found a valid solution for all of the queens so we can return 1 to show we found a solution.
            if (nQueens(board, n, numQueens - 1) == 1)
                return 1;
            // but if it returns a 0, it means it could not find a solution, so we have to try taking another path.
            // This means we have to remove the queen we placed above, since that didn't work.
            else
                board[i][j] = 0;
        }
    // If we make it out of the for loop it means we did not find a valid solution, so we return 0;
    return 0;
}

int main()
{
    // ask the user how many queens
    int n;
    printf("How many queens\n");
    scanf("%d", &n);

    // create the board that will be n x n
    int **board;
    board = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        board[i] = (int *)calloc(n, sizeof(int));

    // make every number in the board a zero to show that we have not placed any queens in it yet
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    // call our program that will place the n queens in such a way that they can't attack each other
    // This program will use backtracking, meaning it will check all configurations until it finds one that works
    // It returns an integer so that it can say whether we found a solution (1) or if we didn't find a solution (0)
    int isSolved = nQueens(board, n, n);

    // print whether or not we found a valid solution
    if (isSolved == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("\n"); // put a new line to show different rows
            for (int j = 0; j < n; j++)
                printf("|%d|", board[i][j]);
        }
        printf("\n\n");
    }

    else
        printf("There is no possible solution\n");

    return 0;
}