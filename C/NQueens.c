#include <stdio.h>
#include <stdbool.h>

int count = 1;

void printBoard(int board[][10], int n)
{
    printf("Solution %d:\n", count++);
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
             if(board[row][col] == 1)
                printf("\tQ");
            else
                printf("\t-");
        }
        printf("\n");
    }
    
}

bool isSafe(int board[][10], int row, int col, int n)
{
    //column checking
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }
  
    int diag_x = row; //diagonal x coordinate
    int diag_y = col; //diagonal y coordinate
    
    while(diag_x >= 0 && diag_y >= 0)
    {
        if(board[diag_x][diag_y] == 1)
            return false;
        diag_x--;
        diag_y--;
    }
    
    // right diagonal checking
    diag_x = row; //diagonal x coordinate
    diag_y = col; //diagonal y coordinate
    
    while(diag_x >= 0 && diag_y < n)
    {
        if(board[diag_x][diag_y] == 1)
            return false;
        diag_x--;
        diag_y++;
    }
    
    return true; // position safe!
}


bool solveNQueens(int board[][10], int row, int n)
{
    if (row == n)
    {
        
        printBoard(board, n);
    }
    
    //recursive case
    for(int j = 0; j < n; j++)
    {
        //check if i,j position is safe for queen placement
        if(isSafe(board, row, j, n))
        {
            board[row][j] = 1;
            
            bool isNextQueenPossible = solveNQueens(board, row + 1, n);
            if(isNextQueenPossible)
                return true;
                
        board[row][j] = 0;        
        }
    }
    
    //if queen was not placed even after trying all positions
    return false;
}


int main()
{
    int n;
    printf("Enter Number of queens: ");
    scanf("%d", &n);
    int board[10][10] = {0};
    solveNQueens(board, 0, n);
}
