#ifndef DISPLAY_GAME_H_INCLUDED
#define DISPLAY_GAME_H_INCLUDED

#include "sudoku.h"


int cantChangeElements(int x,int y);
std :: string choosePuzzle();
std :: string b;
int cantChangeElements(int x,int y);
void givenumtoSolverArray(std :: string);
void givenumtoPlayground(std :: string);
void givenumtoCantchange(std :: string);
void displayMenu();

void checking();
void display();
void printAnswer();
void playing(int,int,int);

int solverarray[N][N];
int cantchange[N][N];
int playground[N][N];

void Interact();
void playtime();
int IfgameisCleared();
void prepare();


#endif // DISPLAY_GAME_H_INCLUDED
