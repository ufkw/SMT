#pragma once
#include "pch.h"
#include <vector>

class TicTacToe
{
public:
	TicTacToe();
	const std::vector<std::vector<char>>& GetBoard() const;
	void SetPlayers(char* player1, char* player2);
	void MakeMove(int row, int col, char player);
	bool IsMoveValid(int row, int col);
	bool CheckWin(char player);
	bool IsBoardFull();
	void Play();

private:
	const int board_length;
	const int board_size;
	std::vector<std::vector<char>> board;
	void DisplayBoard();
};

