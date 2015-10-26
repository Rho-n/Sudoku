#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 9
#define COLS 9
void final(int **grid, int remain, int rowres){
	int k, i, j;
	int max = 9, random;
	time_t tt;
	srand(time(&tt));
	for( k = 0; k < remain ; k++)
	{		
		i = rand() % max;
		j = rand() % max;
		if( grid[i][j] != 0 ){
			grid[i][j] = 0;
		}	
	}
}
int checkzeros(int **grid){
	int row, col, zero = 0;
	for( row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
		{
			if(grid[row][col] == 0)
				zero++;
		}
	}
	return zero;
}
int check(int **grid, int row, int col, int num)
{
	int rowStart = (row/3) * 3;
	int colStart = (col/3) * 3;
	int i, j;

	for(i=0; i<9; ++i)
	{
	        if (grid[row][i] == num) 
			return 0;
	        if (grid[i][col] == num) 
			return 0;
	        if (grid[rowStart + (i%3)][colStart + (i/3)] == num) 
			return 0;
	}
	return 1;
}

int fillit(int **grid, int row, int col)
{
	int i;
	if(row<9 && col<9)
	{
		if(grid[row][col] != 0)
		{
			if((col+1)<9) 
				return fillit(grid, row, col+1);
			else if((row+1)<9) 
				return fillit(grid, row+1, 0);
            		else 
            			return 1;
        	}
        	else
        	{
			for(i=0; i<9; ++i)
			{
				if(check(grid, row, col, i+1))
				{
					grid[row][col] = i+1;
					if((col+1)<9)
					{
						if(fillit(grid, row, col +1)) 
							return 1;
						else 
							grid[row][col] = 0;
            			        }
					else if((row+1) < 9)
                	    		{
                	        		if(fillit(grid, row+1, 0)) 
							return 1;
                	        		else 
							grid[row][col] = 0;
                	    		}
                	    		else 
						return 1;
                		}
            		}
        	}
        	return 0;
	}
	else return 1;
}

void display(int **grid)
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(grid[i][j] == 0)
				printf("* ");
			else
				printf("%d ",grid[i][j]);
		}
		printf("\n");
	}
	printf("-----------------\n");
	return;
}

int checkrow(int **grid, int row, int col, int num){
	int k;
	for ( k = 0; k < COLS; k++ ){
		if( grid[row][k] == num )
			return 0;
	}
	
	return 1;
}
int checkcol(int **grid, int row, int col, int num){
	int k;
	for ( k = 0; k < ROWS; k++ ){
		if( grid[k][col] == num )
			return 0;
	}
	
	return 1;
}

int checkblock(int **grid, int row, int col, int num){
	row = (row/3) * 3;
	col = (col/3) * 3;
	int r, c;
	for ( r = 0; r < 3; r++ ){
		for ( c = 0 ; c < 3 ; c++ ){
			if( grid[row +r][col + c] == num )
				return 0;
		}
	}
	return 1;
}
void fillinrandom(int **grid){ 		/*fills the grid with random no.s*/ 
	int max = 9, random;
	time_t tt;
	srand(time(&tt));
	
	int k;
	for( k = 0; k < 11 ; k++ ){
		int i, j;
		i = rand() % max;
		j = rand() % max;
		if( !grid[i][j] ){
			int num = rand() % max + 1;
			while(1) {
				int n1 = checkrow(grid, i , j ,num);
				int n2 = checkcol(grid, i , j ,num); 
				int n3 = checkblock(grid, i , j ,num);
				if( n1 == 1 && n2 == 1 && n3 == 1 )
				{
					grid[i][j] = num;
					break;
				}
				else
				{
					num = (num + 1)	% max;
				}
			}
		}
	}
}

void makezero(int **grid){  /* Makes all the elements of the grid to zero*/
	int i, j;
	for( i = 0; i < ROWS; i++ ){
		for( j = 0; j < COLS; j++ )
			grid[i][j] = 0;
	}
}

void copy(int **grid, int **solutiongrid){
	int i, j;
	for( i = 0; i < ROWS; i++ ){
		for( j = 0; j < COLS; j++ )
			solutiongrid[i][j] = grid[i][j];
	}

}
int main(){
	int i, j;
  /*  allocate array of pointers  */
	int **grid =(int **)malloc( ROWS * sizeof(int *) );
      	if( grid == NULL ){
		printf("\nError allocating memory\n");
		exit(1);
	}
  /*  allocate each row  */
  	for( i = 0 ; i < ROWS ; i++ ) {
    		grid[i] =(int *) malloc ( COLS * sizeof(int) );
  	}
  	
  	if(grid[i-1]==NULL) {
		printf("\nError allocating memory\n");
		exit(1);
	}	
	
	int **solutiongrid =(int **)malloc( ROWS * sizeof(int *) );
      	if( solutiongrid == NULL ){
		printf("\nError allocating memory\n");
		exit(1);
	}
    	for( i = 0 ; i < ROWS ; i++ ) {
    		solutiongrid[i] =(int *) malloc ( COLS * sizeof(int) );
  	}
  	
  	if(solutiongrid[i-1]==NULL) {
		printf("\nError allocating memory\n");
		exit(1);
	}	

  /* Makes all the elements of the grid to zero*/
	makezero(grid);
	makezero(solutiongrid);
	fillinrandom(grid);
	
	int level;
	printf("LEVELS :->\n");
	printf("1.Extremely Easy\n");	
	printf("2.Easy\n");	
	printf("3.Medium\n");	
	printf("4.Difficult\n");	
	printf("5.Evil\n");	
	scanf("%d", &level);
	
	switch(level)
	{
	case 1:
		if(fillit(grid, 0 , 0))
		{
			copy(grid, solutiongrid);	
			exteasy(grid);
			int zeros = checkzeros(grid);
			display(grid);
			play(grid, solutiongrid);
		}
		break;
	case 2:
		if(fillit(grid, 0 , 0))
		{	
			
			copy(grid, solutiongrid);	
			easy(grid);
			int zeros = checkzeros(grid);
			display(grid);
			play(grid, solutiongrid);
		}
		break;
	case 3:
		if(fillit(grid, 0 , 0))
		{	
			int holes = 49 - rand() % 4;
			copy(grid, solutiongrid);	
			medium(grid, holes);
			int zeros = checkzeros(grid);
			int remain = holes - zeros;
			final(grid, remain, 3);
			display(grid);
			play(grid, solutiongrid);
//			display(grid, solutiongrid);
		}
		break;
	case 4:
		if(fillit(grid, 0 , 0))
		{
			copy(grid, solutiongrid);	
			int holes = 53 - rand() % 4;
			diffi(grid, holes);
			int zeros = checkzeros(grid);
			int remain = holes - zeros;
			final(grid, remain, 3);
			display(grid);
			play(grid, solutiongrid);
//			display(grid, solutiongrid);
			
		}
		break;	
	case 5:
		if(fillit(grid, 0 , 0))
		{	
			copy(grid, solutiongrid);	
			int holes = 57 - rand() % 4;
			evil(grid, holes);
			int zeros = checkzeros(grid);
			int remain = holes - zeros;
			final(grid, remain, 3);
			display(grid);
			play(grid, solutiongrid);
//			display(grid, solutiongrid);
		}
		break;
	default:
		printf("Wrong Entry");
		exit(0);
	}

	return 0;	
}
	

