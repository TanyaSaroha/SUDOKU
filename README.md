# SUDOKU
Sudoku is a combinatorial, number placing puzzle.  
Following C program uses a recursice backtracking algorithm to solve a 9X9 sudoku puzzle.  
The function "int sudoku(int a[][9], int row, int col)" is recursively called. 
This function will make a call to another fucntion "int fill(int a[][9], int row, int col, int num)" which decides if the parameter "num" can be filled in a[row][column].  
  
  
This decision is based on three conditions:-
- Number is not present in the same row 
- Number is not present in the same column
- Number is not present in the 3X3 sub-grid   
  
int r = (row/3) * 3;  
int c = (col/3) * 3;  
int i;  
for(i=0;i<9;i++)  
{  
if(a[row][i] == num) return 0; // condition 1  
if(a[i][col] == num) return 0; // condition 2  
if(a[r + (i%3)][c + (i/3)] == num) return 0; // condition 3  
}  
  
 Changes in the following code can be made depending on type and size of sudoku.  
 Happy solving! :)
