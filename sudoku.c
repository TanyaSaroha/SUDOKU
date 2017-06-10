#include<stdio.h>
#include<stdlib.h>

int fill(int a[][9], int row, int col, int num)
{
	int r = (row/3) * 3;
	int c = (col/3) * 3;
	int i;
	for(i=0;i<9;++i)
	{
		if(a[row][i] == num) return 0;
		if(a[i][col] == num) return 0;
		if(a[r + (i%3)][c + (i/3)] == num) return 0;
	}
	return 1;
}

int sudoku(int a[][9], int row, int col)
{
	int i;
	if(row<9 && col <9)
	{
		if(a[row][col] != 0)
		{
			if((col+1)<9) return sudoku(a,row,col+1);
			else if((row + 1)<9) return sudoku(a,row+1,0);
			else return 1;
		}
		else
		{
			for(i=0;i<9;i++)
			{
				if(fill(a,row,col,i+1))
				{
					a[row][col] = i+1;
					if((col+1)<9)
					{
						if(sudoku(a,row,col+1)) return 1;
						else a[row][col]=0;
					}
					else if((row+1)<9)
					{
						if(sudoku(a,row+1,0)) return 1;
						else a[row][col]=0;
					}
					else return 1;
				}
			}
		}
		return 0;
	}
	else return 1;	
}

int main()
{
	int i,j;
	
	int a[9][9]= {	{0,0,7, 3,0,4, 0,9,0},
					{5,8,0, 0,0,1, 0,0,2},
					{0,0,1, 0,8,0, 0,0,6},
					
					{1,0,0, 0,4,6, 0,0,0},
					{9,7,0, 5,0,0, 0,0,0},
					{6,2,0, 0,0,3, 1,5,0},
					
					{0,0,0, 0,0,9, 4,7,0},
					{0,0,0, 0,3,5, 6,0,0},
					{0,0,9, 4,0,0, 0,0,5}};
					   
	int b[9][9]= {	{0,0,0, 0,0,0, 0,9,0},
					{1,9,0, 4,7,0, 6,0,8},
					{0,5,2, 8,1,9, 4,0,7},
					
					{2,0,0, 0,4,8, 0,0,0},
					{0,0,9, 0,0,0, 5,0,0},
					{0,0,0, 7,5,0, 0,0,9},
					
					{9,0,7, 3,6,4, 1,8,0},
					{5,0,6, 0,8,1, 0,7,4},
					{0,8,0, 0,0,0, 0,0,0}};
	if(sudoku(a,0,0))
	{
		printf("\n\nSUDOKU 1 SOLVED :-\n\n");
		printf("\n*---------------------*\n");
		for(i=1;i<10;i++)
		{
			for(j=1;j<10;j++)
			{
				printf("|%d", a[i-1][j-1]);
				if(j%3==0)
					printf("| ");
			}
			printf("\n");
			if(i%3==0)
				printf("*---------------------*\n");
		}
	}
	else
		printf("\n\n NO SOLUTION \n\n");	
 
 	if(sudoku(b,0,0))
	{
		printf("\n\nSUDOKU 2 SOLVED :-\n\n");
		printf("\n*---------------------*\n");
		for(i=1;i<10;i++)
		{
			for(j=1;j<10;j++)
			{
				printf("|%d", b[i-1][j-1]);
				if(j%3==0)
					printf("| ");
			}
			printf("\n");
			if(i%3==0)
				printf("*---------------------*\n");
		}
	}
	else
		printf("\n\n NO SOLUTION \n\n");	
 
	return 0;
}
