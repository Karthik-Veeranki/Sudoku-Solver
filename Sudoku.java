// Importing necessary libraries
import java.io.*;
import java.util.*;
import java.lang.*;


class Main
{
    //int n = 9;
	public static boolean isSafe(int board[][], int row, int column, int num)
	{
		int j;
	    int n = 9;	
		for(j = 0;j < board.length;j++)
		{
			if(board[row][j] == num)
				return false;
		}
		
		int i;
		for(i = 0;i < board.length;i++)
		{
			if(board[i][column] == num)
				return false;
		}
		
		int size = (int)Math.sqrt(board.length);
		
		int boxRowStart = row - row%size;
		int boxColumnStart = column - column%size;
		
		for(i = boxRowStart;i < boxRowStart + size;i++)
		{
			for(j = boxColumnStart;j < boxColumnStart + size;j++)
			{
				if(board[i][j] == num)
					return false;
			}
		}
		return true;
	}
	
	
	public static boolean solve(int board[][],int n)
	{
	    //int n = 9;
		int row = -1;
		int col = -1;
		
		boolean isEmpty = true;
		int i,j;
		
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(board[i][j] == 0)
				{
					row = i;
					col = j;
					isEmpty = false;
					break;
				}
			}
			
			if(isEmpty == false)
				break;
		}
		
		if(isEmpty == true)
			return true;
		
		for(int num = 1;num <= n;num++)
		{
			if(isSafe(board,row,col,num) == true)
			{
				board[row][col] = num;
				if(solve(board,n))
					return true;
				else
					board[row][col] = 0;
			}
		}
		
		return false;
	}
	
	public static void output(int board[][],int n)
	{
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public static void main(String ar[])throws IOException
	{
		Scanner sc = new Scanner(System.in);
		//int n;
		//n = sc.nextInt();
		int n = 9;
		int board[][] = new int[n][n];
		int i,j;
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				board[i][j] = sc.nextInt();
			}
		}
		
		if(solve(board,n) == true)
		{
			System.out.println("Solution for the given board :");
			output(board,n);
		}
		else
			System.out.println("No solution exists");
	}
}