#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
int count;
void create(){
	top = NULL;
}

void push(int data){
	if (top == NULL){
        	top =(struct node *)malloc(1*sizeof(struct node));
        	top->ptr = NULL;
        	top->info = data;
    	}
    	else
    	{
        	temp =(struct node *)malloc(1*sizeof(struct node));
        	temp->ptr = top;
        	temp->info = data;
        	top = temp;
    	}
    	count++;
}
int pop(){
    	int tempint;
    	top1 = top;
 
    	if (top1 == NULL)
    	{
        	printf("\n Error : Trying to pop from empty stack");
        	return 0;
    	}
    	else
        	top1 = top1->ptr;
		tempint = top->info;
    		free(top);
    		top = top1;
    		count--;
	return tempint;
}

void play(int **grid, int **solutiongrid){
	int tempgrid[9][9];
	int i, j;
	int undorow, undocol, undodigit;
	for (i = 0; i < 9; i++){
		for (j = 0; j < 9; j++){
			tempgrid[i][j] = grid[i][j];
		}	
	}
	create();
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
					push(row);
					push(col);
					push(grid[row][col]);
					grid[row][col] = digit;
					display(grid);
					break;
				}
				else{
					printf("this is already filled :/\n");
					break; 
				}
			case 2:
				undodigit = pop();
				undocol = pop();
				undorow = pop();
			
				if(undodigit == 0 && undorow == 0 && undocol == 0){
					printf("NO MORE UNDO: \n");
					display(grid);
					break;
				}
				else{
					grid[undorow][undocol] = undodigit;
					display(grid);
				//	printf("Yet to write this function\n");
					break;
				}
	
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
