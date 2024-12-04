#include "pch.h"
#include "TicTacToe.h"
#include <stdlib.h>  
#include <iostream>
#include <vector>
using namespace std;

TicTacToe::TicTacToe() : board_length(3), board_size(9)
{
	// initialize board
	board = vector<vector<char>>(board_length, vector<char>(board_length, ' '));
}

/// <summary>
/// Public getter for interface.
/// </summary>
/// <returns>board of X and O</returns>
const std::vector<std::vector<char>>& TicTacToe::GetBoard() const
{
	return TicTacToe::board;
}

/// <summary>
/// Public setter for interface.
/// </summary>
/// <returns>adds X or O to the board</returns>
void TicTacToe::MakeMove(int row, int col, char player)
{
	if (IsMoveValid(row, col))
	{
		board[row][col] = player;
	}
	else
	{
		// error displayed in IsMoveValid()
	}
}

/// <summary>
/// 
/// </summary>
void TicTacToe::Play()
{
	int row;
	int col;
	char player1, player2, player;

	cout << "Flipping a coin to see who goes first...\n";
	SetPlayers(&player1, &player2);
	if (player1 == 'X')
	{
		player = player1;
		cout << "Player 1 is X and Player 2 is O. Player 1 goes first!\n";
	}
	else
	{
		player = player2;
		cout << "Player 2 is X and Player 1 is O. Player 2 goes first!\n";
	}


	int turn = 0;
	char last_player = player;
	while (!CheckWin(last_player) && turn < board_size)
	{
		last_player = player;
		cout << player << "'s turn.\n";
		DisplayBoard();

		do
		{
			cout << "What row? Choose 0, 1, or 2.\n";
			cin >> row;
			cout << "What column? Choose 0, 1, or 2.\n";
			cin >> col;
		} while (!IsMoveValid(row, col));

		MakeMove(row, col, player);

		player = (player == player1) ? player2 : player1; // switch players
		turn++;
	}

	DisplayBoard();
	cout << last_player << " wins!\n";
	return;
}

/// <summary>
/// Check if a move is valid. Is invalid if it is out of bounds or if it is already taken.
/// </summary>
/// <param name="row">row index. Expected 0, 1, 2</param>
/// <param name="col">col index. expected 0, 1, 2</param>
/// <param name="board">internal board used for game</param>
/// <returns>true if move is valid, false otherwise</returns>
bool TicTacToe::IsMoveValid(int row, int col)
{
	// in bounds
	if (row < 0 || col < 0 || row >= board_length || col >= board_length)
	{
		cout << row << ", " << col << " is out of bounds. Please choose another spot between 0 - 2.\n";
		return false;
	}

	// spot not already taken

	if (board[row][col] != ' ')
	{
		cout << row << ", " << col << " is taken. Please choose another spot.\n";
		return false;
	}
	return true;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool TicTacToe::IsBoardFull()
{
	for (int i = 0; i < board_length; i++)
	{
		for (int j = 0; j < board_length; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

/// <summary>
/// Check if a given player won
/// </summary>
/// <param name="player">Player we are checking if they won</param>
/// <returns>true if they won, false otherwise</returns>
bool TicTacToe::CheckWin(char player)
{
	// Check rows
	int match = 0;
	for (int i = 0; i < board_length; i++)
	{
		match = 0;
		for (int j = 0; j < board_length; j++)
		{
			if (board[i][j] == player)
			{
				match++;
			}
		}
		if (match == board_length)
		{
			return true;
		}
	}

	// Check col
	match = 0;
	for (int i = 0; i < board_length; i++)
	{
		match = 0;
		for (int j = 0; j < board_length; j++)
		{
			if (board[j][i] == player)
			{
				match++;
			}
		}
		if (match == board_length)
		{
			return true;
		}
	}

	// check diagonals
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		return true;
	}

	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
	{
		return true;
	}

	return false;
}

/// <summary>
/// Flip a coin for which player goes first.
/// </summary>
/// <param name="player1">Will be set to X or O</param>
/// <param name="player2">Will be set to X or O</param>
void TicTacToe::SetPlayers(char* player1, char* player2)
{
	// flip a coin
	if (rand() % 2 == 0)
	{
		*player1 = 'X';
		*player2 = 'O';
	}
	else
	{
		*player1 = 'O';
		*player2 = 'X';
	}
}

/// <summary>
/// Display board for testing purposes
/// </summary>
void TicTacToe::DisplayBoard()
{
	for (int i = 0; i < board_length; i++)
	{
		for (int j = 0; j < board_length; j++)
		{
			std::cout << board[i][j];
			if (j < board_length - 1) {
				std::cout << " | ";
			}
		}
		std::cout << std::endl;
		if (i < board_length - 1)
		{
			std::cout << std::string(board_length * board_length, '-') << std::endl;
		}
	}
}


