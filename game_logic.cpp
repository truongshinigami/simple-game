#include "sudoku.h"


bool SolveSudoku(int solverarray[N][N])
{
    int row, col;

//     If there is no unassigned location, we are done
    if (!FindUnassignedLocation(solverarray, row, col))
       return true; // success!

//     consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
//         if looks promising
        if (isSafe(solverarray, row, col, num))
        {
//             make tentative assignment
            solverarray[row][col] = num;

//             return, if success, yay!
            if (SolveSudoku(solverarray))
                return true;

//             failure, unmake & try again
            solverarray[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(int solverarray[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (solverarray[row][col] == UNASSIGNED)
                return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int solverarray[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (solverarray[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int solverarray[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (solverarray[row][col] == num)
            return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int solverarray[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (solverarray[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int solverarray[N][N], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !UsedInRow(solverarray, row, num) &&
           !UsedInCol(solverarray, col, num) &&
           !UsedInBox(solverarray, row - row%3 , col - col%3, num);
}

