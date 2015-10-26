#include<stdio.h>
#include<stdlib.h>
void play(int **grid, int **solutiongrid){
	int tempgrid[9][9];
	int i, j;
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			tempgrid[i][j] = grid[i][j];
		}	
	}
	while(1){
		printf("1.Fill a number.\n");
		printf("2.Undo\n");
		printf("3.Exit\n");
		printf("4 Solution\n\n");
		int option;
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("Enter Row, Colnumn and Digit \n");
				int row, col , digit;
				scanf("%d%d%d", &row, &col, &digit);
				
				if(digit < 0 || digit > 9)
				{
					printf("Wrong Input");
					display(grid);
					break;
				}
				else if( tempgrid[row][col] == 0 )
				{
					grid[row][col] = digit;
					display(grid);
					break;
				}
				else{
					printf("this is already filled :/\n");
					break; 
				}
			case 2:
				printf("Yet to write this function\n");
				break;
	
			case 3:
				exit(0);
		
			case 4:
				display(solutiongrid);
				exit(0);
		
			default: 
				printf("wrong entry");
					
		}

	}


}
