#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void diffi(int **grid, int holes);
void easy(int **grid);
void evil(int **grid, int holes);
void exteasy(int **grid);
void medium(int **grid, int holes);
int check(int **grid, int row, int col, int num);
//void display(int **grid);
void play(int **grid, int **solutiongrid);
