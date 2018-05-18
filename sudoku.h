#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <vector>
#define UNASSIGNED 0
#define N 9

// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(int solverarray[N][N], int &row, int &col);

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int solverarray[N][N], int row, int col, int num);
bool UsedInCol(int, int, int);
bool UsedInRow(int, int, int);
bool UsedInBox(int, int, int);
bool SolveSudoku(int solverarray[N][N]);

#endif // SUDOKU_H_INCLUDED
