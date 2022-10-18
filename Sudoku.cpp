#include <bits/stdc++.h> 
using namespace std; 
#define N 9 

bool isSafe(int board[N][N],int row, int col, int num) 
    { 
     
        for (int d = 0; d < N; d++)  
        { 
            
            if (board[row][d] == num) { 
                return false; 
            } 
        } 
  
        for (int r = 0; r < N; r++)  
        { 
               
            if (board[r][col] == num)  
            { 
                return false; 
            } 
        }  
        int s = (int)sqrt(N); 
        int boxRowStart = row - row % s; 
        int boxColStart = col - col % s; 
  
        for (int r = boxRowStart; 
             r < boxRowStart + s; r++)  
        { 
            for (int d = boxColStart; 
                 d < boxColStart + s; d++)  
            { 
                if (board[r][d] == num)  
                { 
                    return false; 
                } 
            } 
        } 
  
        return true; 
    } 

bool solve(int board[N][N],int n) 
{ 
	    int row = -1; 
        int col = -1; 
        bool isEmpty = true; 
        for (int i = 0; i < n; i++)  
        { 
            for (int j = 0; j < n; j++)  
            { 
                if (board[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty) { 
                break; 
            } 
        } 
  
        if (isEmpty)  
        { 
            return true; 
        } 
        
        for (int num = 1; num <= n; num++)  
        { 
            if (isSafe(board, row, col, num))  
            { 
                board[row][col] = num; 
                if (solve(board, n))  
                { 
                    // print(board, n); 
                    return true; 
                } 
                else 
                { 
                    board[row][col] = 0; 
                } 
            } 
        } 
        return false; 
} 

void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 
 
int main() 
{ 
	int grid[N][N];
	int i;
	cout << "Enter the sudoku board in the row-wise order\n" << endl;
	
	cout << "Enter the first row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[0][i];
	}
	cout << "Enter the second row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[1][i];
	}
	cout << "Enter the third row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[2][i];
	}
	cout << "Enter the fourth row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[3][i];
	}
	cout << "Enter the fifth row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[4][i];
	}
	cout << "Enter the sixth row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[5][i];
	}
	cout << "Enter the seventh row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[6][i];
	}
	cout << "Enter the eighth row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[7][i];
	}
	cout << "Enter the ninth row" << endl;
	for(i = 0;i < N;i++)
	{
		cin >> grid[8][i];
	}
	if (solve(grid,N) == true) 
	{
		cout << "\n\nSolution for the given board:" << endl;
		printGrid(grid); 
		
	}
	else
		cout << "No solution exists"; 

	return 0; 
} 
