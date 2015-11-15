/*--------------------------------------------------------------------------*/
/* 
   Copyright (C) 2015  Aditya Malu maluaditya12@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "sudoku.h"
void evil(int **grid, int holes){
	int i, j = 0, iterctr = 0, k;
	time_t tt;
	srand(time(&tt));
	i = rand() % 9;
	int iorig = i + 1;
	for (k = 0; k < holes; k++)
	{
		j = j + 1;
		if( j == 9 ){
			i = i % 9 + 1;
			j = 0;
			if ( i == iorig )
				return;
		}
				
		if(grid[i][j] == 0){
			continue;
		}
		int temp = grid[i][j];
		grid[i][j] = 0;
		int num, count = 0;
			
	}
	return;
}

