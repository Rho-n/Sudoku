#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void evil(int **grid, int holes){
	int i, j = 0, iterctr = 0, k;
	time_t tt;
	srand(time(&tt));
	printf("holes-> %d\n", holes);
	i = rand() % 9;
	iorig = i + 1;
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
		for( num = 1; num < 10; num++ )
		{
			if(check(grid, i, j, num))
				count++;
		}
				
		if(count > 4){
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
			if(cnt < 1 || cnt1 < 1){
				grid[i][j] = temp;
				k--;
			}
			else
				grid[i][j] = 0;
		}
	}
	return;
}

