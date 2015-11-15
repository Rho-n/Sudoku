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
void easy(int **grid){
	
	int i, j, max = 14, k;
	time_t tt;
	srand(time(&tt));
	int holes = 45 - rand() % max;
	for (k = 0; k < holes; k++)
	{	
	
		i = rand() % 9;
		j = rand() % 9;
		
		if(grid[i][j] == 0){
			i = (i + 1) % 9;
			j = (j + 1) % 9;	
		}
		int temp = grid[i][j];
		grid[i][j] = 0;
		int num, count = 0;
		for( num = 1; num < 10; num++ )
		{
			if(check(grid, i, j, num))
				count++;
		}
				
		if(count > 1){
			grid[i][j] = temp;
			k--;
		}
		else{
			int x, cnt = 0, cnt1 = 0;
			for(x = 0; x < 9; x++)
			{	
				if(grid[i][x])
					cnt++;
				if(grid[x][j])
					cnt1++;		
			}
			if(cnt < 4 || cnt1 < 4){
				grid[i][j] = temp;
				k--;
			}
			else
				grid[i][j] = 0;
		}
	}
	return;
}

