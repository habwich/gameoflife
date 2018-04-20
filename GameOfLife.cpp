// GameOfLife.cpp : Defines the entry point for the console application.
//Written By: Evan Habrukowich
//Date Written: 5th March 2012
//Project 1: John Conway's "Game of Life"

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

const int COLS = 25;
const int ROWS = 10;

void defineLife(int row, int column, char input[ROWS][COLS], char output[ROWS][COLS]);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	int random;
	char board1[ROWS][COLS];
	char board2[ROWS][COLS];
	for(int row = 0; row < ROWS; row++)
	{
		for(int col = 0; col < COLS; col++)
		{
			random = rand() % 2;
			if(random == 0)
				board1[row][col] = '*';
			else
				board1[row][col] = ' ';
			cout << board1[row][col];
		}
		cout << endl;
	}
	
	while(1)
	{
		Sleep(1800);
		system("cls");
		for(int row = 0; row < ROWS; row++)
		{
			for(int col = 0; col < COLS; col++)
			{
				defineLife(row, col, board1, board2);
				cout << board2[row][col];
			}
			cout << endl;
			
		}
		for(int row = 0; row < ROWS; row++)
		{
			for(int col = 0; col < COLS; col++)
			{
				board1[row][col] = board2[row][col];
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}

void defineLife(int row, int column, char input[ROWS][COLS], char output[ROWS][COLS])
{
	
	int neighbor = 0;

	//Indicate the cell is within the first row.
	if(row == 0 && column < COLS)
	{
		//Is the cell within the upper-left hand corner.
		if(row == 0 && column == 0)
		{
			if(input[row + 1][column] == '*')
				//Is neighbor below occupied.ok
				neighbor++;
			if(input[row][column + 1] == '*')
				//Is neighbor to the right occupied.ok
				neighbor++;
			if(input[row + 1][column + 1] == '*')
				//Is neighbor within the bottom right occupied.
				neighbor++;
		}
		//Is the cell within the upper-right hand corner.
		if(row == 0 && column == (COLS - 1))
		{
			if(input[row + 1][column] == '*')
				//Is neighbor below occupied.
				neighbor++;
			if(input[row][column - 1] == '*')
				//Is neighbor to the left occupied.
				neighbor++;
			if(input[row + 1][column - 1] == '*')
				//Is neighbor within the bottom left occupied.
				neighbor++;
		}
		//Otherwise the cell is in the first row.
		if(row == 0 && column > 0 && column < (COLS - 1))
		{
			if(input[row + 1][column] == '*')
				//Is neighbor below occupied.
				neighbor++;
			if(input[row][column - 1] == '*')
				//Is neighbor to the left occupied.
				neighbor++;
			if(input[row][column + 1] == '*')
				//Is neighbor to the right occupied.
				neighbor++;
			if(input[row + 1][column - 1] == '*')
				//Is neighbor within the bottom left occupied.
				neighbor++;
			if(input[row + 1][column + 1] == '*')
				//Is neighbor within the bottom right occupied.
				neighbor++;
		}
 	}
	//Indicate the cell is within the bottom row.
	else if(row == (ROWS - 1) && column < COLS)
	{
		//Is the cell within the lower-left hand corner.
		if(row == (ROWS - 1) && column == 0)
		{
			if(input[row - 1][column] == '*')
				//Is neighbor to the top occupied.
				neighbor++;
			if(input[row][column + 1] == '*')
				//Is neighbor to the right occupied.
				neighbor++;
			if(input[row - 1][column + 1] == '*')
				//Is neighbor within the top right occupied.
				neighbor++;
		}
		//Is the cell within the lower-right hand corner.
		if(row == (ROWS - 1) && column == (COLS - 1))
		{
			if(input[row][column - 1] == '*')
				//Is neighbor to the left occupied.
				neighbor++;
			if(input[row - 1][column] == '*')
				//Is neighbor to the top occupied.
				neighbor++;
			if(input[row - 1][column - 1] == '*')
				//Is neighbor within the top left occupied.
				neighbor++;
		}
		//Otherwise the cell is in the bottom row.
		if(row == (ROWS - 1) && column > 0 && column < (COLS - 1))
		{
			if(input[row -1][column] == '*')
				//Is neighbor to the top occupied.
				neighbor++;
			if(input[row][column - 1] == '*')
				//Is neighbor to the left occupied.
				neighbor++;
			if(input[row][column + 1] == '*')
				//Is neighbor to the right occupied.
				neighbor++;
			if(input[row - 1][column - 1] == '*')
				//Is neighbor within the top left occupied.
				neighbor++;
			if(input[row - 1][column + 1] == '*')
				//Is neighbor within the top right occupied.
				neighbor++;
		}
	}
	//Indicate the cell is within the first column
	else if(row > 0 && row < (ROWS - 1) && column == 0)
	{
		if(input[row - 1][column] == '*')
				//Is neighbor to the top occupied.
				neighbor++;
		if(input[row + 1][column] == '*')
				//Is neighbor below occupied.
				neighbor++;
		if(input[row - 1][column + 1] == '*')
				//Is neighbor within the top right occupied.
				neighbor++;
		if(input[row][column + 1] == '*')
				//Is neighbor to the right occupied.
				neighbor++;
		if(input[row + 1][column + 1] == '*')
				//Is neighbor within the bottom right occupied.
				neighbor++;
	}
	//Indicate the cell is within the last column
	else if(row > 0 && row < (ROWS - 1) && column == (COLS - 1))
	{
		if(input[row - 1][column] == '*')
				//Is neighbor to the top occupied.
				neighbor++;
		if(input[row + 1][column] == '*')
				//Is neighbor below occupied.
				neighbor++;
		if(input[row - 1][column - 1] == '*')
				//Is neighbor within the top left occupied.
				neighbor++;
		if(input[row][column - 1] == '*')
				//Is neighbor to the left occupied.
				neighbor++;
		if(input[row + 1][column - 1] == '*')
				//Is neighbor within the bottom left occupied.
				neighbor++;
	}
	//Otherwise the cell is not against the edge of the matrix.
	else
	{
		if(input[row - 1][column] == '*')
				//Is neighbor to the top occupied.
				neighbor++;
		if(input[row + 1][column] == '*')
				//Is neighbor below occupied.
				neighbor++;
		if(input[row][column - 1] == '*')
				//Is neighbor to the left occupied.
				neighbor++;
		if(input[row][column + 1] == '*')
				//Is neighbor to the right occupied.
				neighbor++;
		if(input[row - 1][column - 1] == '*')
				//Is neighbor within the top left occupied.
				neighbor++;
		if(input[row - 1][column + 1] == '*')
				//Is neighbor within the top right occupied.
				neighbor++;
		if(input[row + 1][column - 1] == '*')
				//Is neighbor within the bottom left occupied.
				neighbor++;
		if(input[row + 1][column + 1] == '*')
				//Is neighbor within the bottom right occupied.
				neighbor++;
	}
	//Rules of the Game of Life.
	//If the cell is alive.
	if(input[row][column] == '*')
	{
		if(neighbor < 2)
		{
			output[row][column] = ' ';	
		}
		else if(neighbor >= 2 && neighbor <= 3)
		{
			output[row][column] = '*';
		}
		else if(neighbor >= 3)
		{
			output[row][column] = ' ';
		}
	}
	//If the cell is dead.
	if(input[row][column] == ' ')
	{
		if(neighbor == 3)
		{
			output[row][column] = '*';
		}
		else
		{
			output[row][column] = ' ';
		}
	}
}
